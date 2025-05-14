# TP projet: Ricochet Rebot
## Introduction                                      
Ce projet s'inscrit dans le cadre du module de **spécification et modélisation de programme**. L'objectif principal est d'implémenter le jeu *RICOCHET ROBOT* en utilisant l'ensemble des concepts liés à la programmation orientée objet. Les principales compétences visées sont: le développement de l'esprit de travail collectif, faire des choix de conception et mobiliser les aspects du cours théorique dans un cadre pratique.
## Organisation du travail
Nous sommes cinq personnes à avoir réalisé ce projet: Alois, Diarra, Djamael, Lucas et Sophia. Nous nous sommes répartis le travail en fonction des choix de conception que nous avons fait. La répartition des taches sera mentionnée dans la prochaine partie.
A travers ce projet, nous avons mobilisé plusieurs outils: des outils de versionning comme **GIT**, **GITHUB**, des outils de conception comme **l'UML**, des outils de travail collaboratif comme **EXCALIDRAW**. Le langage utilisé pour l'implémentatio est le **C++**.

## Choix de conception
La première étape est la conception du jeu en lui-meme. Pour cela, nous avons commencé par faire un travail collaboratif consistant à réaliser le diagramme des cas d'utilisation afin de cerner les différentes fonctionnalités du jeu, les acteurs et de définir les limites du système. Ci-dessous le diagramme des use case réalisé.
![image](https://github.com/user-attachments/assets/97647664-0b65-418f-91c1-23e8b72ea4f6)
Une fois cette première partie terminée, nous avons réalisé un diagramme de classe. Ce qui nous a permis d'opérer des choix de conception. Nous avons, en effet, analysé le principe de fonctionnement du jeu et décidé de créer différentes classes d'objet selon leur importance dans l'otique d'avoir une méthode d'implémentation la plus facile possible. A cet effet, nous avons créé une classe principale **Jeu** autour de laquelle s'articule tout le projet. Elle est responsable de la gestion du jeu: l'initialisation des robots, des tuiles et du plateau, la gestion du temps... Par soucis d'optimisation, nous avons créé d'autres classes qui se chargeront de faire certaines des activités de la classe Jeu. C'est-à-dire que la classe Jeu va déléguer certaines de ses activités aux classes: **Plateau, Robot, Tuile objectif** qui ont une exitence autonome d'ou la relation d'agrégation. Le jeu n'a pas de nombre de joueurs fixé. 
Ci-dessous le diagramme de classes réalisé.
![image](https://github.com/user-attachments/assets/49da5d23-56ae-4df8-9e17-ee8e433d21e1)
Ces deux premières étapes nous ont permis de procéder à l'organisation des taches de chacun.
| Classe     | Jeu       | Plateau | Robot | Tuile obejctif | Sablier |
|------------|-----------| ------- | ----- | -------------- | --------|
| Responsable| Diarra    | Sophia  | Lucas | Djamael        | Alois   |


Pour faire le versionning du code, nous avons choisi de separer le projet en plusieurs branches: une branche principale sur laquelle on push la bonne version du code et plusieurs branches secondaires pour chacune des classes.
La méthode consistera à implementer chacune des classes  tout en prenant en compte le referentiel defini en amont pour facilter les tests. En effet, travailler directement sur la branche principale rendrait les tests impossibles et l'usage de Git n'aurait pas de sens.

## Déroulement du projet
 ### Planning
 A l'issu de la première séance, nous avons définis le plan à suivre pour l'implémentation du projet. La deuxième séance a permis d'implémenter et/ou ajuster les différentes classes du jeu. Les délais ont été respectés.
 
 ### Difficultés rencontrées
Globalement, le projet s'est bien déroulé, il n'y a pas eu de difficulté particuliere pour la gestion du travail du groupe. Néanmoins, il a fallu avoir du recul pour s'assurer que tous avaient la meme compréhension du travail à effectuer.
Pour la partie technique, la principale difficulté à laquelle nous nous sommes confrontés était l'usage de l'outil *GIT* car tout le monde ne l'utilisait pas d'habitude. Nous avons réussi à appréhender l'outil et à faire le versionning de notre code en nous entr'aidant et en faisant des recherches sur les bonnes pratiques à avoir. Nous avons également rencontré des conflits sur nos branches que nous sommes arrivés à gérer en procédant à une analyse méticuleuse du code.
![image](https://github.com/user-attachments/assets/7890722a-241e-4a4a-a4a1-3aeaf8abc6cd)
Comme on peut voir sur le diagramme ce n'est pas parfait, mais ça nous a permis d'en apprendre plus sur l'outil Git pour le versionning de code. 

## Résultats obtenus
Nous avons procédé à des tests des différentes méthodes implémentées dans chaque classe. Les résultas obtenus sont satisfaisants.

    ### Exemple de test de la classe Robot

    ### Exemple de test de la classe Plateau
Testée avec "main_test.cpp" avec un faux robot "robot_test" avant l'implémentation avec la vraie classe "robot" : ![image](https://github.com/user-attachments/assets/87af2ba3-1150-48c2-866d-a41863b06c95)
![image](https://github.com/user-attachments/assets/4902649a-b9ce-4a90-82ac-68b919a588be)

    ### Exemple de test de la classe Joueur


    ### Exemple de test de la classe Jeu


    ### Exemple de test de la classe Sablier

    


## Bilan et apprentissages
A l'issu de ce projet, nous avons eu l'occasion de mettre en pratique différents concept de l'approche **classe & objet**, notamment la définition des classes ainsi que les relations entre elles: **délégation( agréagtion, composition) ou héritage**, l'usage des méthodes constantes et des références pour optimiser notre code, ...Nous avons également utilsé des bibliothèques particulières comme **vector** pour définir la meilleure structure pour nos données ou encore **ctime** pour l'usage de fonctions particulières comme rand(). 
Au delà, cela a permis également de réaliser la conception en amont de l'implémentation et donc d'adopter les bonnes pratiques.


## Remarque importante
Suite à une erreur lors d’un `git push --force`, l’historique de la branche `main` a été accidentellement écrasé. 

Pour conserver une trace fidèle du travail collectif effectué tout au long du projet, nous avons restauré l’ancien historique des commits dans une branche dédiée :
[Branche restauration-historique](https://github.com/ECN-SEC-SMP/tp11-Diarra-Sophia-Lucas-Djamael-Alois/tree/restauration-historique)

Elle contient une partie restaurée des contributions individuelles , qui restent consultables sur les branches de chacun.
Merci de bien vouloir en tenir compte dans l’évaluation.


