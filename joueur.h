#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;

/**
 * @class Joueur
 * @brief Représente un joueur dans le jeu avec un nom, un score et un nombre de déplacements effectués pendant la partie.
 */
class Joueur
{
protected:
    string nom;               // nom du joueur
    int score;                // score du joueur pendant la partie
    int nombreDeDeplacements; // nombre de deplacements effectues par le joueur pendant la manche
public:
    /**
     * @brief Constructeur par défaut du joueur.
     * Initialise le nom à "Joueur", le score à 0 et le nombre de déplacements à 0.
     */
    Joueur();

    /**
     * @brief Constructeur du joueur avec des paramètres spécifiés.
     * @param nom Le nom du joueur.
     * @param score Le score du joueur.
     * @param nombreDeDeplacements Le nombre de déplacements effectués par le joueur.
     */
    Joueur(string nom, int score, int nombreDeDeplacements); // constructeur avec parametres

    // Getters

    /**
     * @brief Retourne le nom du joueur.
     * @return Le nom du joueur.
     */
    string getNom() const; // retourne le nom du joueur

    /**
     * @brief Retourne le nombre de déplacements effectués par le joueur.
     * @return Le nombre de déplacements effectués.
     */
    int getNombreDeDeplacements() const; // retourne le nombre de deplacements effectues par le joueur

    /**
     * @brief Retourne le score du joueur.
     * @return Le score du joueur.
     */
    int getScore() const; // retourne le score du joueur

    // Setters

    /**
     * @brief Modifie le nom du joueur.
     * @param nom Le nouveau nom du joueur.
     */
    void setNom(string nom); // modifie le nom du joueur

    /**
     * @brief Modifie le score du joueur.
     * @param score Le nouveau score du joueur.
     */
    void setScore(int score); // modifie le score du joueur

    /**
     * @brief Modifie le nombre de déplacements effectués par le joueur.
     * @param nombreDeDeplacements Le nouveau nombre de déplacements.
     */
    void setNombreDeDeplacements(int nombreDeDeplacements); // modifie le nombre de deplacements effectues par le joueur
};