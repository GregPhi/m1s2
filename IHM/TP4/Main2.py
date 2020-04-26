import sys
from ExpSetup import ExpSetup
from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from MainWindow2 import MainWindow2

def main(args):
    """
    Main générale du TP
    """
    app = QApplication(args)
    a = [1024,800]
    if(len(args)==2):
        a.append(args[1])
    win = MainWindow2(a)
    win.show()
    app.exec_()

if __name__ == "__main__":
    main(sys.argv)
