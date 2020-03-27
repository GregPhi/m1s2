import sys
from NormalWidget import NormalWidget
from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *

def main(args):
    app = QApplication(args)
    win = QMainWindow()
    win.resize(1024,800)
    bub = NormalWidget()
    win.setCentralWidget(bub)
    win.show()
    app.exec()

if __name__ == "__main__":
    main(sys.argv)
