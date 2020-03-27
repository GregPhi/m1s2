import sys
from ExpSetup import ExpSetup
from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *

def main(args):
    app = QApplication(args)
    win = QMainWindow()
    win.resize(1024,800)
    exp = ExpSetup()
    win.setCentralWidget(exp)
    win.show()
    app.exec()

if __name__ == "__main__":
    main(sys.argv)
