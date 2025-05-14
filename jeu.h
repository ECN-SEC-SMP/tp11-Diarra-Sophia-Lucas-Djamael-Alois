// Created by  on 2025/04/29
#include "plateau.h"
#include "robot.h"
#include "sablier.h"
#include "joueur.h"
#include "Tuile_objectif.h"

#ifndef JEU_H
#define JEU_H

class Jeu {
private:
    Plateau le_plateau;
    vector<Robot> robots;
    vector<Joueur> joueurs;
    Sablier le_sablier;
    int nbr_joueurs;
    Tuile_objectif objectif_actuel;
    Tuile_objectif objectif_courant;
    vector<Tuile_objectif> liste_tuiles_objectifs;

public:
//Constructeurs

Jeu();

//méthodes
void set_Joueurs();

void annoncer_Solution();

void proposer_Solution();

//disposer les differents tokens et afficher le plateau
void initialiser_Jeu();


//generation d'une tuile objectif aleatoire
void tirer_tuile_objectif();

//comparer la solution du joueur actuel avec celle des autres joueurs
bool valider_solution(string NomJoueur);

void afficherLegendePlateau();

//destructeur
~Jeu() {
   //nothing to do here
}
};
#endif // JEU_H