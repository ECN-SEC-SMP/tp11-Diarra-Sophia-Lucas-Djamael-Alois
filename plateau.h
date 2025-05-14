#ifndef PLATEAU_H
#define PLATEAU_H

#include <string>
#include <vector>
#include <utility>
#include "robot.h"
#include "Tuile_objectif.h"

class Robot; /**< Déclaration anticipée (forward declaration) */

/**
 * @enum Element_Grille
 * @brief Enumération des différents éléments possibles sur la grille du plateau.
 */
typedef enum
{
    VIDE = 0,     /**< Case vide */
    NON_VIDE = 1, /**< Case non vide */
    VOITURE = 2,  /**< Case contenant une voiture */
    TUILE = 3,    /**< Case contenant une tuile */
    MUR = 4       /**< Case contenant un mur */
} Element_Grille;

/**
 * @class Plateau
 * @brief Classe représentant le plateau de jeu.
 * Cette classe gère l'état du plateau, l'ajout des éléments (robots, murs, tuiles, etc.) et l'affichage du plateau.
 */
class Plateau
{
private:
    int grille[32][32]; /**< La grille du plateau de jeu, une matrice 32x32 */

public:
    /**
     * @brief Constructeur de la classe Plateau.
     * Initialise un plateau vide avec une grille de 32x32 cases.
     */
    Plateau();

    /**
     * @brief Place un robot sur le plateau.
     * @param robot Un pointeur vers l'objet robot à placer sur le plateau.
     */
    void placerRobot(Robot *robot);

    /**
     * @brief Affiche le plateau de jeu.
     * Affiche l'état actuel de la grille du plateau dans la console.
     */
    void afficherPlateau();

    /**
     * @brief Place un mur à une position donnée avec une orientation spécifiée.
     * @param x La coordonnée x de la position du mur.
     * @param y La coordonnée y de la position du mur.
     * @param orientation L'orientation du mur (par exemple, "horizontal" ou "vertical").
     */
    void placerMur(int x, int y, string orientation);

    /**
     * @brief Ajoute des murs dans les différents quadrants du plateau.
     * Cette fonction ajoute des murs à des positions spécifiques du plateau.
     */
    void ajouterMursQuadrants();

    /**
     * @brief Place un angle (ex. un virage) sur le plateau.
     * @param row La ligne où placer l'angle.
     * @param col La colonne où placer l'angle.
     * @param orientation L'orientation de l'angle (par exemple, "haut-gauche").
     * @return True si l'angle a été placé avec succès, sinon false.
     */
    bool placerAngle(int row, int col, const string &orientation);

    /**
     * @brief Ajoute des angles dans les différents quadrants du plateau.
     * Cette fonction ajoute des angles (par exemple, des virages) dans les quadrants du plateau.
     */
    void ajouterAnglesQuadrants();

    /**
     * @brief Retourne les coordonnées des cases ayant une valeur spécifiée.
     * @param valeur La valeur à rechercher sur la grille du plateau.
     * @return Un vecteur de paires représentant les coordonnées des cases correspondantes.
     */
    vector<pair<int, int>> getCoordonneesCases(int valeur) const;

    /**
     * @brief Place les tuiles objectifs sur le plateau.
     * @param tuilesPlacees Un vecteur de tuiles à placer sur le plateau.
     */
    void placerTuilesObjectif(vector<Tuile_objectif> &tuilesPlacees);

    /**
     * @brief Met à jour l'état du plateau en fonction des positions des robots.
     * @param robots Un vecteur contenant les robots présents sur le plateau.
     */
    void majPlateau(const std::vector<Robot *> &robots);

    /**
     * @brief Retourne la valeur de la case à une position donnée.
     * @param i La coordonnée de la ligne.
     * @param j La coordonnée de la colonne.
     * @return La valeur de la case à la position (i, j).
     */
    int& getGrille(int i, int j);
};

#endif