import sys
from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *

class Target:
    defaultColor = QColor(Qt.red)
    highlightCol = QColor(Qt.green)
    toSelectCol = QColor(Qt.blue)
    def __init__(self,x,y,size):
        self.x = x
        self.y = y
        self.size = size
        self.toSelect = false
        self.highlighted = false

    def paint(self,painter):
        if self.toSelect:
            color = toSelectCol
        elif self.highlighted:
            color = highlightCol
        else:
            color = defaultColor
        painter.setPen(QPen(color))
        painter.drawEllipse(self.x,self.y,self.size)

    def getX(self):
        return self.x
    def getY(self):
        return self.y
    def getRadius(self):
        return self.size
    def setSelect(self):
        self.toSelect = True

def main(args):
    app = QApplication(args)
    win = QMainWindow()
    win.resize(1024,800)
    win.show()
    app.exec()

if __name__ == "__main__":
    main(sys.argv)
