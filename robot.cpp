// Class Robot

#include "robot.h"
#include "plateau.h"
#include <iostream>

using namespace std;


/**
 * @brief Constructeur par défaut. Initialise la position du robot de façon aléatoire et sa couleur à ROUGE.
 */
Robot::Robot(){
    int maxX = 16;
    int maxY = 16;

    x = rand() % maxX;
    y = rand() % maxY;

    couleur = ROUGE; 
    nombre_de_deplacements = 0;
}

/**
 * @brief Constructeur avec paramètres.
 * @param x Position en X.
 * @param y Position en Y.
 * @param c Couleur du robot.
 * @param nombre_de_deplacements Nombre de déplacements effectués.
 */
Robot::Robot(int x, int y, TypeCouleur c, int nombre_de_deplacements){
    this->x = x;
    this->y = y;
    this->couleur = c;
    this->nombre_de_deplacements = nombre_de_deplacements;
}

/**
 * @brief Accesseur de la position X.
 * @return La position X du robot.
 */
int Robot::getX() const{
    return x;
}

/**
 * @brief Accesseur de la position Y.
 * @return La position Y du robot.
 */
int Robot::getY() const{
    return y;
}

/**
 * @brief Mutateur de la position X.
 * @param X Nouvelle position X.
 */
void Robot::setX(int X)
{
    this->x = X;
}

/**
 * @brief Mutateur de la position Y.
 * @param Y Nouvelle position Y.
 */
void Robot::setY(int Y)
{
    this->y = Y;
}

/**
 * @brief Accesseur de la couleur du robot.
 * @return La couleur du robot.
 */
TypeCouleur Robot::getCouleur() const{
    return couleur;
}

/**
 * @brief Retourne le nom de la couleur du robot sous forme de chaîne de caractères.
 * @return Nom de la couleur (ROUGE, VERT, BLEU, JAUNE, INCONNUE).
 */
string Robot::getCouleurNom() const {
    switch (couleur) {
        case ROUGE: return "ROUGE";
        case VERT:  return "VERT";
        case BLEU:  return "BLEU";
        case JAUNE: return "JAUNE";
        default:    return "INCONNUE";
    }
}

/**
 * @brief Accesseur du nombre de déplacements effectués par le robot.
 * @return Nombre de déplacements.
 */
int Robot::getNombreDeDeplacements() const{
    return nombre_de_deplacements;
}

/**
 * @brief Vérifie si une position est occupée par un autre robot.
 * @param nx Position X à vérifier.
 * @param ny Position Y à vérifier.
 * @param robots Vecteur contenant les pointeurs vers les robots.
 * @return true si la position est occupée, false sinon.
 */
bool Robot::positionOccupee(int nx, int ny, const vector<Robot*> &robots){
    for (const auto& robot : robots) { 
        if (robot == this) continue; 
        if (robot->getX() == nx && robot->getY() == ny) { 
            return true; 
        }
    }
    return false; 
}

/**
 * @brief Déplace le robot dans une direction donnée si la case n'est ni un mur ni occupée.
 * @param direction Direction du déplacement ("haut", "bas", "gauche", "droite").
 * @param robots Vecteur contenant les pointeurs vers les autres robots.
 * @param plateau Pointeur vers l'objet Plateau.
 */
void Robot::deplacement(string direction, const vector<Robot*> &robots, Plateau* plateau) {
    if (direction == "droite"){
        if (y < 15){  // Tant que le robot n'est pas déjà en haut du plateau
            y++;        // Déplacer le robot vers le haut
            if (positionOccupee(this->x, this->y, robots)) { // Si la position est occupée par un autre robot
                y--; // Reculer d'une case
                //break; // Sortir de la boucle
            }
            if(plateau->getGrille(this->x, this->y) == 2){ // Si la case est un mur
                y--; // Reculer d'une case
                //break; // Sortir de la boucle
            }
        }
    nombre_de_deplacements++;
    }else if (direction == "gauche"){
        if (y > 0){  // Tant que le robot n'est pas déjà en bas du plateau
            y--;         // Déplacer le robot vers le bas
            if (positionOccupee(this->x, this->y, robots)) { // Si la position est occupée par un autre robot
                y++; // Reculer d'une case
                //break; // Sortir de la boucle
            }
            if(plateau->getGrille(this->x, this->y) == 2){ // Si la case est un mur
                y++; // Reculer d'une case
                //break; // Sortir de la boucle
            }
        }
    nombre_de_deplacements++;  // Ajouter un déplacement
    }else if (direction == "haut"){
        if (x > 0){  // Tant que le robot n'est pas déjà à gauche du plateau
            x--;        // Déplacer le robot vers la gauche
            if (positionOccupee(this->x, this->y, robots)) { // Si la position est occupée par un autre robot
                x++; // Reculer d'une case
                //break; // Sortir de la boucle
            }
            if(plateau->getGrille(this->x, this->y) == 2){ // Si la case est un mur
                x++; // Reculer d'une case
                //break; // Sortir de la boucle
            }
        }
    nombre_de_deplacements++;  // Ajouter un déplacement
    }else if (direction == "bas"){
        if (x < 15){  // Tant que le robot n'est pas déjà à droite du plateau
            x++;         // Déplacer le robot vers la droite
            if (positionOccupee(this->x, this->y, robots)) { // Si la position est occupée par un autre robot
                x--; // Reculer d'une case
                //break; // Sortir de la boucle
            }
            if(plateau->getGrille(this->x, this->y) == 2){ // Si la case est un mur
                x--; // Reculer d'une case
                //break; // Sortir de la boucle
            }
        }
    nombre_de_deplacements++;  // Ajouter un déplacement
    }else{
        cout << "Direction non valide" << endl; // Message d'erreur si la direction n'est pas valide
    }
}

/**
 * @brief Vérifie si une position est libre (aucun robot ne s'y trouve).
 * @param x Position X à vérifier.
 * @param y Position Y à vérifier.
 * @param robots Vecteur des robots existants.
 * @return true si la position est libre, false sinon.
 */
bool estPositionLibre(int x, int y, const std::vector<Robot>& robots) {
    for (const auto& robot : robots) {
        if (robot.getX() == x && robot.getY() == y)
            return false; // Position occupée
    }
    return true; // Position libre
}


/**
 * @brief Crée 4 robots avec des couleurs différentes à des positions aléatoires non chevauchées.
 * @return Vecteur contenant les robots créés.
 */
vector<Robot> creationRobots() {
    srand(time(0));

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

/**
 * @brief Transforme un vecteur de robots en vecteur de pointeurs vers ces robots.
 * @param robots Référence au vecteur de robots.
 * @return Vecteur de pointeurs vers les robots.
 */
vector<Robot*> getPointers(vector<Robot>& robots) {
    vector<Robot*> ptrs;
    for (Robot& r : robots) {
        ptrs.push_back(&r); 
    }
    return ptrs;
}