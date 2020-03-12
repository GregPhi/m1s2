# Description Cas d'Utilisation

### Identification :

Nom du cas : Utilisation de l'application, afin de gérer le prêt de livres à un élève

But : détaille les étapes permettant à un utilisateur de lister des livres à prêter

Acteur principal :  élève (Etienne) && utilisateur [membre de l'association des parents d'élèves] (Emma)

### Fonctionnement :

Déclenchement : Le cas commence lorsque l'utilisateur lance l'application

Pré-condition : L'utilisateur est un parent d'élève appartenant à l'association et l'utilisateur a autorisé l'application à utiliser son appareil photo et réaliser des "connexions internets"

Scénario-nominal :
1. Etienne arrive afin de récupérer ses livres
2. Emma ouvre l'application, y identique ses identifiants et demande la liste des livres associés à Etienne
3. Le système de l'application transmet les informations au serveur ("Back-Office")
4. Le système vérifie les informations
5. [Les identifiants sont corrects] Le serveur informe le système de l'application que les identifiants sont corrects et transmet la liste des livres qui doivent être prêté à Etienne
6. Le système de l'application affiche la liste des livres grâce à un recyclerview

Post-condition : L'application transmet la liste des livres prêtés au serveur

Scénario-alternatif :
5. [Les identifiants ne sont pas corrects]
  * 5-1. Le serveur informe le système de l'application que la connexion n'a pas pu se réaliser
  * 5-2. L'application affiche un message (Toast) "L'identifiant entré n'est pas correct"
  * 5-3. Retour à l'étape 1

Scénario-exception :
