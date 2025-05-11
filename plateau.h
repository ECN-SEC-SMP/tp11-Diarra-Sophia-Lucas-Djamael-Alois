#ifndef PLATEAU_H
#define PLATEAU_H

#include <string>
#include <vector>
#include "robot.h"

class Plateau {
private:
    int grille[16][16];

public:
    Plateau();
    void genererGrille(); // Met les murs extérieurs
    void placerMur(int x, int y, std::string orientation);
    void placerRobot(Robot robot); // Place un robot
    void afficherPlateau(); // Affiche le plateau

    void placerAngle(int x, int y); // Place un angle (mur en L)
    std::pair<int, int> getRandomAngle(); // Fournit une position valide d’angle pour une tuile
    void placerTuile(int x, int y, char symbole);
};

#endif