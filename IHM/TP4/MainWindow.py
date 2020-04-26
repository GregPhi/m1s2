from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from ExpSetup import ExpSetup
from XPManager import XPManager
import os
from csv import *


class MainWindow(QMainWindow):
    """
    Initialise la QMainWindow de l'application : exécute la technique demandée
    """
    def __init__(self,width,height):
        super(QMainWindow,self).__init__()
        self.width = width
        self.height = height
        self.resize(500,400)
        self.dialog = ExpSetup()
        self.setCentralWidget(self.dialog)
        self.buttonDialog = self.dialog.getValidation()
        self.buttonDialog.clicked.connect(self.verfication)

    def verfication(self):
        """
        Dès que toutes les informations importantes ont bien été renseignées crée le Widget
        """
        num_vide = self.dialog.getNumeroUtilisateur().text() == ''
        dens_vide = self.dialog.getDensite().text() == ''
        tai_vide = self.dialog.getTailleCible().text() == ''
        rep_vide = self.dialog.getNbRepetition().text() == ''
        paletteV = QPalette()
        paletteV.setColor(QPalette.Base,Qt.red)
        if (num_vide):
            self.dialog.getNumeroUtilisateur().setPalette(paletteV)
        if (dens_vide):
            self.dialog.getDensite().setPalette(paletteV)
        if (tai_vide):
            self.dialog.getTailleCible().setPalette(paletteV)
        if (rep_vide):
            self.dialog.getNbRepetition().setPalette(paletteV)
        if (not num_vide and not dens_vide and not tai_vide and not rep_vide):
            self.createWidget()

    def createWidget(self):
        """
        Lance l'application après avoir récupéré les informations rentrées par l'utilisateur
        """
        num_util = int(self.dialog.getNumeroUtilisateur().text())
        tech = self.dialog.getTechnique().currentText()
        nb_densite = int(self.dialog.getDensite().text())
        nb_taille_cible = int(self.dialog.getTailleCible().text())
        nb_repet = int(self.dialog.getNbRepetition().text())

        xp = XPManager(self.width,self.height,num_util,tech,nb_densite,nb_taille_cible,nb_repet)
        technique = xp.manager()
        technique.signal.connect(self.quit)

        r = self.geometry()
        r.setX(100)
        r.setY(100)
        self.setGeometry(r)

        self.resize(self.width,self.height)
        self.setCentralWidget(technique)
        self.show()

    def quit(self):
        """
        Quitte l'application
        """
        self.close()
