import serial
import pyautogui
import time

Arduino = serial.Serial('COM4', 9600)
time.sleep(0)
print(Arduino.readline())
while 1:
    Data = Arduino.readline()
    print(Arduino.readline())

    if Data == b'0\r\n':
        pyautogui.keyUp('right')
        pyautogui.keyUp('left')
        pyautogui.keyDown('up')


    elif Data == b'1\r\n':
        Arduino.flushOutput()
        Arduino.flushInput()
        pyautogui.keyDown('up')

        pyautogui.keyUp('left')
        pyautogui.keyDown('right')
    elif Data == b'2\r\n':
        Arduino.flushOutput()
        Arduino.flushInput()
        pyautogui.keyDown('up')

        pyautogui.keyUp('right')
        pyautogui.keyDown('left')
    Arduino.flushInput()
    Arduino.flushOutput()
