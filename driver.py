from PyQt5.QtWidgets import QApplication, QLabel, QMainWindow, QFrame, QPushButton, QComboBox
from PyQt5 import QtGui
from PyQt5.QtGui import QFontDatabase, QFont

import sys


class rLum(QMainWindow):
    w = 0
    h = 0
    port = 0
    #Setup all the goodies
    def __init__(self, *args, **kwargs):
        super(rLum, self).__init__( *args, **kwargs)
        self.w = 1280
        self.h = 720
        self.setWindowTitle('xShine')
        self.setWindowIcon(QtGui.QIcon('logo.png'))
        frm = QFrame()
        self.setCentralWidget(frm)
        self.resize(self.w, self.h)
        self.setStyleSheet("QLabel {font: 30pt Trebuchet MS}")
        self.addGiu()

    def setEffect(self, index):
        print('set to ' + str(index))

    def addGiu(self):
        cb = QComboBox(self)
        cb.addItem("01")
        cb.addItem("02")
        cb.move(50, 400)

        #Strobe block
        str_button = QPushButton('Strobe', self)
        str_button.setToolTip('Entire strip rapidly turns on and off to set color and frequency')
        str_button.move(200, 400)
        str_button.clicked.connect(lambda: self.setEffect(1))

        #Pulse blocke
        pulse_button = QPushButton('Pulse', self)
        pulse_button.setToolTip('Entire strip will pulse to set color and frequency')
        pulse_button.move(300, 400)
        pulse_button.clicked.connect(lambda: self.setEffect(2))


        label = QLabel('Welcom to rLum', self)
        label.adjustSize()
        label.move(self.w/2 - 100, 0)





app = QApplication(sys.argv)

window = rLum()
window.show()

app.exec()
