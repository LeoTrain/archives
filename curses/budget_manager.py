import csv
import os
from collections import Counter
from datetime import datetime
from typing import List

from expenses_categories import categories


class budgetManager():
    def __init__(self, ) -> None:
        self.file_path = "/Users/ftl/lab/curses/transformed_data.csv"
        self.initialise_file()
        self.categories = categories 
        self.headers = ["Date", "Name", "Amount", "Category"]

    def get_category(self, name: str) -> str | None:
        for category_name in self.categories:
            for hit_name in self.categories[category_name]:
                if hit_name == name.lower():
                    return category_name
        return None

    def initialise_file(self) -> None:
        if not os.path.exists(self.file_path):
            with open(self.file_path, mode='w', newline='') as file:
                writer = csv.writer(file)
                writer.writerow(self.headers)

    def import_expense(self, date: str, name: str, amount: str) -> None:
        formatted_amount = f"{float(amount):.2f}"
        data = [date, name, formatted_amount]
        category = self.get_category(name)
        if category is not None:
            data.append(category)
        else:
            data.append("No category")

        with open(self.file_path, mode="a", newline='') as file:
            writer = csv.writer(file)
            writer.writerow(data)

    def get_expenses(self, this_month: bool = False) -> List[List[str]]:
        expenses = []
        todays_date = datetime.now()
        with open(self.file_path, mode="r") as file:
            reader = csv.reader(file)
            next(reader)

            for row in reader:
                if this_month == True:
                    rows_date = datetime.strptime(row[0], "%d-%m-%Y")
                    if todays_date.year == rows_date.year and todays_date.month == rows_date.month:
                        expenses.append(row)
                else:
                    expenses.append(row)
        
        return expenses

    def get_expense_total(self, this_month: bool = False) -> float:
        expenses = self.get_expenses()
        total_amount = 0
        todays_date = datetime.now()
        for line in expenses:
            date_str, _, amount_str, _ = line
            
            if this_month == True:
                date = datetime.strptime(date_str, "%d-%m-%Y")
                if date.year == todays_date.year and date.month == todays_date.month:
                    total_amount += float(amount_str)
            else:
                total_amount += float(amount_str)

        return total_amount

    def get_expense_average(self, this_month: bool = False) -> float:
        expenses = self.get_expenses(this_month=this_month)
        total = self.get_expense_total(this_month=this_month)
        average = total / len(expenses) if len(expenses) != 0 else 1

        return average

    def get_most_frequent_category(self, this_month: bool = False) -> str | None:
        expenses = self.get_expenses(this_month=this_month) 
        categories = [expense[3] for expense in expenses]
        category_count = Counter(categories)
        try:
            most_frequent_category = category_count.most_common()[0]
        except Exception as e:
            print(e)
            most_frequent_category = ["No expense"]
        return most_frequent_category[0]


    def get_expense_line(self, date: str, name:str , amount: str) -> int | None:
         expenses = self.get_expenses()
         line_to_delete = None
         for i, line in enumerate(expenses):
             if date == line[0] and name == line[1] and amount == line[2]:
                 line_to_delete = i
         return line_to_delete

    def get_total_number_of_transactions(self, this_month: bool = False) -> int:
         expenses = self.get_expenses(this_month=this_month)
         return len(expenses)

    def delete_expense(self, date: str, name: str, amount: str) -> None:
        expenses = self.get_expenses()
        line_to_delete = self.get_expense_line(date, name, amount)

        if line_to_delete is not None:
            expenses.pop(line_to_delete)
            
            data = []
            data.append(self.headers)
            for line in expenses:
                data.append(line)

            with open(self.file_path, mode="w", newline='') as file:
                writer = csv.writer(file)
                writer.writerows(data)

    def modify_date(self, date: str, name: str, amount: str, new_date: str) -> None:
        expenses = self.get_expenses()
        line_to_modify = self.get_expense_line(date, name, amount)

        if line_to_modify is not None:
            expenses[line_to_modify][0] = new_date

            data = []
            data.append(self.headers)
            for line in expenses:
                data.append(line)

            with open(self.file_path, mode="w", newline='') as file:
                writer = csv.writer(file)
                writer.writerows(data)


if __name__ == "__main__":
    manager = budgetManager()

        
