#ifndef PLATEAU_H
#define PLATEAU_H

#include <string>
#include <vector>
#include "robot.h"


typedef enum
{
    VIDE = 0,
    NON_VIDE = 1,
    VOITURE = 2,
    TUILE =3,
    MUR = 4
}Element_Grille;

class Plateau {
private:
    int grille[32][32];

public:
    Plateau();
    void placerRobot(Robot* robot); // Place un robot
    void afficherPlateau(); // Affiche le plateau
    void placerMur(int x, int y, string orientation);
    void ajouterMursQuadrants();
    bool placerAngle(int row, int col, const string& orientation);
    void ajouterAnglesQuadrants();
    vector<pair<int, int>> getCoordonneesCases(int valeur) const ;
    void placerTuilesObjectif(vector<Tuile_objectif>& tuilesPlacees);
    void majPlateau(const std::vector<Robot*>& robots);
};

#endif