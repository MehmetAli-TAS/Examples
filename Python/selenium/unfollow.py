import time
from selenium import webdriver
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.by import By

print("Program calisiyor!")
chrome_options = Options()
chrome_options = webdriver.ChromeOptions()
#chrome_options.add_argument("--headless")
#chrome_options.add_argument("--no-sandbox")
#chrome_options.add_argument("--disable-dev-shm-usage")
driver = webdriver.Chrome(chrome_options)

url = "https://www.instagram.com/accounts/login/"
driver.get(url)
driver.maximize_window()
time.sleep(10)

print("siteye giriliyor")

username = driver.find_element(By.NAME, 'username').send_keys('username') 
password = driver.find_element(By.NAME, 'password').send_keys('password')
girisbutton = driver.find_element(By.XPATH, '//*[@id="loginForm"]/div/div[3]/button').click() #Log-in button

time.sleep(10)
print("giris basarili")
time.sleep(5)
z = 0
try:
    while True:
        driver.get('https://www.instagram.com/thekali_01/following/')
        time.sleep(3)
        takipciler = driver.find_element(By.XPATH, '/html/body/div[2]/div/div/div/div[2]/div/div/div[1]/div[2]/div/div[1]/section/main/div/header/section[3]/ul/li[3]/div/a').click()
        time.sleep(3)
        for i in range(1, 11):
            takip_birak = driver.find_element(By.XPATH, f'/html/body/div[6]/div[1]/div/div[2]/div/div/div/div/div/div/div[4]/div[{i}]/div/div/div/div/div/div/div[3]/div/button').click()
            z = z+1
            print(z, "takip birakildi!!!")
except:
    print("islem tamamlandi!!!")



