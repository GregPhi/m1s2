import sys
from CanvasDessin import CanvasDessin
from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *

class Dessin(QMainWindow):
    def __init__(self):
        super(QMainWindow, self).__init__()
        self.canvas = CanvasDessin()
        self.setCentralWidget(self.canvas)

def main(args):
    app = QApplication(args)
    dessin = Dessin()
    dessin.show()
    app.exec()

if __name__ == "__main__":
    main(sys.argv)
