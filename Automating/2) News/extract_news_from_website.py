import os
import sys
from datetime import datetime
from pathlib import Path

import pandas as pd
from selenium import webdriver
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.chrome.service import Service


def get_news():
    website = 'https://www.thesun.co.uk/sport/football/'
    path = '/home/pedro/Documentos/chromedriver_linux64/chromedriver'

    options = Options()
    options.add_argument('--headless')

    service = Service(executable_path=path)
    driver = webdriver.Chrome(service=service, options=options)
    driver.get(website)

    containers = driver.find_elements(by="xpath", value='//div[@class="teaser__copy-container"]')

    titles = []
    subs = []
    links = []

    for container in containers:
        title = container.find_element(by="xpath", value='./a/h3').text
        sub = container.find_element(by="xpath", value='./a/p').text
        link = container.find_element(by="xpath", value='./a').get_attribute("href")

        titles.append(title)
        subs.append(sub)
        links.append(link)

    df_headlines = pd.DataFrame({'Titulo': titles, 'Conteudo': subs, 'Link': links})

    now = datetime.now()
    date = now.strftime("%d-%m-%Y")

    application_path = os.path.dirname(sys.executable)

    print('antes')
    if application_path.find('venv') != -1:
        print('entrei')
        application_path = str(Path(__file__).parent)

    print(application_path)

    possible_path = os.path.join(application_path, 'headlines')
    if not os.path.exists(possible_path):
        os.mkdir(possible_path)

    final_path = os.path.join(application_path, 'headlines', f'headline_{date}.csv')

    df_headlines.to_csv(final_path, index=False)
    driver.quit()


def partial_to_full_path(path):
    parent = os.path.abspath(__file__)
    return os.path.join(parent, path.lstrip('../'))


def read_csv():
    df = pd.read_csv('headlines/headline_27-01-2023.csv', sep=',')
    print(df)


if __name__ == "__main__":
    pd.options.display.width = None  # pd.set_option('display.width', 320)
    pd.options.display.max_columns = None

    get_news()
    # read_csv()
