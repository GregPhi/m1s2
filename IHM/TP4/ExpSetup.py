import sys
from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from random import *
from math import *

class ExpSetup(QDialog):
    def __init__(self):
        super(QDialog,self).__init__()
        self.num_util = QLineEdit(self)
        self.tech = QComboBox(self)
        self.tech.addItem("Highlight")
        self.tech.addItem("Bubble")
        self.tech.addItem("Rope")
        self.tech.addItem("Normal")
        self.nb_densite = QLineEdit(self)
        self.nb_taille_cible = QLineEdit(self)
        self.nb_repet = QLineEdit(self)
        self.button_valid = QPushButton("Validattion")
        self.button_valid.clicked.connect(self.buttonValide)

        self.layout = QVBoxLayout()
        self.layout.addWidget(self.num_util)
        self.layout.addWidget(self.tech)
        self.layout.addWidget(self.nb_densite)
        self.layout.addWidget(self.nb_taille_cible)
        self.layout.addWidget(self.nb_repet)
        self.layout.addWidget(self.button_valid)
        self.setLayout(self.layout)

    def buttonValide(self):
        num_util = self.num_util.text()
        if(num_util!=''):
            num_util = int(num_util)
        tech = self.tech.currentText()
        nb_densite = self.nb_densite.text()
        if(nb_densite!=''):
            nb_densite = int(nb_densite)
        nb_taille_cible = self.nb_taille_cible.text()
        if(nb_taille_cible!=''):
            nb_taille_cible = int(nb_taille_cible)
        nb_repet = self.nb_repet.text()
        if(nb_repet!=''):
            nb_repet = int(nb_repet)
        test = (num_util,tech,nb_densite,nb_taille_cible,nb_repet)
        print(test)

def generatorCSV(name_file,taille_x,taille_y,nb_cible,taille_cible,espace_e_cible):
    file = open(name_file,'w')
    donnee = list()

    for i in range(nb_cible):
        test = generatePoint(taille_x,taille_y,taille_cible)
        if(len(donnee)==0):
            donnee.append(test)
        else:
            while(not(goodAdd(donnee,test,espace_e_cible))):
                test = generatePoint(taille_x,taille_y,taille_cible)
            donnee.append(test)

    for d in donnee:
        texte = str(d[0])+","+str(d[1])+","+str(d[2])+"\n"
        file.write(texte)
    file.flush()
    file.close()

def generatePoint(taille_x,taille_y,taille_cible):
    x = randrange(taille_x)
    y = randrange(taille_y)
    size = randrange(taille_cible)
    return (x,y,size)

def goodAdd(donnee,test,espace_e_cible):
    ok = True
    for d in donnee:
        distance = sqrt(abs((d[0] - test[0]))**2+(abs(d[1] - test[1]))**2)
        if(espace_e_cible > distance-(d[2]+test[2])/2):
            ok = False
            break
    return ok
