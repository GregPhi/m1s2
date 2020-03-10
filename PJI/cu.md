# Description Cas d'Utilisation

--- Cas 1 :

### Identification :

Nom du cas : Utilisation de l'application, afin d'ajouter un / des livre(s)

But : détaille les étapes permettant à un utilisateur d'ajouter des livres à la base de donnée

Acteur principal : utilisateur (Bob)

### Fonctionnement :

Déclenchement : Le cas commence lorsque l'utilisateur lance l'application

Pré-condition : L'utilisateur est un parent d'élève appartenant à l'association

Scénario-nominal :
1. Bob ouvre l'application et y indique son identifiant, puis valide
2. Le système de l'application transmet les informations au serveur ("Back-Office")
3. Le serveur vérifie les informations
4. [Les identifiants sont corrects] Le serveur informe le système de l'application que les identifiants sont corrects
5. Le système de l'application informe que l'Activity à afficher c'est celle qui permet à l'utilisateur de choisir la méthode afin d'aouter un / des livres
6. L'application affiche
   - 3 boutons :
  * Ajout par scan
  * Ajout en rentrent manuellement le code barre
  * Ajout en rentrant manuellement les informations du livre
   - un recyclerview des livres en cours d'ajout
7. Bob choisit d'ajouter un livre [Ajout par scan]

Post-condition :

Scénario-alternatif :
4. [Les identifiants ne sont pas corrects]
   4-1. Le serveur informe le système de l'application que la connexion n'a pas pu se réaliser
   4-2. L'application affiche un message (Toast) "L'identifiant entré n'est pas correct"
   4-3. Retour à l'étape 1
7. [Ajout en rentrant manuellement le code barre]
   7-1.
   7-2.
   7-3.
   7-4.
   7-5.
   7-6.  
7. [Ajout en rentrant manuellement les informations du livre]
   7-1. 
   7-2.
   7-3.
   7-4.
   7-5.
   7-6.

Scénario-exception :
