/**
 * @file Tuile_objectif.h
 * @brief Déclaration de la classe Tuile_objectif représentant une tuile avec une position, une couleur et un symbole.
 */

#ifndef _TUILE_OBJECTIF_H
#define _TUILE_OBJECTIF_H
#include <iostream>
#include "stdlib.h" // Pour utiliser la fonction rand() pour la génération de nombres aléatoires
#include <ctime>    // Pour initialiser le générateur de nombres aléatoires (time(NULL))

#define MAX_POSITION_X 16
#define MAX_POSITION_Y 16
#define NB_COULEURS_DIFFS 5
#define NB_SYMBOLES_DIFFS 4
using namespace std;

/**
 * @brief Représente les différentes couleurs possibles pour une tuile.
 */
typedef enum
{
    ROUGE = 0,
    VERT = 1,
    BLEU = 2,
    JAUNE = 3,
    MULTICOLORE = 4
} TypeCouleur;

/**
 * @brief Représente les différents symboles possibles pour une tuile.
 */
typedef enum
{
    LOSANGE = 0,
    CARRE = 1,
    ETOILE = 2,
    ROND = 3
} TypeSymbole;

/**
 * @class Tuile_objectif
 * @brief Classe représentant une tuile objectif avec une position, une couleur et un symbole.
 */
class Tuile_objectif
{
private:
    int positionX, positionY; ///< Coordonnée X et Y de la tuile
    TypeCouleur couleur;      ///< Couleur de la tuile
    TypeSymbole symbole;      ///< Symbole de la tuile

public:
    /**
     * @brief Constructeur aléatoire de la tuile.
     *
     * Initialise la tuile avec une position, une couleur et un symbole choisis aléatoirement.
     */
    Tuile_objectif();

    /**
     * @brief Constructeur avec paramètres.
     *
     * @param _positionX Position X à affecter.
     * @param _positionY Position Y à affecter.
     * @param _couleur Couleur de la tuile.
     * @param _symbole Symbole de la tuile.
     */
    Tuile_objectif(int _positionX, int _positionY, TypeCouleur _couleur, TypeSymbole);

    // Setters

    /**
     * @brief Définit la position de la tuile.
     * @param _positionX Nouvelle position X.
     * @param _positionY Nouvelle position Y.
     */
    void setPosition(int _positionX, int _positionY);

    /**
     * @brief Définit la couleur de la tuile.
     * @param _couleur Nouvelle couleur.
     */
    void setCouleur(TypeCouleur _couleur);

    /**
     * @brief Définit le symbole de la tuile.
     * @param _symbole Nouveau symbole.
     */
    void setSymbole(TypeSymbole _symbole);

    // Getters

    /**
     * @brief Récupère la position actuelle de la tuile.
     * @param _positionX Pointeur vers la variable où stocker la position X.
     * @param _positionY Pointeur vers la variable où stocker la position Y.
     */
    void getPosition(int *_positionX, int *_positionY) const;

    /**
     * @brief Récupère le symbole de la tuile.
     * @return Symbole actuel de la tuile.
     */
    TypeSymbole getSymbole() const;

    /**
     * @brief Récupère la couleur de la tuile.
     * @return Couleur actuelle de la tuile.
     */
    TypeCouleur getCouleur() const;

    /**
     * @brief Récupère la coordonnée X de la tuile.
     * @return Position X de la tuile.
     */
    int get_X() const;

    /**
     * @brief Récupère la coordonnée Y de la tuile.
     * @return Position Y de la tuile.
     */
    int get_Y() const;
};
void printTuile(Tuile_objectif *latuile);
#endif