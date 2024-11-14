import curses
from datetime import datetime

def new_date_popup(stdscr):
    height, width = 7, 40
    start_y, start_x = (stdscr.getmaxyx()[0] - height) // 2, (stdscr.getmaxyx()[1] - width) // 2

    popup = curses.newwin(height, width, start_y, start_x)
    popup.box()

    popup.addstr(1, (width // 2) - len("Nouvelle Date") // 2, "Nouvelle Date", curses.A_BOLD)
    popup.addstr(3, 2, "Entrez la nouvelle date (dd-mm-yyy):")

    curses.echo()
    popup.refresh()
    date_str = popup.getstr(4, 2, 15).decode('utf-8')
    curses.noecho()

    popup.addstr(5, 2, f"Date valide: {date_str}", curses.A_BOLD)

    popup.refresh()

    popup.getch()
    popup.clear()
    popup.refresh()

    return date_str


def configurate_expenses_screen(stdscr, manager):
    curses.start_color()
    curses.init_pair(1, curses.COLOR_YELLOW, curses.COLOR_BLACK)
    curses.init_pair(2, curses.COLOR_WHITE, curses.COLOR_BLACK)

    expenses = manager.get_expenses()
    modes = ["DELETE", "DATE", "QUIT"]
    col_widths = [10, 20, 15, 20]
    margin = 2

    current_option = 0        
    current_mode = 0

    screen_height, screen_width = stdscr.getmaxyx()
    fake_column_text = f"{expenses[0][0]:<10}{expenses[0][1]:<20}{expenses[0][2]:<15}{expenses[0][3]:<20}"
    center_x = screen_width // 2 - len(fake_column_text) // 2

    movement_guide = "up: k | down: j | left: h | right: l"

    while True:
        stdscr.clear()
        
        stdscr.addstr(0,0, f"You are in {modes[current_mode]} mode.")
        center_y = screen_height // 2 - len(expenses) // 2

        for i, line in enumerate(expenses):
            if len(line) != len(col_widths):
                stdscr.addstr(center_y, center_x, "Erreur: Ligne CSV incorrecte.", curses.color_pair(1))
                continue
            if i == current_option:
                stdscr.attron(curses.color_pair(1))
            else:
                stdscr.attron(curses.color_pair(2))

            for j, width in enumerate(col_widths):
                column_text = f"{line[j]:<{width}}"
                stdscr.addstr(center_y, center_x + sum(col_widths[:j]) + margin * j, column_text)

            center_y += 1

            stdscr.attroff(curses.color_pair(1))
            stdscr.attroff(curses.color_pair(2))

        # Extern options
        mode_x = 0
        mode_y = screen_height - 1
        
        for i, mode in enumerate(modes):
            if current_mode == i:
                text = f"[X]{mode}"
            # ADD HERE DATE
            else:
                text = f"[ ]{mode}"
            stdscr.addstr(mode_y, mode_x, text)
            mode_x += len(text) + margin

        mov_guide_x = screen_width - len(movement_guide) - 1
        mov_guide_y = screen_height - 1
        stdscr.addstr(mov_guide_y, mov_guide_x, movement_guide)

        stdscr.refresh()

        key = stdscr.getch()

        if key == ord('j') and current_option < len(expenses) - 1:
            current_option += 1
        elif key == ord('k') and current_option > 0:
            current_option -= 1
        elif key == ord('h') and current_mode > 0:
            current_mode -= 1
        elif key == ord('l') and current_mode < len(modes) - 1:
            current_mode += 1
        elif key == ord('\n') and len(expenses) > 0 and current_mode == 0:
            date, name, amount, _ = expenses[current_option]
            manager.delete_expense(date, name, str(amount))
            expenses = manager.get_expenses()
            current_option = min(current_option, len(expenses) - 1)
        elif key == ord('\n') and len(expenses) > 0 and current_mode == 1:
            date, name, amount, _ = expenses[current_option]
            new_date = new_date_popup(stdscr)
            manager.modify_date(date, name, amount, new_date)
            expenses = manager.get_expenses()
        elif key == ord('\n') and current_mode == len(modes) - 1:
            break


