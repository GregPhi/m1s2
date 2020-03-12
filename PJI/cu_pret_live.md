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
6. Le système de l'application affiche la liste des livres grâce à un recyclerview, et- 2 boutons :
  * Scanner
  * Envoyer
7. Emma clique sur le bouton Scanner, l'application ouvre une activity affichant différent choix de scan :
  * scan par code barre
  * reconnaissance de texte
  * reconnaissance d'image
  * entrée manuelle
8. [Emma choisit d'utiliser la méthode de scan par code barre]
9. Emma dispose les livres sur une surface place (une table par exemple) et procède au scan des livres
10. Dès que Emma a fini de scanner les livres, elle appuye sur le bouton Vérification de l'activity
11. Le système de l'application réaffiche la liste de livres, cependant le background des livres a changé : 'vert' si il a était reconnu sinon 'rouge'
12. [Tous les livres ont été reconnu]
13. Emma appuye sur Envoyer

Post-condition : Le système de l'application transmet les livres qui ont été scanné afin de procéder à la modification de leur état dans la base de donnée

#### Commentaires :
- faut-il que le serveur informe l'application de la bonne réception et de la réalisation des modifications ? ==> ajout de 5 cas
- l'application doit-elle envoyer des logs des opérations réalisées lorsque l'utilisateur se déconnecte ?

Scénario-alternatif :

5. [Les identifiants ne sont pas corrects]
  * 5-1. Le serveur informe le système de l'application que la connexion n'a pas pu se réaliser
  * 5-2. L'application affiche un message (Toast) "L'identifiant entré n'est pas correct"
  * 5-3. Retour à l'étape 2

A : 8. [Emma choisit d'utiliser la méthode de reconnaissance de texte]
  * 8-1. Emma positionne l'appareil de son smartphone au-dessus des titres de chaque livre
  * 8-2. Le système tente de relayer les titres scannés et les titres reçus
  * 8-3. Retour à l'étape 11

B : 8. [Emma choisit d'utiliser la méthode de reconnaissance d'image]
  * 8-1. Emma positionne l'appareil de son smartphone au-dessus des titres de chaque livre
  * 8-2. Le système tente de relayer les images scannés et les images reçus
  * 8-3. Retour à l'étape 11

C : 8. [Emma choisit d'utiliser la méthide rentrée manuelle]
  * 8-1. Le système affiche des champs à remplir
  * 8-2. Le système vérifie qu'il exsite bien un livre correspondant dès qu'Emma appuye sur le bouton Vérifier
  * 8-3. [Tous les champs sont remplis]
  * 8-4. [Les informations sont corrects]
  * 8-5. Le livre s'ajoute à la liste des livres scannés
  * 8-6. Retour à l'étape 8-1, tant qu'il y a des livres à prêter
  * 8-7. Retour à l'étape 10

8-3 [Certains champs ne sont pas remplis]
  * 8-3-1. Le sytème affiche un message afin de prévenir Emma qu'il manque des informations nécessaires
  * 8-3-2. Retour à l'tape C : 8-1, en complétant les champs déjà renseignés

8-4 [Certaines informations sont incorrectes]
  * 8-4-1. Retour à l'étape C : 8

12. [Il manque des livres]
  * 12-1. Emma informe le système que certains sont manquants
  * 12-2. Retour à l'étape 13

Scénario-exception :

3. [L'application n'arrive pas à se connecter au serveur afin d'envoyer les identifiants]
  * 3-1. Emma vérifie la connexion
  * 3-2. Retour à l'étpae 1

12. [Des livres sont inconnus de la liste]
  * 12-1. Le système de l'application informe le serveur qu'il faudrait créer de nouveau livre dans la base de donnée
  * 12-2. Retour à l'étape 13.
##### Commentaires :
- faut-il permettre à l'utilisateur de pouvoir créer une fiche temporaire ? ou directement créer le nouveau livre ?
- des logs doivent-elles être envoyées lors d'une telle erreur ?
