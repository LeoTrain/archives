import curses
from popups import yes_no_popup, question_popup

def navigate_expenses(stdscr, data, manager):
    curses.curs_set(0)  # Hide cursor
    current_index = 0
    current_page = 0
    screen_height, screen_width = stdscr.getmaxyx()
    items_per_page = (screen_height - 3)
    total_pages = (len(data) + items_per_page - 1) // items_per_page

    modes = ["NORMAL", "DELETE", "DATE", "QUIT"]
    current_mode = 0

    while True:
        stdscr.clear()
        stdscr.border(0)

        # Calculate the slice of data to display for the current page
        start_index = current_page * items_per_page
        end_index = min(start_index + items_per_page * 2, len(data))
        
        # Calculate the split index for two columns
        split_index = min(start_index + items_per_page, end_index)
        
        # Draw the data for the left and right columns
        draw_expense_list(stdscr, data[start_index:split_index], highlight_index=current_index - start_index)
        draw_expense_list(stdscr, data[split_index:end_index], highlight_index=current_index - split_index, is_right=True)
        draw_current_page_index(stdscr, current_page, total_pages) 
        draw_modes(stdscr, modes, current_mode)
        stdscr.refresh()
        
        key = stdscr.getch()

        if key == ord('j') and current_index < len(data) - 1 and modes[current_mode] == modes[0]:
            current_index += 1
            if current_index >= (current_page + 1) * items_per_page:
                current_page += 1
        elif key == ord('k') and current_index > 0 and modes[current_mode] == modes[0]:
            current_index -= 1
            if current_index < current_page * items_per_page:
                current_page -= 1
        elif key == ord('n') and current_page < total_pages - 1 and modes[current_mode] == modes[0]:
            current_page += 1
            current_index = current_page * items_per_page
        elif key == ord('p') and current_page > 0 and modes[current_mode] == modes[0]:
            current_page -= 1
            current_index = current_page * items_per_page
        elif key == ord('h') and current_mode > 0:
            current_mode -= 1
        elif key == ord('l') and current_mode < len(modes) - 1:
            current_mode += 1
        elif key == ord('\n'):
            if modes[current_mode] == "QUIT":
                if yes_no_popup(stdscr, "quitter"):
                    break
            elif modes[current_mode] == "DELETE":
                if yes_no_popup(stdscr, "eliminer"):
                    manager.delete_expense(data[current_index][0], data[current_index][1], data[current_index][2])
                    data = manager.get_expenses()
                    current_index -= 1
            elif modes[current_mode] == "DATE":
                if yes_no_popup(stdscr, "changer la date"):
                    new_date = question_popup(stdscr, "Entrez la nouvelle date:")
                    date, name, amount, _ = data[current_index]
                    manager.modify_date(date, name, amount, new_date)
                    data = manager.get_expenses()

def draw_modes(stdscr, modes, current_mode):
    height, width = stdscr.getmaxyx()
    final_str = ""
    for mode in modes:
        final_str += f"[ ]{mode}"
        if not mode == modes[-1]:
            final_str += "  |"
    mode_x = width // 2 - len(final_str) // 2
    mode_y = height - 2
    
    for i, mode in enumerate(modes):
        if mode == modes[current_mode]:
            text = f"[X]{mode}"
        else:
            text = f"[ ]{mode}"
        stdscr.addstr(mode_y, mode_x, text)
        mode_x += len(text) + 2

def draw_current_page_index(stdscr, current_page, total_pages):
    screen_height, screen_width = stdscr.getmaxyx()
    
    # Format the page index string
    page_index_str = f"{current_page + 1}/{total_pages}"  # Assuming current_page is 0-based
    
    # Calculate the position for the page index string
    x_position = screen_width - len(page_index_str) - 1
    y_position = screen_height - 2
    
    # Add the page index string to the screen
    stdscr.attron(curses.color_pair(1))
    stdscr.addstr(y_position, x_position, page_index_str)
    stdscr.attroff(curses.color_pair(1))

def draw_expense_list(stdscr, data, highlight_index=None, is_right=False):
    screen_height, screen_width = stdscr.getmaxyx()
    margin = 2

    page_width = screen_width // 2 - margin * 2
    date_width = 10
    amount_width = 8
    name_width = (page_width - date_width - amount_width) // 2
    category_width = page_width - date_width - amount_width - name_width

    col_widths = [
        date_width,
        name_width,
        amount_width,
        category_width,
    ]

    if is_right:
        start_x = screen_width // 2 + margin
    else:
        start_x = screen_width // 4 - sum(col_widths) // 2

    current_y = 1

    # Draw the vertical line separating the two sections
    if not is_right:
        vertical_line_x = screen_width // 2
        for y in range(1, screen_height - margin):
            stdscr.addch(y, vertical_line_x, ord('|'))

    for i, line in enumerate(data):
        if i == highlight_index:
            stdscr.attron(curses.color_pair(1))
        else:
            stdscr.attron(curses.color_pair(2))

        # Ensure the Y position is within screen limits
        if current_y >= screen_height - margin:
            break

        for j, width in enumerate(col_widths):
            column_text = line[j]

            # If the text is too long, truncate it and add "..."
            if len(column_text) > width:
                max_display_length = width - 3
                if start_x + sum(col_widths[:j]) + margin * j + max_display_length > screen_width:
                    max_display_length = screen_width - (start_x + sum(col_widths[:j]) + margin * j)
                column_text = column_text[:max_display_length] + "..."

            # Calculate the position to place the string
            x_position = start_x + sum(col_widths[:j]) + margin * j

            # Ensure the X position is within screen limits
            if x_position < screen_width:
                stdscr.addstr(current_y, x_position, column_text)
            else:
                break

        stdscr.attroff(curses.color_pair(1))
        stdscr.attroff(curses.color_pair(2))

        current_y += 1

    stdscr.refresh()

def show_expenses_screen(stdscr, manager):
    curses.start_color()
    curses.init_pair(1, curses.COLOR_YELLOW, curses.COLOR_BLACK)
    curses.init_pair(2, curses.COLOR_WHITE, curses.COLOR_BLACK)
    data = manager.get_expenses()

    stdscr.clear()
    navigate_expenses(stdscr, data, manager)

    stdscr.refresh()
