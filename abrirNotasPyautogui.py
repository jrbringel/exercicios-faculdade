# Automação com PyAutoGUI: Abrir e fechar o Bloco de Notas
import pyautogui
import time

pyautogui.press("win")
time.sleep(1)
pyautogui.write("notepad")
pyautogui.press("enter")
time.sleep(2)
pyautogui.write("Automação funcionando!")
time.sleep(2)
pyautogui.hotkey("alt", "f4")
pyautogui.press("right")
pyautogui.press("enter")
