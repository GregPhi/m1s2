import sys
from MainBubble import Target
from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *

class BubbleWidget(QWidget):
    def __init__(self):
        supze(QWidget,self).__init__()
        self.targets = list()
        file = open("targets.csv",'r')
        line = csv.reader(file)
        for row in line:
            t = Target(row[0],row[1],row[2])
            self.targets.append(t)

    def paintEvent(self,event):
        painter = QPainter()
        for i in range(len(self.targets)):
            self.targets[i].paint(painter)
