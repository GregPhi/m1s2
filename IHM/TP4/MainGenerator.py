import sys
from random import *
from math import sqrt
import os

def generatorCSV(pathGenPoints,pathRandPoints,width,height,nb_cible,taille_cible,espace_e_cible):
    """
    Génere un fichier CSV contenant des bulles.
    parameters:
    name_file (str) - nom du fichier CSV (peut contenir un chemin suivi du nom)
    width (int) - largeur maximale en x des coordonnées
    height (int) - largeur maximale en y des coordonnées
    nb_cible (int) - nombre de bulles à générer
    taille_cible (int) - diamètre maximale des bulles
    espace_e_cible (int) - distance minimale séparant les bulles
    """
    fileGen = open(pathGenPoints,'w')
    fileRand = open(pathRandPoints,'w')
    donnee = list()

    for i in range(int(nb_cible)):
        test = generatePoint(width,height,taille_cible)
        if(len(donnee)==0):
            donnee.append(test)
        else:
            while(not(goodAdd(donnee,test,espace_e_cible))):
                test = generatePoint(width,height,taille_cible)
            donnee.append(test)

    for d in donnee:
        texte = str(d[0])+","+str(d[1])+","+str(d[2])+"\n"
        fileGen.write(texte)

    shuffle(donnee)
    for d in donnee:
        texte = str(d[0])+","+str(d[1])+","+str(d[2])+"\n"
        fileRand.write(texte)

    fileRand.flush()
    fileRand.close()
    fileGen.flush()
    fileGen.close()

def generatePoint(width,height,taille_cible):
    """
    Génére des coordonnées et une taille
    parameters:
    width (int) - borne maximale de la coordonnée x
    height (int) - borne maximale de la coordonnée y
    taille_cible (int) - borne maximale du diamètre
    returns:
    tuple - les coordonnées et une taille dans leur borne respective
    """
    x = randrange(width)
    y = randrange(height)
    size = taille_cible
    return (x,y,size)

def goodAdd(donnees,test,espace_e_cible):
    """
    Retourne si une bulle (test) respecte les conditions de distance (espace_e_cible) avec toutes le autres bulles (donnees)
    parameters:
    données (iterable) - données itérables contenant des tuples (x,y,size)
    test (tuple) - point à vérifier
    espace_e_cible (int) - distance à respecter entre test et les bulles dans données
    returns:
    boolean - True si test respect la distance avec tous les points dans données, False sinon
    """
    ok = True
    for d in donnees:
        distance = sqrt(abs((d[0] - test[0]))**2+(abs(d[1] - test[1]))**2)
        if(espace_e_cible > distance-(d[2]+test[2])/2):
            ok = False
            break
    return ok

def main(args):
    """
    Main pour vérifier la génération des bulles
    """
    if(len(args)==8):
        generatorCSV(args[1],args[2],int(args[3]),int(args[4]),int(args[5]),int(args[6]),int(args[7]))
    else:
        print("FALSE")

if __name__ == "__main__":
    main(sys.argv)
