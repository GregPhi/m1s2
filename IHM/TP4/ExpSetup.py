import sys
from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from random import *
from math import *


class ExpSetup(QDialog):
    """
    Fenêtre de dialogue permettant de sélectionner les paramètres
    """
    def __init__(self):
        super(QDialog,self).__init__()
        self.initWidgets()
        self.initLayout()

    def initWidgets(self):
        """
        Crée les widgets de la fenêtre de dialogue
        """
        self.num_util = QLineEdit(self)
        self.tech = QComboBox(self)
        self.tech.addItem("Bubble")
        self.tech.addItem("Rope")
        self.tech.addItem("Normal")
        self.nb_densite = QLineEdit(self)
        self.nb_taille_cible = QLineEdit(self)
        self.nb_repet = QLineEdit(self)
        self.button_valid = QPushButton("Validation")

    def initLayout(self):
        """
        Crée le layout de la fenêtre
        """
        self.layout = QFormLayout()
        self.layout.addRow("Numéro d'utilisateur", self.num_util)
        self.layout.addRow("Technique", self.tech)
        self.layout.addRow("Densités", self.nb_densite)
        self.layout.addRow("Taille maximale des cibles", self.nb_taille_cible)
        self.layout.addRow("Nombre de répétitions", self.nb_repet)
        self.layout.addRow(self.button_valid)
        self.setLayout(self.layout)

    def getNumeroUtilisateur(self):
        """
        Retourne la QLineEdit concernant le numero de l'utilisateur
        returns:
        QLineEdit - le numéro de l'utilisateur
        """
        return self.num_util

    def getTechnique(self):
        """
        Retourne la QComboBox concernant la technique que l'utilisateur veut utiliser
        returns:
        QComboBox - technique à instancier
        """
        return self.tech

    def getDensite(self):
        """
        Retourne la QLineEdit concernant la densité de points
        returns:
        QLineEdit - nombre de points
        """
        return self.nb_densite

    def getTailleCible(self):
        """
        Retourne la QLineEdit concernant la taille des cibles
        returns:
        QLineEdit - taille des cibles
        """
        return self.nb_taille_cible

    def getNbRepetition(self):
        """
        Retourne la QLineEdit concernant le nombre de fois où l'utilisateur va devoir cliquer sur/près une cible
        returns:
        QLineEdit - nombre de clique
        """
        return self.nb_repet

    def getValidation(self):
        """
        Retourne la QPushButton concernant le numero de l'utilisateur
        returns:
        QPushButton - le bouton de validation
        """
        return self.button_valid
