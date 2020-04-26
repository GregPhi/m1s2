from math import sqrt
from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *

class BubbleCursor():
    # couleur par défault utilisée pour peindre le curseur
    defaultColor = QColor(Qt.green)
    """
    Initialise le BubbleCursor
    """
    def __init__(self,targets):
        self.x = 0
        self.y = 0
        self.size = 42
        self.targets = targets
        self.closest = None

    def getClosest(self):
        """
        Retourne la target la plus proche du BubbleCursor
        return:
        Target - une target
        """
        return self.closest

    def paint(self,painter):
        """
        Peint le curseur
        """
        painter.setPen(QPen(Qt.black))
        painter.setBrush(BubbleCursor.defaultColor)
        painter.drawEllipse(self.x-self.size,self.y-self.size,self.size*2,self.size*2)

    def move(self,x,y):
        """
        Déplace le curseur en x et y
        Puis cherche le target le plus proche du curseur
        """
        self.x = x
        self.y = y
        distanceMin = 6666
        if(self.closest != None):
            self.closest.setHighlighted(False)
        for i in range(len(self.targets)):
            distance = sqrt(abs((self.targets[i].getX() - self.x))**2+(abs(self.targets[i].getY() - self.y))**2)
            if(distance<distanceMin):
                distanceMin = distance
                self.closest = self.targets[i]
        self.closest.setHighlighted(True)
        self.size = distanceMin
