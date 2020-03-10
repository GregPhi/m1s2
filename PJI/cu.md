# Description Cas d'Utilisation

### Identification :

Nom du cas : Utilisation de l'application, afin d'ajouter un / des livre(s) par SCAN

But : détaille les étapes permettant à un utilisateur d'ajouter des livres à la base de donnée

Acteur principal : utilisateur (Bob)

### Fonctionnement :

Déclenchement : Le cas commence lorsque l'utilisateur lance l'application

Pré-condition : L'utilisateur est un parent d'élève appartenant à l'association et l'utilisateur a autorisé l'application à utiliser son appareil photo et réaliser des "connexions internets"

Scénario-nominal :
1. Bob ouvre l'application et y indique son identifiant, puis valide
2. Le système de l'application transmet les informations au serveur ("Back-Office")
3. Le serveur vérifie les informations
4. [Les identifiants sont corrects] Le serveur informe le système de l'application que les identifiants sont corrects
5. Le système de l'application informe que l'Activity à afficher c'est celle qui permet à l'utilisateur de choisir la méthode afin d'aouter un / des livres
6. L'application affiche
- 4 boutons :
  * Ajout par scan
  * Ajout en rentrent manuellement le code barre
  * Ajout en rentrant manuellement les informations du livre
  * Envoi des livres à ajouter à la base de donnée
- un recyclerview des livres en cours d'ajout
7. Bob choisit d'ajouter un livre [Ajout par scan]
8. L'application affiche une nouvelle activity comportant
- 2 boutons :
  * Scanner
  * Valider
- un textview qui affichera le code barre scanné
9. Bob clique sur Scanner
10. Le système de l'application remplace l'activity courante grâce à un IntentIntegrator
11. Dès que l'application a détecté le code barre, il retourne vers l'activity en y affichant le code barre
12. [Le code barre est correct] Bob clique sur Valider
13. Le système de l'application va effectué une requête afin de récupérer les informations du livre (grâce à l'utilisation de l'API Google Book)
14. Après avoir récupéré un JSON où se trouve les informations du livre scanné, le système va parser les informations afin d'obtenir un nouveau livre, le JSON est supprimé
15. L'application affiche une activity comportant
  * le titre
  * le code barre
  * la matière
  * le niveau
  * l'état du livre (initialisé <A PRETER>)
  * l'image de couverture
  * un bouton -> Ajouter
16. Bob complète les informations manquantes
17. Bob clique sur Ajouter
18. [Toutes les informations importantes sont rentrées] Le système ajoute le nouveau livre dans une liste qui sera envoyé au serveur
19. Retour à l'étape 6
20. Bob clique sur Envoi des livres à ajouter à la base de données

Post-condition : L'application transmet les nouveaux livres au serveur

Scénario-alternatif :

4. [Les identifiants ne sont pas corrects]
  * 4-1. Le serveur informe le système de l'application que la connexion n'a pas pu se réaliser
  * 4-2. L'application affiche un message (Toast) "L'identifiant entré n'est pas correct"
  * 4-3. Retour à l'étape 1

7. [Ajout en rentrant manuellement le code barre]
  * 7-1. Etape 13

7. [Ajout en rentrant manuellement les informations du livre]
  * 7-1. Etape 15

12. [Le code barre est incorrect]
  * 12-1. Retour à l'étape 9

18. [Il manque des informations afin d'ajouter le livre]
  * 18-1 Retour à l'étape 16

Scénario-exception :

8. [Problème lors de l'utilisation de l'appareil photo]
  * 8-1. Fermer l'application
  * 8-2. Se rendre dans les paramètres de son smartphone
  * 8-3. Autoriser l'utilisation de l'appareil photo pour cette application
  * 8-4. Retour à l'étape 1

 9. [Problème lors de l'utilisation de l'appareil photo]
  *  9-1. Fermer l'application
  *  9-2. Se rendre dans les paramètres de son smartphone
  *  9-3. Autoriser l'utilisation de l'appareil photo pour cette application
  *  9-4. Retour à l'étape 1
