import serial
from PyQt5.QtWidgets import *
from PyQt5 import QtGui
from PyQt5.QtGui import QFontDatabase, QFont
from PyQt5.QtCore import QThread, pyqtSignal, Qt
import sys
import math
import time


class ArdSerial:

    def __init__(self, port):
        print("ArdSerial started... ")
        self.ser = serial.Serial(port, 9600)
      #  self.ser.write(b'f$')
       # self.ser.write(b'g$')

    def send_val(self, val):

        self.ser.write(val)
        con = False
       # while con == False: #idc
        #    while self.ser.in_waiting > 0:
         #       print(self.ser.readline())

        # time.sleep(.25)
        # print("Test")

    def enable(self, val):
        print("passed", val)
        if val == 0:
            self.ser.write(b'4')
            # print(b'no')
        if val == 2:
            self.ser.write(b'2')
            # print(b'yes')

port = '/dev/ttyACM0'

ard = ArdSerial(port)
time.sleep(10)
ard.send_val(b'gcc2444$')
print("Outed")
