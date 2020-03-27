import sys
from Target import Target
from BubbleCursor import *
from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from csv import *
from time import *
from random import *

class NormalWidget(QWidget):
    def __init__(self):
        super(QWidget,self).__init__()
        self.setMouseTracking(True)
        self.targets = list()
        file = open("targets.csv",'r')
        line = reader(file)
        for row in line:
            t = Target(int(row[0]),int(row[1]),int(row[2]))
            self.targets.append(t)
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
