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
6. Le système de l'application affiche la liste des livres grâce à un recyclerview, et
- 2 boutons :
  * Scanner
  * Envoyer
7. Emma clique sur le bouton Scanner, l'application ouvre une activity affichant différent choix de scan :
  * scan par code barre
  * reconnaissance de texte
  * reconnaissance d'image
8. [Emma choisit d'utiliser la méthode de scan par code barre]
9. Emma dispose les livres sur une surface place (une table par exemple) et procède au scan des livres
10. Dès que Emma a fini de scanner les livres, elle appuye sur le bouton Vérification de l'activity
11. Le système de l'application réaffiche la liste de livres, cependant le background des livres a changé : 'vert' si il a était reconnu sinon 'rouge'
12. [Tous les livres ont été reconnu]
13. Emma appuye sur Envoyer

#### Commentaires :
- faut-il que le serveur informe l'application de la bonne réception et de la réalisation des modifications ? ==> ajout de 5 cas
-

Post-condition : Le système de l'application transmet les livres qui ont été scanné afin de procéder à la modification de leur état dans la base de donnée

Scénario-alternatif :
5. [Les identifiants ne sont pas corrects]
  * 5-1. Le serveur informe le système de l'application que la connexion n'a pas pu se réaliser
  * 5-2. L'application affiche un message (Toast) "L'identifiant entré n'est pas correct"
  * 5-3. Retour à l'étape 2

8. [Emma choisit d'utiliser la méthode de reconnaissance de texte]
  * 8-1. Emma positionne l'appareil de son smartphone au-dessus des titres de chaque livre
  * 8-2. Le système tente de relayer les titres scannés et les titres reçus
  * 8-3. Retour à l'étape 11

8. [Emma choisit d'utiliser la méthode de reconnaissance d'image]
  * 8-1. Emma positionne l'appareil de son smartphone au-dessus des titres de chaque livre
  * 8-2. Le système tente de relayer les images scannés et les images reçus
  * 8-3. Retour à l'étape 11

12. [Certains livres n'ont pas été reconnu]
  * 12-1. Le background de certains livres est 'rouge'
  * 12-2. Retour à l'étape 7

Scénario-exception :

3. [L'application n'arrive pas à se connecter au serveur afin d'envoyer les identifiants]

12. [Des livres sont inconnus de la liste]
  * 12-1.
