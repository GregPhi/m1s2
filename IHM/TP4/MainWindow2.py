from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from ExpSetup import ExpSetup
from XPManager import XPManager
from random import shuffle

class MainWindow2(QMainWindow):
    """
    Initialise la QMainWindow de l'application : exécute une liste de techniques prédéfinies
    """
    def __init__(self,*args):
        super(QMainWindow,self).__init__()
        self.width = args[0][0]
        self.height = args[0][1]
        self.cpt = 0
        self.xp = list()
        self.technique = None
        if(len(args[0])==3):
            self.num_util = args[0][2]
            self.createWidget()
        else:
            self.resize(500,400)
            self.dialog = ExpSetup()
            self.setCentralWidget(self.dialog)
            self.buttonDialog = self.dialog.getValidation()
            self.buttonDialog.clicked.connect(self.verfication)

    def verfication(self):
        """
        Dès que l'utilisateur a rentré son numéro d'utilisateur lance la création du Widget
        """
        num_vide = self.dialog.getNumeroUtilisateur().text() == ''
        palette = QPalette()
        palette.setColor(QPalette.Base,Qt.red)
        if (num_vide):
            self.dialog.getNumeroUtilisateur().setPalette(palette)
        else:
            self.num_util = self.dialog.getNumeroUtilisateur().text()
            self.createWidget()

    def createWidget(self):
        """
        Initialise la liste des techniques qui seront exécutées au fur et à mesure
        """
        self.xp.append(XPManager(self.width, self.height, self.num_util, "Bubble", 90, 18, 30).manager())
        self.xp.append(XPManager(self.width, self.height, self.num_util, "Normal", 90, 18, 30).manager())
        self.xp.append(XPManager(self.width, self.height, self.num_util, "Rope", 90, 18, 30).manager())

        self.xp.append(XPManager(self.width, self.height, self.num_util, "Bubble", 90, 6, 30).manager())
        self.xp.append(XPManager(self.width, self.height, self.num_util, "Normal", 90, 6, 30).manager())
        self.xp.append(XPManager(self.width, self.height, self.num_util, "Rope", 90, 6, 30).manager())

        self.xp.append(XPManager(self.width, self.height, self.num_util, "Bubble", 30, 18, 30).manager())
        self.xp.append(XPManager(self.width, self.height, self.num_util, "Normal", 30, 18, 30).manager())
        self.xp.append(XPManager(self.width, self.height, self.num_util, "Rope", 30, 18, 30).manager())

        self.xp.append(XPManager(self.width, self.height, self.num_util, "Bubble", 30, 6, 30).manager())
        self.xp.append(XPManager(self.width, self.height, self.num_util, "Normal", 30, 6, 30).manager())
        self.xp.append(XPManager(self.width, self.height, self.num_util, "Rope", 30, 6, 30).manager())

        #shuffle(self.xp)

        self.technique = self.xp[self.cpt]
        self.technique.signal.connect(self.next)

        r = self.geometry()
        r.setX(100)
        r.setY(100)
        self.setGeometry(r)

        self.resize(self.width,self.height)
        self.setCentralWidget(self.technique)
        self.show()

    def next(self):
        """
        Sélectionne la technique suivante tant qu'il y en a
        """
        if(self.cpt < len(self.xp)-1):
            self.cpt += 1
            self.xp[self.cpt].resetTimer()
            self.xp[self.cpt].signal.connect(self.next)
            self.setCentralWidget(self.xp[self.cpt])
        else:
            self.close()
