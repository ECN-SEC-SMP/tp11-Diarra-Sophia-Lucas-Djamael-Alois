#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;



class Joueur{
protected:
    string nom; //nom du joueur
    int score; //score du joueur pendant la partie
    int nombreDeDeplacements; //nombre de deplacements effectues par le joueur pendant la manche
public:
    Joueur();

    Joueur(string nom, int score, int nombreDeDeplacements); //constructeur avec parametres

    //getters

    //retourne le nom du joueur
    string getNom() const; //retourne le nom du joueur

    //retourne le nombre de deplacements effectues par le joueur
    int getNombreDeDeplacements() const; //retourne le nombre de deplacements effectues par le joueur

    //retourne le score du joueur
    int getScore() const; //retourne le score du joueur

    //setters

    //ecrit le nom du joueur
    void setNom(string nom); //modifie le nom du joueur
    
    //modifie le score du joueur
    void setScore(int score); //modifie le score du joueur

    //modifie le nombre de deplacements effectues par le joueur
    void setNombreDeDeplacements(int nombreDeDeplacements); //modifie le nombre de deplacements effectues par le joueur 
};