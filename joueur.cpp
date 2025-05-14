// Class Joueur

#include "joueur.h"
#include <iostream>

using namespace std;

/**
 * @class Joueur
 * @brief Représente un joueur dans le jeu avec un nom, un score et un nombre de déplacements.
 */

// Constructeur par défaut
/**
 * @brief Constructeur par défaut du joueur.
 * Initialise le nom à "Joueur", le score à 0 et le nombre de déplacements à 0.
 */
Joueur::Joueur()
{
    this->nom = "Joueur";           // Nom par défaut
    this->score = 0;                // Score initialisé à 0
    this->nombreDeDeplacements = 0; // Nombre de déplacements initialisé à 0
}

// Constructeur avec paramètres
/**
 * @brief Constructeur du joueur avec des paramètres spécifiés.
 * @param nom Le nom du joueur.
 * @param score Le score du joueur.
 * @param nombreDeDeplacements Le nombre de déplacements du joueur.
 */
Joueur::Joueur(string nom, int score, int nombreDeDeplacements)
{
    this->nom = nom;                                   // Initialisation du nom
    this->score = score;                               // Initialisation du score
    this->nombreDeDeplacements = nombreDeDeplacements; // Initialisation du nombre de déplacements
}

// Retourne le nom
/**
 * @brief Retourne le nom du joueur.
 * @return Le nom du joueur.
 */
string Joueur::getNom() const
{
    return this->nom; // Retourne le nom du joueur
}

// Retourne le nombre de déplacements effectués par le joueur
/**
 * @brief Retourne le nombre de déplacements effectués par le joueur.
 * @return Le nombre de déplacements du joueur.
 */
int Joueur::getNombreDeDeplacements() const
{
    return this->nombreDeDeplacements; // Retourne le nombre de déplacements
}

// Retourne le score du joueur
/**
 * @brief Retourne le score du joueur.
 * @return Le score du joueur.
 */
int Joueur::getScore() const
{
    return this->score; // Retourne le score du joueur
}

// Modifie le nom du joueur
/**
 * @brief Modifie le nom du joueur.
 * @param nom Le nouveau nom du joueur.
 */
void Joueur::setNom(string nom)
{
    this->nom = nom; // Modifie le nom du joueur
}

// Modifie le score du joueur
/**
 * @brief Modifie le score du joueur.
 * @param score Le nouveau score du joueur.
 */
void Joueur::setScore(int score)
{
    this->score = score; // Modifie le score du joueur
}

// Modifie le nombre de déplacements effectués par le joueur
/**
 * @brief Modifie le nombre de déplacements effectués par le joueur.
 * @param nombreDeDeplacements Le nouveau nombre de déplacements.
 */
void Joueur::setNombreDeDeplacements(int nombreDeDeplacements)
{
    this->nombreDeDeplacements = nombreDeDeplacements; // Modifie le nombre de déplacements
}