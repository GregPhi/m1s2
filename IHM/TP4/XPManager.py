import sys
from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from random import *
from MainGenerator import *
from RopeWidget import RopeWidget
from NormalWidget import NormalWidget
from BubbleWidget import BubbleWidget
from csv import writer
import os

class XPManager():
    """

    """
    def __init__(self,width,height,num_util,technique,densite,taille,nb_repet):
        self.width = width
        self.height = height
        self.num_util = num_util
        self.technique = technique
        self.densite = densite
        self.taille = taille
        self.nb_repet = nb_repet

    def manager(self):
        """
        Génère les targets qui seront utilisés par les Widgets
        """
        pathGenPoints = "target" + str(self.densite) + "_" + str(self.taille) + ".csv"
        pathRandPoints = "targetRand" + str(self.densite) + "_" + str(self.taille) + ".csv"
        if(not os.path.exists(pathGenPoints) and not os.path.exists(pathRandPoints)):
            # 30 -> l'espace entre les points
            generatorCSV(pathGenPoints,pathRandPoints,self.width,self.height,self.densite,self.taille,30)
        if(self.technique == "Bubble"):
            technique = BubbleWidget(self.num_util,self.nb_repet,self.taille,self.densite,pathGenPoints,pathRandPoints)
        elif(self.technique == "Normal"):
            technique = NormalWidget(self.num_util,self.nb_repet,self.taille,self.densite,pathGenPoints,pathRandPoints)
        elif(self.technique == "Rope"):
            technique = RopeWidget(self.num_util,self.nb_repet,self.taille,self.densite,pathGenPoints,pathRandPoints)
        return technique

