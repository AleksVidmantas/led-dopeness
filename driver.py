import serial
from PyQt5.QtWidgets import *
from PyQt5 import QtGui
from PyQt5.QtGui import QFontDatabase, QFont
from PyQt5.QtCore import QThread, pyqtSignal
import sys


class Reader(QThread):

    def __init__(self, ard):
        QThread.__init__(self)
        print("setup")
        self.ard = ard
        #self.run()

    def run(self):
        while True:  # Or: while ser.inWaiting():
            print("Gleemed: ", self.ard.ser.readline())


class ArdSerial:

    def __init__(self, port):
        print("ArdSerial started... ")
        self.ser = serial.Serial(port, 9600)
        self.ser.write(b'f$')
        self.ser.write(b'g$')

    def send_val(self, val):
        self.ser.write(val)
        #print("Test")

    def enable(self, val):
        print("passed", val)
        if val == 0:
            self.ser.write(b'4')
            #print(b'no')
        if val == 2:
            self.ser.write(b'2')
            #print(b'yes')


class RLum(QMainWindow):
    w = 0
    h = 0
    port = 0
    color = 0
    port = 'COM6'
    print("Help")

    # Setup all the goodies
    def __init__(self, *args, **kwargs):

        self.ard = ArdSerial(self.port)
        self.read_thread = Reader(self.ard)
        print("RLUM ")
        super(RLum, self).__init__( *args, **kwargs)
        self.w = 1280
        self.h = 720
        self.setWindowTitle('xShine')
        self.setWindowIcon(QtGui.QIcon('logo.png'))
        frm = QFrame()
        self.setCentralWidget(frm)
        self.resize(self.w, self.h)
        self.setStyleSheet("QLabel {font: 30pt Trebuchet MS}")
        self.addGui()
        self.read_thread.start()

    def setEffect(self, index):
        self.ard.send_val(b'g2$')
        print('set to ' + str(index))

    def setColor(self):
        self.color = QColorDialog.getColor()

    def addGui(self):
        #on/off
        enabled_btn = QCheckBox("Enable", self)
        enabled_btn.move(10, 0)
        enabled_btn.toggle()
        enabled_btn.setToolTip('Enables/Disables entire light')
        enabled_btn.clicked.connect(lambda: self.ard.enable(enabled_btn.checkState()))

        # Set port button/lists block
        cb = QComboBox(self)
        cb.addItem("01")
        cb.addItem("02")
        cb.move(50, 400)

        set_port_btn = QPushButton('Set Port #', self)
        set_port_btn.setToolTip('Sets port # only, if the prefix is incorrect, use manual port set')
        set_port_btn.move(50, 440)
        set_port_btn.clicked.connect(lambda: print("Define me plz"))

        #Manual port text box
        man_port_txt = QLineEdit(self)
        man_port_txt.move(50, 500)
        man_port_txt.setToolTip("If a manual port is required, enter it here")
        man_port_txt.resize(100, 25)


        #Manual port set port button
        set_man_port = QPushButton('Set Port', self)
        set_man_port.setToolTip('Sets port directly to what is in the text box above')
        set_man_port.move(50, 530)
        set_man_port.clicked.connect(lambda: self.ard.send_val("Test"))

        #Strobe block
        str_button = QPushButton('Strobe', self)
        str_button.setToolTip('Entire strip rapidly turns on and off to set color and frequency')
        str_button.move(200, 400)
        str_button.clicked.connect(lambda: self.setEffect(1))

        #Pulse block
        pulse_button = QPushButton('Pulse', self)
        pulse_button.setToolTip('Entire strip will pulse to set color and frequency')
        pulse_button.move(300, 400)
        pulse_button.clicked.connect(lambda: self.ard.ser.write(b'*g1$'))

        #Chase block
        chase_btn = QPushButton('Chase', self)
        chase_btn.setToolTip('One color will chase the other until it hits the beginning of strip, then repeat')
        chase_btn.move(400, 400)
        chase_btn.clicked.connect(lambda: self.ard.ser.write(b'*g2$'))

        #Welcome box
        label = QLabel('Welcome to LED Control', self)
        label.adjustSize()
        label.move(self.w/2 - 200, 0)

        #color block
        color_btn = QPushButton('Select Color', self)
        color_btn.move(900, 400)
        color_btn.clicked.connect(lambda: self.setColor())





app = QApplication(sys.argv)

window = RLum()
window.show()

app.exec()
