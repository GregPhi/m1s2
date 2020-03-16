# Description Cas d'Utilisation

### Identification :

Nom du cas : Utilisation de l'application lors du rendu des livre

But : étapes permettant à un utilisateur de lister les livre rendus

Acteur principal :  élève (Louis) && utilisateur [membre de l'association des parents d'élèves] (Emma)

### Fonctionnement :

Déclenchement : Le cas commence lorsque l'élève arrive pour rendre ses livres

Pré-condition : Emma appartient à l'association et Louis fait parti de la liste des élèves

Scénario-nominal :
1. Louis arrive pour rendre ses livres
2. Emma ouvre l'application, y identique ses identifiants et demande la liste des livres associés à Louis
3. Le système de l'application transmet les informations au serveur ("Back-Office")
4. Le système vérifie les informations
5. Le système affiche la liste des livres à rendre et plusieurs choix pour valider les livres (code barre, text, image, entrée manuelle ...)
6. Emma choisit une métohde de validation des livres
7. Le système affiche la méthode pour rentrer les informations
8. Emma valide les livres
9. Le systeme verifie les livres.
10. Le système indique les livres manquant
11. Emma appui sur "send"
12. le système renvoie la liste de livre validé au serveur

Post-condition : L'application transmet la liste des livres rendu au serveur

Scénario-alternatif :

4. [l'identifiant n'est pas correcte]
  * 4-1. Le serveur informe le système de l'application que la connexion n'a pas pu se réaliser
  * 4-2. L'application affiche un message "L'identifiant entré n'est pas correct"
  * 4-3. Retour à l'étape 2

10.[il manque des livres]
  * 10.1 Emma appui "commentaire" et écrit les livres qu'il manque
  * 10.2 Emma appui sur "confirmer"
  * 10.3 Etape 11

9.[Le livre n'est pas reconu]



Scénario-exception :

2. [L'application n'arrive pas à se connecter au serveur afin d'envoyer les identifiants]

7. [Problème lors de l'utilisation de l'appareil photo]
  * 8-1. Fermer l'application
  * 8-2. Se rendre dans les paramètres de son smartphone
  * 8-3. Autoriser l'utilisation de l'appareil photo pour cette application
  * 8-4. Retour à l'étape 6


----

DSS
title Rendu d'un livre

Eleve->+Utilisateur : Indique les livres qu'il doit rendre

Utilisateur->+Systeme : Ouvre l'application

loop connexion
    Systeme->+Utilisateur  : Demande les identifiants de l'utilisateur et la liste des livres associés à l'éléève
    Utilisateur->+Systeme : indique les identifiants et la demande
    Systeme->+Serveur : Transmet les idendifiants et la demande
    Serveur-->-Serveur : Vérifie les identifiants
end

Serveur-->-Systeme : Envoi la liste des livres
Systeme-->-Systeme : Affiche les livres
Systeme-->-Utilisateur: Demande l'option que l'utilisateur va utiliser (scan, ...)

loop utilise l'option afin de reconnaitre les livres à rendre
    Utilisateur->+Systeme : effectue la reconnaissance
    Systeme->+Systeme : effectue les modifications du statut du livre reconnu
    Systeme-->-Utilisateur:
end

Utilisateur->+Systeme : indique au systeme la fin de la reconnaissance
Systeme->+Serveur : envoi la listes des livres avec modification de leur statut
Serveur->+Serveur : mets à jour la base de donnée associé à l'élève

Serveur-->-Systeme:
Systeme-->-Utilisateur:
Utilisateur-->-Eleve: lui indique si tous ses livres ont bien été rendus
