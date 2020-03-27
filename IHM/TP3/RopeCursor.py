import sys
from math import sqrt
from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from BubbleCursor import BubbleCursor

class RopeCursor(BubbleCursor):
    def __init__(self,targets):
        super(BubbleCursor,self).__init__()
        self.x = 0
        self.y = 0
        self.size = 42
        self.targets = targets
        self.closest = None

    def paint(self,painter):
        painter.setPen(QPen(Qt.black))
        painter.setBrush(BubbleCursor.defaultColor)
        if(self.closest != None):
            painter.drawLine(self.x,self.y,self.closest.getX(),self.closest.getY())

    def getClosest(self):
        return self.closest

    def move(self,x,y):
        self.x = x
        self.y = y
        distanceMin = 6666
        if(self.closest != None):
            self.closest.setHighlighted(False)
        for i in range(len(self.targets)):
            distance = sqrt(abs((self.targets[i].getX() - self.x))**2+(abs(self.targets[i].getY() - self.y))**2)
            #if(distance > self.targets[i].getRadius()/2):
            #distance -= self.targets[i].getRadius()/2
            #else:
                #distance = 0
            if(distance<distanceMin):
                distanceMin = distance
                self.closest = self.targets[i]
        self.closest.setHighlighted(True)
        self.size = distanceMin
