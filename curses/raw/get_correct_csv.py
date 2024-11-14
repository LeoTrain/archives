import csv
from datetime import datetime

def categorize(description):
    if "Online Banking" in description:
        return "Online Banking"
    elif "POS" in description:
        return "Point of Sale"
    elif "ATM" in description:
        return "ATM Withdrawal"
    elif "ePAYMENT" in description:
        return "ePayment"
    else:
        return "Other"

def extract_name(description):
    if "Empfänger:" in description:
        return description.split("Empfänger:")[1].split("Zahlungsreferenz:")[0].strip()
    elif "Verwendungszweck:" in description:
        return description.split("Verwendungszweck:")[1].split("Zahlungsreferenz:")[0].strip()
    elif "Auftraggeber:" in description:
        return description.split("Auftraggeber:")[1].split("IBAN")[0].strip()
    else:
        return description[:50]  # Première partie du texte descriptif s'il n'y a pas de mots-clés

def transform_data(input_file, output_files):
    with open(input_file, mode='r', newline='', encoding='utf-8') as elba_file:
        reader = csv.reader(elba_file, delimiter=';')
        transformed_data = []
        transformed_expenses = []

        for row in reader:
            try:
                date = row[0].strip()
                date = datetime.strptime(date, '%d.%m.%Y')
                date = date.strftime("%d-%m-%Y")
            except ValueError:
                # Gère les erreurs de format de date ici
                if row[0].strip().startswith('\ufeff'):
                    # Enlève '\ufeff' du début de row[0]
                    row[0] = row[0].lstrip('\ufeff').strip()
                    try:
                        date = row[0]
                        date = datetime.strptime(date, '%d.%m.%Y')
                        date = date.strftime("%d-%m-%Y")
                    except ValueError:
                        print(f"Format de date invalide après suppression du BOM : {row[0]}")
                        date = None  # Ou une autre valeur par défaut si nécessaire
                else:
                    print(f"Format de date invalide : {row[0]}")
                    date = None
            description = row[1].strip('"')
            amount = row[3].strip().replace('.', '').replace(',', '.')
            name = extract_name(description)
            category = categorize(description)
            
            if amount[0] == "-":
                amount = amount[1:]
                transformed_data.append([date, name, amount, category])
            else:
                transformed_expenses.append([date, name, amount, category])

        with open(output_files[0], mode='w', newline='', encoding='utf-8') as output_csv:
            writer = csv.writer(output_csv)
            writer.writerow(['Date', 'Name', 'Amount', 'Category'])
            writer.writerows(transformed_data)

        with open(output_files[1], mode='w', newline='', encoding='utf-8') as incomes_csv:
            writer = csv.writer(incomes_csv)
            writer.writerow(['Date', 'Name', 'Amount', 'Category'])
            writer.writerows(transformed_expenses)

transform_data('elba.csv', ['transformed_data.csv', 'transformed_incomes.csv'])

