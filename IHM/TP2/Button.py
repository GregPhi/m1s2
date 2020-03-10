import sys
from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *

class CanvasButton(QWidget):
    bbox = QRect()
    def __init__(self):
        super(QWidget, self).__init__()

def main(args):
    app = QApplication(args)
    win = QMainWindow()
    cBut = CanvasButton()
    win.resize(500,300)
    win.setWindowTitle("TP PyQt")
    win.setCentralWidget(cBut)
    win.show();
    app.exec()

if __name__ == "__main__":
    main(sys.argv)
