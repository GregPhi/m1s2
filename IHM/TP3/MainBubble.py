import sys
from BubbleWidget import BubbleWidget
from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *

def main(args):
    app = QApplication(args)
    win = QMainWindow()
    win.resize(1024,800)
    bub = BubbleWidget()
    win.setCentralWidget(bub)
    win.show()
    app.exec()

if __name__ == "__main__":
    main(sys.argv)
