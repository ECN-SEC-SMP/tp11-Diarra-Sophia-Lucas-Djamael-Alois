#include <iostream>
#include "plateau.h"
// #include "robot.h"
#include "robot_test.h"


int main() {
    Plateau plateau;
    plateau.genererGrille();     // Génère murs extérieurs + croix

    Robot r;            // Crée un robot 
    plateau.placerRobot(r);      // Place le robot rouge

    plateau.afficherPlateau();   // Affiche tout le plateau dans le terminal

    return 0;
}
