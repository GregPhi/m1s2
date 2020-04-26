import sys
from ExpSetup import ExpSetup
from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from MainWindow import MainWindow

def main(args):
    """
    Main générale du TP
    """
    app = QApplication(args)
    win = MainWindow(1024,800)
    win.show()
    app.exec_()

if __name__ == "__main__":
    main(sys.argv)
