/// \file sablier.h
/// \brief Déclaration de la classe Sablier.

#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;

/// \class Sablier
/// \brief Classe représentant un minuteur simple avec affichage du temps restant.
class Sablier
{
protected:
    /// \brief Temps actuel du sablier (en secondes).
    int temps;

public:
    ///
    /// \brief Constructeur par défaut.
    /// Initialise le sablier à 0 seconde.
    ///
    Sablier();

    ///
    /// \brief Lance un compte à rebours de 3 secondes.
    /// Affiche le temps restant dans la console à chaque seconde.
    ///
    void start_timer();
};