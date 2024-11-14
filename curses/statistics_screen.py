import curses

def draw_statistics(stdscr, global_stats, monthly_stats):
    screen_height, screen_width = stdscr.getmaxyx()
    title_global = "Statistiques Globales"
    title_monthly = "Statistiques Mensuelles"
    margin = 2

    # Clear the screen and add a border
    stdscr.clear()
    stdscr.border(0)
    
    # Title Globales
    stdscr.addstr(1, margin, title_global, curses.A_BOLD)
    
    # Title Mensuelles
    stdscr.addstr(1, (screen_width // 2) + margin, title_monthly, curses.A_BOLD)

    # Display Global Statistics (Left Side)
    y = 3
    for key, value in global_stats.items():
        text = f"{key}: {value}"
        stdscr.addstr(y, margin, text)
        y += 1

    # Display Monthly Statistics (Right Side)
    y = 3
    for key, value in monthly_stats.items():
        text = f"{key}: {value}"
        stdscr.addstr(y, (screen_width // 2) + margin, text)
        y += 1

    # Add instructions for navigation
    instructions = "Appuyez sur 'q' pour quitter"
    stdscr.addstr(screen_height - 2, (screen_width // 2) - len(instructions) // 2, instructions)

    stdscr.refresh()

    # Wait for user input to close the statistics screen
    while True:
        key = stdscr.getch()
        if key == ord('q'):
            break

def statistics_screen(stdscr, manager):
    # Collect global statistics
    total_expenses_global = manager.get_expense_total()
    average_expenses_global = manager.get_expense_average()
    most_freq_cat_global = manager.get_most_frequent_category()
    total_number_of_transactions = manager.get_total_number_of_transactions()

    global_stats = {
        "Total des dépenses": f"{total_expenses_global:.2f} €",
        "Dépense moyenne": f"{average_expenses_global:.2f} €",
        "Catégorie la plus dépensée": most_freq_cat_global,
        "Dépense totale par catégorie": "None",
        "Nombre total de transactions": f"{total_number_of_transactions}",
        "Dépense max": f"None €",
        "Dépense min": f"None €",
        "Catégorie avec dépense moyenne la plus élevée": "None",
        "Date avec la dépense la plus élevée": "None"
    }

    # Collect monthly statistics
    total_expenses_monthly = manager.get_expense_total(this_month=True)
    average_expenses_monthly = manager.get_expense_average(this_month=True)
    most_freq_cat_monthly = manager.get_most_frequent_category(this_month=True)
    total_number_of_transactions_monthly = manager.get_total_number_of_transactions(this_month=True)

    monthly_stats = {
        "Total des dépenses": f"{total_expenses_monthly:.2f} €",
        "Dépense moyenne": f"{average_expenses_monthly:.2f} €",
        "Catégorie la plus dépensée": most_freq_cat_monthly,
        "Dépense totale par catégorie": "None",
        "Nombre total de transactions": f"{total_number_of_transactions_monthly}",
        "Dépense max": f"None €",
        "Dépense min": f"None €",
        "Catégorie avec dépense moyenne la plus élevée": "None",
        "Date avec la dépense la plus élevée": "None"
    }

    # Display the statistics
    draw_statistics(stdscr, global_stats, monthly_stats)

