/*
 * LUCAS
 * SOPHIA
 * DJAMAEL
 * DIARRA
 * TP11 - SEC - 28/04/2025
 * Ricochet Robots
*/


#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <ctime>    // Pour srand()
#include <vector>
#include "robot.h" 
#include "sablier.h"
#include "joueur.h"
#include "plateau.h"

using namespace std;
 
 
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
 
 
int main(){   
    //MAIN

    //1. Initialisation du plateau de jeu (fonction jeu)
    //2. tirer carte objectif (fonction jeu)
    //3. Annoncer solution (fonction jeu)
    //4. Proposition solution (fonction jeu)
    //5. Validation solution (fonction jeu)
    //6. Fin de la manche main

}
 
 