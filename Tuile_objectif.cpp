/**
 * @file Tuile_objectif.cpp
 * @brief Implémentation de la classe Tuile_objectif représentant une tuile avec position, couleur et symbole.
 */

#include "Tuile_objectif.h"

/**
 * @brief Constructeur de la classe Tuile_objectif.
 *
 * Initialise la position, la couleur et le symbole de manière aléatoire.
 */
Tuile_objectif::Tuile_objectif(/* args */)
{
    this->positionX = rand() % MAX_POSITION_X;
    this->positionY = rand() % MAX_POSITION_Y;
    this->couleur = (TypeCouleur)(rand() % NB_COULEURS_DIFFS);
    this->symbole = (TypeSymbole)(rand() % NB_SYMBOLES_DIFFS);
}

/**
 * @brief Constructeur de la classe Tuile_objectif.
 *
 * @param _positionX Position en X à affecter.
 * @param _positionY Position en Y à affecter.
 * @param _couleur   Couleur à affecter.
 * @param __symbole  Symbole à affecter.
 */
Tuile_objectif::Tuile_objectif(int _positionX, int _positionY, TypeCouleur _couleur, TypeSymbole _symbole)
{
    this->positionX = _positionX % MAX_POSITION_X;
    this->positionY = _positionY % MAX_POSITION_Y;
    this->couleur = (TypeCouleur)(_couleur % NB_COULEURS_DIFFS);
    this->symbole = (TypeSymbole)(_symbole % NB_SYMBOLES_DIFFS);
}

/**
 * @brief Définit la position de la tuile.
 *
 * @param _positionX Position en X à affecter.
 * @param _positionY Position en Y à affecter.
 */
void Tuile_objectif::setPosition(int _positionX, int _positionY)
{
    this->positionX = _positionX;
    this->positionY = _positionY;
}

/**
 * @brief Définit la couleur de la tuile.
 *
 * @param _couleur La nouvelle couleur de la tuile.
 */
void Tuile_objectif::setCouleur(TypeCouleur _couleur)
{
    this->couleur = _couleur;
}

/**
 * @brief Définit le symbole de la tuile.
 *
 * @param _symbole Le nouveau symbole de la tuile.
 */
void Tuile_objectif::setSymbole(TypeSymbole _symbole)
{
    this->symbole = _symbole;
}

/**
 * @brief Récupère la position actuelle de la tuile.
 *
 * @param _positionX Pointeur vers une variable recevant la position X.
 * @param _positionY Pointeur vers une variable recevant la position Y.
 */
void Tuile_objectif::getPosition(int *_positionX, int *_positionY) const
{
    *_positionX = this->positionX;
    *_positionY = this->positionY;
}

/**
 * @brief Récupère la position X de la tuile.
 *
 * @return La position X de la tuile.
 */
int Tuile_objectif::get_X() const
{
    return this->positionX;
}

/**
 * @brief Récupère la position Y de la tuile.
 *
 * @return La position Y de la tuile.
 */
int Tuile_objectif::get_Y() const
{
    return this->positionY;
}

/**
 * @brief Récupère la couleur de la tuile.
 *
 * @return La couleur actuelle de la tuile.
 */
TypeCouleur Tuile_objectif::getCouleur() const
{
    return this->couleur;
}

/**
 * @brief Récupère le symbole de la tuile.
 *
 * @return Le symbole actuel de la tuile.
 */
TypeSymbole Tuile_objectif::getSymbole() const
{
    return this->symbole;
}