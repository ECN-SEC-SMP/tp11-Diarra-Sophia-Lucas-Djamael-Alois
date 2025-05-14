/**
 * @file Jeu.h
 * @brief Déclaration de la classe Jeu, qui gère la logique principale du jeu.
 */

#include "plateau.h"
#include "robot.h"
#include "sablier.h"
#include "joueur.h"
#include "Tuile_objectif.h"

#ifndef JEU_H
#define JEU_H

/**
 * @class Jeu
 * @brief Classe représentant l'ensemble du jeu : le plateau, les joueurs, les robots et les objectifs.
 */

class Jeu
{
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
    /**
     * @brief Constructeur par défaut de la classe Jeu.
     */
    Jeu();

    /**
     * @brief Initialise la liste des joueurs.
     *
     * Demande à l'utilisateur de renseigner les informations nécessaires.
     */
    void set_Joueurs();

    /**
     * @brief Permet à un joueur d'annoncer une solution.
     *
     * Cette fonction est appelée lorsqu'un joueur pense avoir trouvé une solution.
     */
    void annoncer_Solution();

    /**
     * @brief Permet au joueur ayant annoncé la solution de la proposer en détail.
     *
     * Cette fonction est utilisée pour vérifier si le joueur avait raison.
     */
    void proposer_Solution();

    /**
     * @brief Tire une nouvelle tuile objectif aléatoire.
     *
     * Cette tuile devient la nouvelle cible des joueurs.
     */
    void tirer_tuile_objectif();

    /**
     * @brief Valide si un joueur a bien trouvé la bonne solution.
     *
     * @param NomJoueur Nom du joueur qui propose la solution.
     * @return true si la solution est correcte, false sinon.
     */
    bool valider_solution(string NomJoueur);

    /**
     * @brief Affiche la légende du plateau pour aider les joueurs à comprendre les éléments présents.
     */
    void afficherLegendePlateau();
};
#endif