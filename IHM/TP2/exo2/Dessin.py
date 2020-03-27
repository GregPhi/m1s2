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

        bar = self.addToolBar("Color")

        red = QAction("red",self)
        red.triggered.connect(self.setRed)
        bar.addAction(red)

        yellow = QAction("yellow",self)
        yellow.triggered.connect(self.setYellow)
        bar.addAction(yellow)

        green = QAction("green",self)
        green.triggered.connect(self.setGreen)
        bar.addAction(green)

        blue = QAction("blue",self)
        blue.triggered.connect(self.setBlue)
        bar.addAction(blue)

        dialog = QAction("dialog",self)
        dialog.triggered.connect(self.dialogColor)
        bar.addAction(dialog)

    def setRed(self):
        self.canvas.modifColor(Qt.red)
    def setYellow(self):
        self.canvas.modifColor(Qt.yellow)
    def setGreen(self):
        self.canvas.modifColor(Qt.green)
    def setBlue(self):
        self.canvas.modifColor(Qt.blue)

    def dialogColor(self):
        color = QColorDialog.getColor()

def main(args):
    app = QApplication(args)
    dessin = Dessin()
    dessin.show()
    app.exec()

if __name__ == "__main__":
    main(sys.argv)
