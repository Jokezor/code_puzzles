from selenium import webdriver
from selenium.webdriver.common.action_chains import ActionChains
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions

driver = webdriver.Firefox()
driver.get("https://www.slapchris.com")
canvas = WebDriverWait(driver, 10).until(expected_conditions.element_to_be_clickable((By.ID, "defaultCanvas0")))

size = canvas.size
width, height = size['width'], size['height']

ActionChains(driver, 20).move_to_element_with_offset(canvas, 10, 200).click_and_hold().move_by_offset(width-20, 0).release().perform()
