import sys
from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *

class CanvasDessin(QWidget):
    def __init__(self):
        super(QWidget, self).__init__()
        self.setMinimumSize(1250,750)
        self.traces = list()
        self.painter = QPainter()
        self.pen = QPen(Qt.black)
        self.painter.setPen(self.pen)
        self.path = QPainterPath()

    def paintEvent(self,event):
        for i in range(len(self.traces)):
            self.path.addPath(self.tarces[i])
        self.painter.drawPath(self.path)

    def modifColor(self,color):
        self.pen = QPen(color)
        self.painter.setPen(self.pen)
        self.update()

    def modif(self,width):
        self.pen.setWidth(witdh)
        self.painter.setPen(self.pen)
        self.update()

    def mouseMoveEvent(self, event):
        pass

    def mousePressEvent(self, event):
        pass

    def mouseReleaseEvent(self, event):
        pass
