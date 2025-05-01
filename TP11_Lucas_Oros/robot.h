#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>

using namespace std;

typedef enum TypeCouleur {ROUGE, VERT, BLEU, JAUNE}; //permet de definir les 4 couleurs possibles

/**
 * @brief Classe Robot
 * 
 * Objectif : Creer une classe Robot qui represente un robot sur un plateau de jeu
 * 
 * Attributs : 
 * - x : position x du robot sur le plateau
 * - y : position y du robot sur le plateau
 * - couleur : couleur du robot #permet de dinstinguer les 4 robots
 * nombre_de_deplacements : nombre de deplacements effectues par le robot
 * 
 * Methodes :
 * - constructeur sans parametre
 * - constructeur a partir de parametres x, y
 * 
 * - getX() : retourne la position x du robot
 * - getY() : retourne la position y du robot
 * - get_couleur() : retourne la couleur du robot
 * - get_couleur_nom() : retourne le nom de la couleur du robot (string)
 * - get_nombre_de_deplacements() : retourne le nombre de deplacements effectues par le robot
 * - positionOccupee(int nx, int ny, const vector<Robot*> &robots) : verifie si une position est occupee par un autre robot
 * - déplacement(string direction, const vector<Robot*> &robots) : deplace le robot sur le plateau (haut, bas, gauche, droite) jusqu'à obstacle

 * 
 * 
 */

class Robot{
protected:          //attributs sont accessibles par les classes filles (heritage)
    int x; //abscisse du robot
    int y; //ordonnee du robot
    TypeCouleur couleur; //couleur du robot #permet de dinstinguer les 4 robots
    int nombre_de_deplacements; //nombre de deplacements effectues par le robot


public:
    //constructeur a partir de parametres limites du plateau
    Robot();

    //constructeur a partir de parametres x, y, couleur et nombre_de_deplacements
    Robot(int x, int y, TypeCouleur c, int nombre_de_deplacements = 0); 

    //accesseurs x
    int getX() const; //const dire que les attributs ne sont pas modifies

    //accesseurs y
    int getY() const; //const dire que les attributs ne sont pas modifies

    //accesseurs couleur
    TypeCouleur getCouleur() const; //const dire que les attributs ne sont pas modifies

    //accesseurs couleur nom
    string getCouleurNom() const; //const dire que les attributs ne sont pas modifies

    //accesseurs nombre_de_deplacements
    int getNombreDeDeplacements() const; //const dire que les attributs ne sont pas modifies

    //position occupee par un autre robot
    bool positionOccupee(int nx, int ny, const vector<Robot*> &robots); //verifie si une position est occupee par un autre robot

    //deplacement
    void deplacement(string direction, const vector<Robot*> &robots); //deplace le robot sur le plateau (haut, bas, gauche, droite) jusqu'à obstacle
};