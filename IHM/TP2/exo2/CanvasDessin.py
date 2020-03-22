import sys
from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *

class CanvasDessin(QWidget):
    def __init__(self):
        super(QWidget, self).__init__()
        self.setMinimumSize(500,400)
        self.traces = list()

    def paintEvent(self,event):
        path = QPainterPath()
        for i i in range(len(self.traces)):
            path.addPath(self.tarces[i])

    def 

    def paintEvent(self,event):
        pass

    def mouseMoveEvent(self, event):
        pass

    def mousePressEvent(self, event):
        pass

    def mouseReleaseEvent(self, event):
        pass
