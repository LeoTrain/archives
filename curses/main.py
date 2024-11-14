import curses

from budget_manager import budgetManager
from configurate_expenses import configurate_expenses_screen
from new_expenses import new_expense_screen
from show_expenses import show_expenses_screen
from statistics_screen import statistics_screen 


def main(stdscr):
    manager = budgetManager()
    # Effacer l'écran
    stdscr.clear()
    stdscr.border(0)

    height, width = stdscr.getmaxyx()
    center_y = height // 2
    center_x = width // 2

    # Titre du Programme
    title = r"""
______________________.____ 
\_   _____/\__    ___/|    |
 |    __)    |    |   |    |
 |     \     |    |   |    |___
 \___  /     |____|   |_______ \
     \/                       \/
            """

    # Calcul du début en y pour centrer verticalement et x
    start_y = center_y // 2 - len(title.splitlines()) // 2
    start_x = center_x - len(title.splitlines()[1]) // 2

    # Initialiser les couleurs
    curses.start_color()
    curses.init_pair(
        1, curses.COLOR_YELLOW, curses.COLOR_BLACK
    )  # Texte rouge sur fond noir
    curses.init_pair(
        2, curses.COLOR_WHITE, curses.COLOR_BLACK
    )  # Texte blanc sur fond noir

    # Affichage du menu
    menu_options = [
        "Nouvelle depense",
        "Afficher les depenses",
        "Gerer les depenses",
        "Quitter",
    ]
    current_option = 0  # Option actuellement sélectionnée

    while True:
        # Effacer l'écran à chaque tour de boucle
        stdscr.clear()

        # Réafficher le titre
        for i, line in enumerate(title.splitlines()):
            stdscr.addstr(start_y + i, start_x, line)

        # Afficher les options du menu
        for i in range(len(menu_options)):
            option_len = len(menu_options[i])
            x = center_x - option_len // 2
            y = center_y - len(menu_options) // 2 + i

            # Vérifier si cette option est sélectionnée
            if i == current_option:
                stdscr.attron(curses.color_pair(1))  # Texte en rouge
            else:
                stdscr.attron(curses.color_pair(2))  # Texte en blanc

            stdscr.addstr(y, x, menu_options[i])

            # Réinitialiser les attributs de couleur
            stdscr.attroff(curses.color_pair(1))
            stdscr.attroff(curses.color_pair(2))

        # Rafraîchir l'écran pour afficher les changements
        stdscr.refresh()

        # Attendre une entrée de l'utilisateur
        key = stdscr.getch()

        # Navigation avec 'j' et 'k'
        if key == ord("j") and current_option < len(menu_options) - 1:
            current_option += 1
        elif key == ord("k") and current_option > 0:
            current_option -= 1
        elif key == ord("\n"):
            if current_option == 0:
                new_expense_screen(stdscr)
            elif current_option == 1:
                show_expenses_screen(stdscr, manager)
            elif current_option == 2:
                statistics_screen(stdscr, manager)
            elif current_option == len(menu_options) - 1:  # Quitter
                break
            else:
                stdscr.addstr(
                    0, 0, f"Vous avez sélectionné: {menu_options[current_option]}"
                )
                stdscr.refresh()
                stdscr.getch()


if __name__ == "__main__":
    # Démarrer l'application curses
    curses.wrapper(main)
