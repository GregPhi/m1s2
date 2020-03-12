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
2. Emma ouvre l'application et indique l'identifiant associé à Louis
3. Le système de l'application transmet les informations au serveur ("Back-Office")
4. Le système vérifie les informations
5. Le système affiche la liste des livres à rendre et plusieurs choix pour valider les livres (code barre, text, image, entré manuelle ...)
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
