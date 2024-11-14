import pandas as pd
import matplotlib.pyplot as plt
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from user_infos import *
import time
import os
import shutil

class MonkeyType:
    def __init__(self):
        print("Opening browser...")
        
        self.download_csv()
        self.move_downloaded_csv_data()
        
        print("Plotting...")
        
        self.file_path = "/Users/ftl/Dev/000-DataManagement/MonkeyTypeAnalysis/data.csv"
        self.data = pd.read_csv(self.file_path)
        self.data['datetime'] = pd.to_datetime(self.data['timestamp'], unit='ms')
        self.data['date'] = self.data['datetime'].dt.date
        self.max_wpm_per_day = self.data.groupby('date')['wpm'].max()
        
    def plotting(self):  
        plt.figure(figsize=(10, 5))
        plt.plot(self.max_wpm_per_day.index, self.max_wpm_per_day.values, marker='o', color='blue')
        plt.xlabel('Date')
        plt.ylabel('Maximum Words Per Minute')
        plt.title('Maximum WPM Recorded Each Day')
        plt.grid(True)
        plt.xticks(self.max_wpm_per_day.index, rotation=85, ha="right")
        plt.tight_layout()
        plt.show()
        

    def download_csv(self):
        options = webdriver.FirefoxOptions()
        options.add_argument('--headless')
        driver = webdriver.Firefox(options=options)
        driver.get('https://monkeytype.com/account')

        print("Connecting to MonkeyType...")
        # Click 'Reject All' if present
        try:
            reject_all_button = WebDriverWait(driver, 5).until(
                EC.element_to_be_clickable((By.CLASS_NAME, 'rejectAll'))
            )
            driver.execute_script("arguments[0].click();", reject_all_button)
            # print("Clicked 'Reject All'")
        except Exception as e:
            print(f"Error clicking 'Reject All': {e}")

        # Handling the consent modal
        try:
            WebDriverWait(driver, 5).until(
                EC.visibility_of_element_located((By.CLASS_NAME, 'fc-consent-root'))
            )

            accept_button = WebDriverWait(driver, 10).until(
                EC.element_to_be_clickable((By.CLASS_NAME, 'fc-button-background'))
            )
            driver.execute_script("arguments[0].click();", accept_button)
            # print("Clicked in consent modal accept button")
        except Exception as e:
            print(f"Error interacting with modal: {e}")
        
        print("Logging in...")
        # Wait two seconds
        time.sleep(2)
        
        # Handling email input
        try:
            email_input = driver.find_element(By.NAME, 'current-email')
            email_input.send_keys(user_email)
            # print("Email inserted sucessfully")
        except Exception as e:
            print(f"Error interacting with the email input: {e}")
        
        # Handling password input
        try:
            password_input = driver.find_element(By.NAME, 'current-password')
            password_input.send_keys(user_password)
            # print("Password inserted sucessfully")
        except Exception as e:
            print(f"Error interacting with the password input: {e}")
        
        # Handling login button click
        try:
            driver.find_element(By.CLASS_NAME, 'signIn').click()
            # print("Clicked on the 'Sign In' button sucessfully")
        except Exception as e:
            print(f"Error interacting with the 'Sign In' button: {e}")
        
        print("Downloading CSV...")
        # Wait for loggin in
        time.sleep(5)
        
        # Clicking the 'Export CSV' button
        try:
            export_csv_button = WebDriverWait(driver, 5).until(
                EC.element_to_be_clickable((By.CLASS_NAME, 'button.exportCSV'))
            )
            driver.execute_script("arguments[0].click();", export_csv_button)
            # print("Clicked on the 'Export CSV' button")
        except Exception as e:
            print(f"Error clicking the 'Export CSV' button: {e}")
        
        # Wait for the download to finish
        time.sleep(2)
                      
        # Clean up
        driver.quit()

    def move_downloaded_csv_data(self):
        source_path = "/Users/ftl/Downloads/results.csv"
        target_path = "/Users/ftl/Dev/000-DataManagement/MonkeyTypeAnalysis/data.csv"
        
        # Check if file exists
        if os.path.exists(source_path):
            
            # Check if a file with the new name already exists at the destination and remove it if it does
            if os.path.exists(target_path):
                os.remove(target_path)
                # print("Old data removed")
                
            # Move and rename new data
            shutil.move(source_path, target_path)
            # print(f"File moved and renamed from {source_path} to {target_path}")
        
if __name__ == "__main__":
    manager = MonkeyType()
    manager.plotting()
