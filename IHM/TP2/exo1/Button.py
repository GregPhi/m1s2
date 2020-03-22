import sys
from ButtonModel import ButtonModel
from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *

class CanvasButton(QWidget):
    defaultCol = Qt.green
    hoverCol = Qt.red
    pressCol = Qt.blue

    def __init__(self):
        super(QWidget, self).__init__()
        self.setMouseTracking(True)
        self.bbox = QRect(5,5,100,50)
        self.cursorOver = False
        self.buttonModel = ButtonModel()

    def cursorOnEllipse(self, point):
        if self.ellipse.contains(point):
            #print("cursor on ELLIPSE")
            return True
        else:
            #print("cursor not in ELLIPSE")
            return False

    def paintEvent(self,event):
        painter = QPainter(self)
        if (self.buttonModel.state == self.buttonModel.hover):
            painter.setBrush(self.hoverCol)
        elif (self.buttonModel.state == self.buttonModel.pressIn):
            painter.setBrush(self.pressCol)
        else:
            painter.setBrush(self.defaultCol)
        painter.drawEllipse(self.bbox)

    def mouseMoveEvent(self, event):
        self.ellipse = QRegion(self.bbox,QRegion.Ellipse)
        curs = self.cursorOver
        self.cursorOver = self.cursorOnEllipse(event.pos())
        if (self.cursorOver and not curs):
            self.buttonModel.enter()
        elif (not self.cursorOver and curs):
            self.buttonModel.leave()
        self.update()

    def mousePressEvent(self, event):
        self.buttonModel.press()
        self.cursorOver = self.cursorOnEllipse(event.pos())
        if (self.cursorOver):
            self.setCursor(QCursor(Qt.PointingHandCursor))
        #cercle autour du pointeur
        self.update()

    def mouseReleaseEvent(self, event):
        self.buttonModel.release()
        curs = self.cursorOver
        self.cursorOver = self.cursorOnEllipse(event.pos())
        if (self.cursorOver):
            cursor = QCursor()
            self.setCursor(QCursor(Qt.UpArrowCursor))
        self.update()
        #print("mouse release event")

    def enterEvent(self, event):
        pass
        #print("enter event")

    def leaveEvent(self, event):
        pass
        #print("leave event")


def main(args):
    app = QApplication(args)
    win = QMainWindow()
    cBut = CanvasButton()
    win.resize(500,300)
    win.setWindowTitle("TP PyQt")
    win.setCentralWidget(cBut)
    win.show();
    app.exec()

if __name__ == "__main__":
    main(sys.argv)
