import curses

def question_popup(stdscr, question: str) -> str:
    height, width = 5, 40
    start_y, start_x = (stdscr.getmaxyx()[0] - height) // 2, (stdscr.getmaxyx()[1] - width) // 2

    popup = curses.newwin(height, width, start_y, start_x)
    popup.box()

    popup.addstr(1, (width // 2) - len(question) // 2, question, curses.A_BOLD)

    curses.echo()
    popup.refresh()
    answer = popup.getstr(3, 2, 15).decode('utf-8')
    curses.noecho()

    popup.refresh()

    popup.clear()
    popup.refresh()

    return answer.strip()

def yes_no_popup(stdscr, action: str) -> bool:
    height, width = 6, 40
    start_y, start_x = (stdscr.getmaxyx()[0] - height) // 2, (stdscr.getmaxyx()[1] - width) // 2

    popup = curses.newwin(height, width, start_y, start_x)
    popup.box()

    curses.start_color()
    curses.init_pair(1, curses.COLOR_YELLOW, curses.COLOR_BLACK)
    curses.init_pair(2, curses.COLOR_WHITE, curses.COLOR_BLACK)

    yes_str = "Oui"
    no_str = "Non"
    yes_x = (width // 2) - len(yes_str) // 2 - 10
    no_x = (width // 2) - len(no_str) // 2 + 10
    selected_option = "yes"

    while True:
        popup.clear()
        popup.box()

        popup.addstr(1, (width // 2) - len("Est-tu sur de") // 2, "Est-tu sur de", curses.A_BOLD)
        popup.addstr(2, (width // 2) - len(f"continuer a {action} ?") // 2, f"continuer a {action} ?", curses.A_BOLD)

        if selected_option == "yes":
            popup.addstr(4, yes_x, yes_str, curses.color_pair(1))
            popup.addstr(4, no_x, no_str, curses.color_pair(2))
        else:
            popup.addstr(4, yes_x, yes_str, curses.color_pair(2))
            popup.addstr(4, no_x, no_str, curses.color_pair(1))

        popup.refresh()

        key = popup.getch()

        if key == ord('h') and selected_option == "no":
            selected_option = "yes"
        elif key == ord('l') and selected_option == "yes":
            selected_option = "no"
        elif key == curses.KEY_ENTER or key == 10:
            if selected_option == "yes":
                return True
            elif selected_option == "no":
                return False
