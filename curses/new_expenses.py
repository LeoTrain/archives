import curses
from budget_manager import budgetManager
from datetime import datetime
from popups import question_popup

def add_expense_with_manager(name: str, amount: str) -> None:
    manager = budgetManager()

    date = datetime.now().strftime("%d-%m-%Y")
    if "," in amount:
        left, right = amount.split(",")
        correct_amount = f"{left}.{right}"
    elif "." in amount:
        left, right = amount.split(".")
        correct_amount = f"{left}.{right}"
    else:
        correct_amount = amount
    
    manager.import_expense(date, name, correct_amount)

def draw_title(stdscr):
    title = r"""
 _   _                       _ _            _   __                           
| \ | | ___  _   ___   _____| | | ___    __| | /_/ _ __   ___ _ __  ___  ___ 
|  \| |/ _ \| | | \ \ / / _ \ | |/ _ \  / _` |/ _ \ '_ \ / _ \ '_ \/ __|/ _ \
| |\  | (_) | |_| |\ V /  __/ | |  __/ | (_| |  __/ |_) |  __/ | | \__ \  __/
|_| \_|\___/ \__,_| \_/ \___|_|_|\___|  \__,_|\___| .__/ \___|_| |_|___/\___|
                                                  |_|
            """
    screen_height, screen_width = stdscr.getmaxyx()
    lines = title.split('\n')
    max_line_length = max(len(line) for line in lines)
    
    start_y = screen_height // 8
    start_x = (screen_width - max_line_length) // 2
    
    for i, line in enumerate(lines):
        stdscr.addstr(start_y + i, start_x, line, curses.A_BOLD)


def new_expense_screen(stdscr):
    height, width = stdscr.getmaxyx()
    center_y = height // 2
    center_x = width // 2

    stdscr.clear()
    draw_title(stdscr)
    stdscr.refresh()

    expense_name = question_popup(stdscr, "Entrez le nom de la depense:")
    expense_amount = question_popup(stdscr, "Entrez le montant de la depense:")

    if expense_name and expense_amount:
        add_expense_with_manager(expense_name, expense_amount)
        stdscr.addstr(center_y + 5, center_x - len("Dépense enregistrée!") // 2, "Dépense enregistrée!", curses.A_BOLD)
    else:
        stdscr.addstr(center_y + 5, center_x - len("Erreur lors de l'enregistrement!") // 2, "Erreur lors de l'enregistrement!", curses.A_BOLD)

    stdscr.refresh()
    stdscr.getch()


