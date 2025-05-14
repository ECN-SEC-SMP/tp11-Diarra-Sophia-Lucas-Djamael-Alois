#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include "Tuile_objectif.h" // Inclusion de la classe Tuile_objectif pour le type Couleur
#include "plateau.h"        // Inclusion de la classe Plateau pour le type Plateau

using namespace std;

class Plateau;

/**
 * @class Robot
 * @brief Représente un robot sur le plateau de jeu.
 *
 * Chaque robot a une position (x, y), une couleur unique, et un compteur de déplacements.
 */

class Robot
{
protected:
    int x;                      ///< Position x du robot sur le plateau
    int y;                      ///< Position y du robot sur le plateau
    TypeCouleur couleur;        ///< Couleur du robot, permet de distinguer les 4 robots
    int nombre_de_deplacements; ///< Nombre de déplacements effectués par le robot

public:
    /**
     * @brief Constructeur par défaut
     */
    Robot();

    /**
     * @brief Constructeur avec paramètres
     * @param x Position x initiale
     * @param y Position y initiale
     * @param c Couleur du robot
     * @param nombre_de_deplacements Nombre initial de déplacements (par défaut 0)
     */
    Robot(int x, int y, TypeCouleur c, int nombre_de_deplacements = 0);

    /**
     * @brief Retourne la position x du robot
     * @return Coordonnée x
     */
    int getX() const; // const dire que les attributs ne sont pas modifies

    /**
     * @brief Retourne la position y du robot
     * @return Coordonnée y
     */
    int getY() const; // const dire que les attributs ne sont pas modifies

    /**
     * @brief Retourne la couleur du robot
     * @return Couleur sous forme d'enum TypeCouleur
     */
    TypeCouleur getCouleur() const; // const dire que les attributs ne sont pas modifies

    /**
     * @brief Retourne le nom de la couleur du robot (sous forme de chaîne)
     * @return Nom de la couleur
     */
    string getCouleurNom() const; // const dire que les attributs ne sont pas modifies

    /**
     * @brief Retourne le nombre de déplacements effectués
     * @return Nombre de déplacements
     */
    int getNombreDeDeplacements() const; // const dire que les attributs ne sont pas modifies

    /**
     * @brief Vérifie si une position est occupée par un autre robot
     * @param nx Coordonnée x à tester
     * @param ny Coordonnée y à tester
     * @param robots Vecteur de pointeurs vers les robots
     * @return true si la position est occupée, false sinon
     */
    bool positionOccupee(int nx, int ny, const vector<Robot *> &robots); // verifie si une position est occupee par un autre robot

    /**
     * @brief Déplace le robot dans une direction donnée jusqu'à rencontrer un obstacle
     *
     * @param direction Direction du déplacement ("haut", "bas", "gauche", "droite")
     * @param robots Vecteur de pointeurs vers les robots (pour éviter les collisions)
     * @param plateau Pointeur vers le plateau (pour gérer les murs)
     */
    void deplacement(string direction, const vector<Robot *> &robots, Plateau *plateau);

    /**
     * @brief Définit la position x du robot
     * @param _X Nouvelle coordonnée x
     */
    void setX(int _X);

    /**
     * @brief Définit la position y du robot
     * @param _Y Nouvelle coordonnée y
     */
    void setY(int _Y);
};

/**
 * @brief Vérifie si une position est libre (aucun robot dessus)
 * @param x Coordonnée x
 * @param y Coordonnée y
 * @param robots Vecteur de robots
 * @return true si la position est libre, false sinon
 */
bool estPositionLibre(int x, int y, const std::vector<Robot> &robots);

/**
 * @brief Crée 4 robots de couleurs différentes à des positions aléatoires sans chevauchement
 * @return Vecteur de robots
 */
vector<Robot> creationRobots();

/**
 * @brief Récupère des pointeurs vers les robots du vecteur
 * @param robots Vecteur de robots
 * @return Vecteur de pointeurs vers les robots
 */
vector<Robot *> getPointers(vector<Robot> &robots);