import sys
from Target import Target
from BubbleCursor import BubbleCursor
from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from csv import *
from time import *
from random import *

class BubbleWidget(QWidget):
    def __init__(self):
        super(QWidget,self).__init__()
        self.setMouseTracking(True)
        self.targets = list()
        file = open("targets.csv",'r')
        line = reader(file)
        for row in line:
            self.targets.append(Target(int(row[0]),int(row[1]),int(row[2])))
        self.curosr = BubbleCursor(self.targets)
        self.timer = None
        self.random = None
        self.randomTarget()

    def randomTarget(self):
        self.random = choice(self.targets)
        self.random.setSelect(True)
        self.timer = time()

    def paintEvent(self,event):
        painter = QPainter(self)
        self.curosr.paint(painter)
        for i in range(len(self.targets)):
            self.targets[i].paint(painter)
        self.update()

    def mouseMoveEvent(self,event):
        self.curosr.move(event.x(),event.y())
        self.update()

    def mousePressEvent(self, event):
        if(event.button() == Qt.LeftButton):
            temp = self.curosr.getClosest()
            if(temp == self.random):
                self.random.setSelect(False)
                print("Timer : ",time() - self.timer)
                self.randomTarget()
