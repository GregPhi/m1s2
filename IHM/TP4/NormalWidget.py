import sys
from Target import Target
from NormalCursor import *
from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from csv import *
from time import *
from random import *
import os

class NormalWidget(QWidget):

    signal = pyqtSignal(bool)

    """
    """
    def __init__(self,num_util,nb_repet,taille,densite,pathGenPoints,pathRandPoints):
        super(QWidget,self).__init__()
        self.setMouseTracking(True)
        self.num_util = num_util
        self.nb_repet = nb_repet
        self.taille = taille
        self.densite = densite
        self.cpt = nb_repet
        self.targets = list()
        file1 = open(pathGenPoints,'r')
        line1 = reader(file1)
        for row in line1:
            self.targets.append(Target(int(row[0]),int(row[1]),int(row[2])))
        #file2 = open(pathRandPoints,'r')
        #line2 = reader(file2)
        self.randoms = list()
        #for row in line2:
        #    self.randoms.append(Target(int(row[0]),int(row[1]),int(row[2])))
        self.curosr = NormalCursor(self.targets)
        self.error = 0
        self.timer = None
        self.random = None
        self.randomTarget()
        self.fileL = "log@"+str(self.num_util)+".csv"
        self.fileLog = open(self.fileL, 'a', newline='')
        self.writerLog = writer(self.fileLog)
        self.log = list()

    def randomTarget(self):
        """
        Choisi une target de façon aléatoire
        """
        if(self.cpt == 0):
            self.winner()
            self.signal.emit(True)
            return
        self.random = choice(self.targets)
        while(self.randoms.count(self.random)>0):
            self.random = choice(self.targets)
        self.randoms.append(self.random)
        self.random.setSelect(True)
        self.cpt -= 1
        self.timer = time()

    def paintEvent(self,event):
        """
        Affiche les targets
        """
        painter = QPainter(self)
        for i in range(len(self.targets)):
            self.targets[i].paint(painter)
        self.update()

    def mouseMoveEvent(self,event):
        """
        Lance le mouvement du curseur
        """
        self.curosr.move(event.x(),event.y())
        self.update()

    def mousePressEvent(self, event):
        """
        Si il y a un clique gauche :
            - si la target sélectionnée est bonne : choisit une nouvelle target à sélectionner
            - sinon incrémente le total d'erreur
        """
        if(event.button() == Qt.LeftButton):
            temp = self.curosr.getClosest()
            if(temp == self.random):
                self.random.setSelect(False)
                t = time() - self.timer
                self.log.append([self.num_util,"Normal",self.densite,self.taille,self.nb_repet-self.cpt,str(t).replace(".",","),1])
                self.randomTarget()
            else:
                self.error += 1
                t = time() - self.timer
                self.log.append([self.num_util,"Normal",self.densite,self.taille,self.nb_repet-self.cpt,str(t).replace(".",","),0])

    def winner(self):
        """
        Affiche les informations de l'utilisateur
        Ecrit dans le fichier de l'utilisateur ses résultats
        """
        info = "- Utilisateur : "+str(self.num_util)+"\n - Nombre erreurs : "+str(self.error)
        print(info)
        #message = QMessageBox.information(self,"Resultats",info)
        empty = True
        with open(self.fileL) as f:
            readL = reader(f)
            for r in readL:
                if(r == ['Utilisateur', 'Methode', 'Densite', 'Taille', 'Num cbile', 'Temps', 'Correct']):
                    empty = False
        self.writerLog = writer(self.fileLog)
        if (empty):
            self.writerLog.writerow(["Utilisateur","Methode","Densite","Taille","Num cbile","Temps","Correct"])
        self.writerLog.writerows(self.log)
        self.fileLog.flush()
        self.fileLog.close()

    def resetTimer(self):
        """
        Rénitialise le timer
        """
        self.timer = time()