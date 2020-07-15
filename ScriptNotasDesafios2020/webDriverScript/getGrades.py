'''
This script is for calculating the students grades in a single contest. 
You can use it by configuring the dict with the username of each student
then putting your login information in my.login (if your contest is private).
It uses a webdriver (Which is not how it should be done. But I wanted to learn
more about it). 
'''

import sys
from bs4 import BeautifulSoup
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as ec
from collections import OrderedDict

students = OrderedDict({'franciscowernke': 0, 'gabrielhpr': 0, 'gabrielp': 0, 'guilhermes': 0, 'gustavo25': 0, 'igor_barberino': 0, 'lafifi': 0, 'lirineu': 0, 'lucianoleao': 0, 'mazetti_07': 0, 'mbsilva': 0, 'melloguel': 0, 'mscosta': 0, 'rrvsrafael': 0, 'rshimabukuro': 0, 'skeleton237': 0, 'thiagosteixeira': 0, 'tutss': 0, 'vinifrota': 0, 'wanniny': 0, 'willhiro': 0})

def timeToInt(stringTime):
    splitted_times = stringTime.split(':')
    hour = int(splitted_times[0])
    minute = int(splitted_times[1]) 
    second = int(splitted_times[2][:2])
    return hour * 60 * 60 + minute * 60 + second

class VjudgeBot():
    def __init__(self):
        self.driver = webdriver.Firefox(executable_path=r'/Users/brelf/Git/Desafios2020/ScriptNotasDesafios2020/geckodriver')
        self.wait = WebDriverWait(self.driver, 15)
    def login(self):
        vjudge_url = 'https://vjudge.net/'
        self.driver.get(vjudge_url)
        login_button = self.driver.find_element_by_xpath('/html/body/nav/div/ul/li[8]/a')
        login_button.click()
        loginFile = open('my.login', 'r')
        USERNAME, PASSWORD = loginFile.readlines()
        self.wait.until(ec.visibility_of_element_located((By.XPATH, '//*[@id="login-username"]')))
        username_field = self.driver.find_element_by_xpath('//*[@id="login-username"]')
        username_field.send_keys(USERNAME)
        password_field = self.driver.find_element_by_xpath('//*[@id="login-password"]')
        password_field.send_keys(PASSWORD)
        confirm_login_button = self.driver.find_element_by_xpath('//*[@id="btn-login"]')
        confirm_login_button.click()    
    def getContestGrades(self, contest_link, upsolving_time):
        upsolving_time *= 60 * 60
        self.driver.get(contest_link)
        self.wait.until(ec.visibility_of_element_located((By.XPATH, '//*[@id="contest-rank-table"]')))
        soup = BeautifulSoup(self.driver.page_source, 'html.parser')
        rank_table = soup.find("table", attrs={"id": "contest-rank-table"})
        rank_table_data = rank_table.tbody.find_all('tr')
        sum_of_all = 0
        total_students = 0
        username_grade = []
        for tr in rank_table_data:
            username = tr.find('td', attrs={"class": "team meta"}).text.split(' (')[0]
            acs = tr.find_all('td', attrs={"class": "prob accepted"}) + tr.find_all('td', attrs={"class": "prob accepted fb"})
            grades = [.5 if timeToInt(x.text) > upsolving_time else 1 for x in acs]
            total_grade = 0
            for grade in grades:
                total_grade += grade
            username = username.lower()
            if username in students:
                students[username] = total_grade
                sum_of_all += total_grade
                total_students += 1

        for username, grade in students.items():
            print(username, grade)
        print("Sum ->", sum_of_all, "Total Students (that solve at least 1)", total_students)
        mean_grade = sum_of_all / total_students
        
        print("Mean Grade  ", mean_grade)
        print('\n\n\n\n==============================\n\n\n\n')
        for username, grade in students.items():
            print(grade)
    def close(self):
        self.driver.close()


bot = VjudgeBot()
bot.login()
bot.getContestGrades(sys.argv[1], int(sys.argv[2]))
bot.close()
