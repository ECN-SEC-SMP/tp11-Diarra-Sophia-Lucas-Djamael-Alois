// Class Robot

#include "robot.h"
#include <iostream>

using namespace std;


//constructeur sans parametre (position aleatoire dans les limites du plateau)
Robot::Robot(){
    int maxX = 16;
    int maxY = 16;

    x = rand() % maxX; //position aleatoire entre 0 et maxX
    y = rand() % maxY; //position aleatoire entre 0 et maxY

    couleur = ROUGE; //par defaut le robot est rouge
    nombre_de_deplacements = 0; //par defaut le robot n'a pas deplacements
}

//constructeur a partir de parametres x, y, couleur
Robot::Robot(int x, int y, TypeCouleur c, int nombre_de_deplacements){
    this->x = x; //initialiser la position x du robot
    this->y = y; //initialiser la position y du robot
    this->couleur = c; //initialiser la couleur du robot
    this->nombre_de_deplacements = nombre_de_deplacements; //initialiser le nombre de deplacements
}

//accesseurs x
int Robot::getX() const{
    return x;
}

//accesseurs y
int Robot::getY() const{
    return y;
}
void Robot::setX(int _X)
{
    this->x = _X;
}

void Robot::setY(int _Y)
{
    this->y = _Y;
}
//accesseurs couleur
TypeCouleur Robot::getCouleur() const{
    return couleur;
}

//accesseurs couleur nom
string Robot::getCouleurNom() const {
    switch (couleur) {
        case ROUGE: return "ROUGE";
        case VERT:  return "VERT";
        case BLEU:  return "BLEU";
        case JAUNE: return "JAUNE";
        default:    return "INCONNUE";
    }
}

//accesseurs nombre_de_deplacements
int Robot::getNombreDeDeplacements() const{
    return nombre_de_deplacements;
}

//fonction positionOccupee qui verifie si une position est occupee par un autre robot
bool Robot::positionOccupee(int nx, int ny, const vector<Robot*> &robots){
    for (const auto& robot : robots) { //parcours tous les robots
        if (robot == this) continue; // Ne pas se comparer à soi-même
        if (robot->getX() == nx && robot->getY() == ny) { 
            return true; //retourne vrai si la position est occupee par un autre robot
        }
    }
    return false; //retourne faux si la position n'est pas occupee par un autre robot
}

//deplacement du robot sur le plateau (haut, bas, gauche, droite) jusqu'a la limite du plateau 16x16
void Robot::deplacement(string direction, const vector<Robot*> &robots){
    if (direction == "haut"){
        while (y < 15){  // Tant que le robot n'est pas déjà en haut du plateau
            y++;        // Déplacer le robot vers le haut
            if (positionOccupee(this->x, this->y, robots)) { // Si la position est occupée par un autre robot
                y--; // Reculer d'une case
                break; // Sortir de la boucle
            }
        }
    nombre_de_deplacements++;
    }else if (direction == "bas"){
        while (y > 0){  // Tant que le robot n'est pas déjà en bas du plateau
            y--;         // Déplacer le robot vers le bas
            if (positionOccupee(this->x, this->y, robots)) { // Si la position est occupée par un autre robot
                y++; // Reculer d'une case
                break; // Sortir de la boucle
            }
        }
    nombre_de_deplacements++;  // Ajouter un déplacement
    }else if (direction == "gauche"){
        while (x > 0){  // Tant que le robot n'est pas déjà à gauche du plateau
            x--;        // Déplacer le robot vers la gauche
            if (positionOccupee(this->x, this->y, robots)) { // Si la position est occupée par un autre robot
                x++; // Reculer d'une case
                break; // Sortir de la boucle
            }
        }
    nombre_de_deplacements++;  // Ajouter un déplacement
    }else if (direction == "droite"){
        while (x < 15){  // Tant que le robot n'est pas déjà à droite du plateau
            x++;         // Déplacer le robot vers la droite
            if (positionOccupee(this->x, this->y, robots)) { // Si la position est occupée par un autre robot
                x--; // Reculer d'une case
                break; // Sortir de la boucle
            }
        }
    nombre_de_deplacements++;  // Ajouter un déplacement
    }else{
        cout << "Direction non valide" << endl; // Message d'erreur si la direction n'est pas valide
    }
}

// Fonction pour vérifier si une position est libre pour eviter le chevauchement
bool estPositionLibre(int x, int y, const std::vector<Robot>& robots) {
    for (const auto& robot : robots) {
        if (robot.getX() == x && robot.getY() == y)
            return false; // Position occupée
    }
    return true; // Position libre
}


//fonction pour creer quatre robots de couleurs differents avec des positions aleatoires (ils ne doivent pas se chevaucher)
vector<Robot> creationRobots() {
    srand(time(0)); // Initialisation du générateur aléatoire

    vector<Robot> robots;

    for (int i = 0; i < 4; ++i) {
        int x, y;
        do {
            x = rand() % 16;
            y = rand() % 16;
        } while (!estPositionLibre(x, y, robots)); // Vérifie la position dans le vecteur déjà créé

        robots.push_back(Robot(x, y, static_cast<TypeCouleur>(i))); // Crée un robot avec une couleur différente
    }

    return robots; // Retourne la liste créée
}

vector<Robot*> getPointers(vector<Robot>& robots) {
    vector<Robot*> ptrs;
    for (Robot& r : robots) {
        ptrs.push_back(&r); 
    }
    return ptrs;
}