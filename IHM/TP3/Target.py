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
        self.toSelect = False
        self.highlighted = False

    def paint(self,painter):
        if self.toSelect:
            color = Target.toSelectCol
        elif self.highlighted:
            color = Target.highlightCol
        else:
            color = Target.defaultColor
        painter.setPen(QPen(Qt.black))
        painter.setBrush(color)
        painter.drawEllipse(int(self.x-self.size/2),int(self.y-self.size/2),self.size,self.size)

    def getX(self):
        return self.x
    def getY(self):
        return self.y
    def getRadius(self):
        return self.size
    def setSelect(self,bool):
        self.toSelect = bool
    def setHighlighted(self,bool):
        self.highlighted = bool
