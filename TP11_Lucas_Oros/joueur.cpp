// Class Joueur

#include "joueur.h"
#include <iostream>

using namespace std;

// Constructeur par défaut
Joueur::Joueur(){
    this->nom = "Joueur"; // Nom par défaut
    this->score = 0; // Score initialisé à 0
    this->nombreDeDeplacements = 0; // Nombre de déplacements initialisé à 0
}

// Constructeur avec paramètres
Joueur::Joueur(string nom, int score, int nombreDeDeplacements) {
    this->nom = nom; // Initialisation du nom
    this->score = score; // Initialisation du score
    this->nombreDeDeplacements = nombreDeDeplacements; // Initialisation du nombre de déplacements
}

// retourne le nom
string Joueur::getNom() const {
    return this->nom; // Retourne le nom du joueur
}

// retourne le nombre de deplacements effectues par le joueur
int Joueur::getNombreDeDeplacements() const {
    return this->nombreDeDeplacements; // Retourne le nombre de déplacements
}

// retourne le score du joueur
int Joueur::getScore() const {
    return this->score; // Retourne le score du joueur
}

// modifie le nom du joueur
void Joueur::setNom(string nom) {
    this->nom = nom; // Modifie le nom du joueur
}

// modifie le score du joueur
void Joueur::setScore(int score) {
    this->score = score; // Modifie le score du joueur
}

// modifie le nombre de deplacements effectues par le joueur
void Joueur::setNombreDeDeplacements(int nombreDeDeplacements) {
    this->nombreDeDeplacements = nombreDeDeplacements; // Modifie le nombre de déplacements
}