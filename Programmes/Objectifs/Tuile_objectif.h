#ifndef _TUILE_OBJECTIF_H
#define _TUILE_OBJECTIF_H
#include <iostream>
#include "stdlib.h"     // Pour utiliser la fonction rand() pour la génération de nombres aléatoires
#include <ctime>        // Pour initialiser le générateur de nombres aléatoires (time(NULL))

#define MAX_POSITION_X 16
#define MAX_POSITION_Y 16
#define NB_COULEURS_DIFFS 5
#define NB_SYMBOLES_DIFFS 4
using namespace std;

typedef enum
{
    ROUGE = 0,
    VERT = 1,
    BLEU = 2,
    JAUNE = 3,
    MULTICOLORE = 4
}TypeCouleur;

typedef enum
{
    LOSANGE = 0,
    CARRE = 1,
    ETOILE = 2,
    ROND = 3
}TypeSymbole;

class Tuile_objectif
{
private:
    int positionX, positionY;
    TypeCouleur couleur;
    TypeSymbole symbole;


public:
    Tuile_objectif(/* args */);
    Tuile_objectif(int _positionX, int _positionY, TypeCouleur _couleur, TypeSymbole);
    
    // Setters
    void setPosition(int _positionX, int _positionY);
    void setCouleur(TypeCouleur _couleur);
    void setSymbole(TypeSymbole _symbole);


    // Getters
    void getPosition(int *_positionX, int *_positonY);
    int get_X();
    int get_Y();
    TypeCouleur getCouleur();
    TypeSymbole getSymbole();

    

};

#endif