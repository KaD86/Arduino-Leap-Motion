# Arduino-Leap-Motion
Gesture controlled by combining the power of Arduino and Python: This technique enables us to control certain functions on our computer/Laptop by simply waving our hand in front of it. We will use two Ultrasonic sensors to determine and read the distance between the monitor and our hands using Arduino, based on this value of distance we will perform certain actions in order to control a media player (VLC). The commands from Arduino are sent to the computer through serial port (USB). This data is going to be then read by python which is running on the laptop (Windows 10) and based on the read data an action will be performed

Software Prerequisites:
•	Environment: Windows 10
•	Install Python [https://www.python.org/downloads/] ---Install it with Environment variables.
•	Install Python Serial Library [https://learn.adafruit.com/arduino-lesson-17-email-sending-movement-detector/installing-python-and-pyserial] PySerial is a Python API module which is used to read and write serial data to Arduino or any other Microcontroller.
•	Arduino IDE https://www.arduino.cc/en/Main/Software 
•	Fritzing: To create arduino prototype for PC. http://fritzing.org/download/
•	NewPing Library for Arduino
•	VLC Player [https://get.videolan.org/vlc/3.0.1/win32/vlc-3.0.1-win32.exe]’
•	Download \ Create .mp4 video to test the project.
•	Install pyautogui using cmd: pip install pyautogui


