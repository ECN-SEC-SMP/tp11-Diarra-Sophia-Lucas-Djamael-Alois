/*
 * LUCAS OROS 
 * TP11 - SEC - 28/04/2025
 * Ricochet Robots
 */


 #include <iostream>
 #include <string>
 #include <fstream>
 #include <sstream>
 #include <map>
 #include <ctime>    // Pour srand()
 #include "robot.h"
 #include "temps.h"
 
 
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
    //==== Création des 4 robots ====
    vector<Robot> robots = creationRobots(); // Créer 4 robots avec des positions aléatoires
    vector<Robot*> robotPtrs = getPointers(robots); // Obtenir les pointeurs vers les robots
 
 
    //==== Affichage des robots ====
    for (size_t i = 0; i < robots.size(); ++i) {
        std::cout << "Robot " << i+1 << " : (" 
                  << robots[i].getX() << ", " 
                  << robots[i].getY() << ", " 
                  << robots[i].getCouleurNom() << ")" << std::endl;
    }
     
     
    //==== Vérification de la position d'un robot ====
    //verification de la position du robot 0
    if (robots[0].positionOccupee(7, 4, robotPtrs)) {
        cout << "La position est occupee par un robot" << endl;
    } else {
        cout << "La position n'est pas occupee par un robot" << endl;
    }
 

    //==== Déplacements des robots ====

    //deplacement du robot 0 vers le haut
    robots[0].deplacement("haut", robotPtrs);
    cout << "Robot 0 : (" << robots[0].getX() << ", " << robots[0].getY() << ")" << endl;
 
    //deplacement du robot 1 vers la droite
    robots[1].deplacement("droite", robotPtrs);
    cout << "Robot 1 : (" << robots[1].getX() << ", " << robots[1].getY() << ")" << endl;
 
    //deplacement du robot 0 vers le droite
    robots[0].deplacement("droite", robotPtrs);
    cout << "Robot 0 : (" << robots[0].getX() << ", " << robots[0].getY() << ")" << endl;
     
    //deplacement du robot 3 pour rencontrer le robot 2
    robots[3].deplacement("gauche", robotPtrs);
    cout << "Robot 4 : (" << robots[3].getX() << ", " << robots[3].getY() << ")" << endl;
 


    //==== Affichage du nombre de déplacements effectués par chaque robot ====
    //nombre de deplacements effectues par les 4 robots
    for(size_t i = 0; i < robots.size(); ++i) {
        std::cout << "Robot " << i+1 << " : " 
                  << robots[i].getNombreDeDeplacements() 
                  << " deplacements" << std::endl;
    }
}