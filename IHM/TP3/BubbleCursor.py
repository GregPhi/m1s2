import sys
from math import sqrt
from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *

class BubbleWidget():
    defaultColor = QColor(Qt.black)
    def __init__(self,targets):
        self.setMouseTracking(True)
        self.x = 0
        self.y = 0
        self.size = 66666
        self.targets = targets
        self.closest = None
        self.cursor = QCursor()

    def paintEvent(self,event):
        painter = QPainter()
        paint(painter)

    def paint(self,painter):
        painter.setPen(QPen(defaultColor))
        painter.drawEllipse(self.x,self.y,self.size*2)

    def mouseMoveEvent(self,event):
        move(event.x(),event.y())
        self.cursor.setPos(self.x,self.y)
        self.update()

    def move(self,x,y):
        self.x = x
        self.y = y
        for i in range(len(self.targets)):
            distanceMin = 6666
            minIndex = 6666
            distance = sqrt([(self.targets[i].getX() - self.x)**2]+[(self.targets[i].getY() - self.y)**2])
            distance -= self.targets[i].getRadius()
            if(distance<distanceMin):
                distanceMin = distance
                minIndex = i
        self.closest = self.targets[minIndex]
        self.targets[minIndex].setSelect()
