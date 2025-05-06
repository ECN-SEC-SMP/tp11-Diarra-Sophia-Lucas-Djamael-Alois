// Created by  on 2025/04/29
#include "Plateau.h"
#include "Robot.h"
#include "sablier.h"
#include "Joueurs.h"
#include "Tuile_objectif.h"


#ifndef JEU_H
#define JEU_H

class Jeu {
private:
    Plateau le_plateau;
    vector<Robot> robots;
    vector<Joueurs> liste_joueurs;
    Sablier le_sablier;
    Tuile_objectif objectif_actuel;
    Tuile_objectif objectif_courant;
    vector<Tuile_objectif> liste_tuiles_objectifs;

public:
//Constructeurs

Jeu();

//méthodes
void set_Joueurs();

//Disposer automatiquement les tuiles dans les angles
void init_position_tuile(int x, int y, char type_tuile);

Jeu::annoncer_Solution()

Jeu::proposer_Solution()

//disposer les differents tokens et afficher le plateau
void initialiser_Jeu();


//generation d'une tuile objectif aleatoire
Tuile_objectif tirer_tuile_objectif();

//comparer la solution du joueur actuel avec celle des autres joueurs
void valider_solution();


//destructeur
~Jeu() {
   //nothing to do here
}
};
#endif // JEU_H