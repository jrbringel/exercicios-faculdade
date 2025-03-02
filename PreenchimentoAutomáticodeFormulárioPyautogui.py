# Automação com PyAutoGUI: Criando e Preenchendo um Formulário no Bloco de Notas
import pyautogui
import time

pyautogui.hotkey("win", "r")
time.sleep(1)
pyautogui.write("notepad")
pyautogui.press("enter")
time.sleep(2)

pyautogui.write("=== Formulário de Cadastro ===")
pyautogui.press("enter")
pyautogui.write("Nome: ")
pyautogui.write("Whstelley Bringel Lima")
pyautogui.press("enter")
pyautogui.write("E-mail: ")
pyautogui.write("whstelleybringellima@gmail.com")
pyautogui.press("enter")
pyautogui.write("Telefone: ")
pyautogui.write("62 986201911")
pyautogui.press("enter")
pyautogui.write("Curso: ")
pyautogui.write("Engenharia de Software")
pyautogui.press("enter")
