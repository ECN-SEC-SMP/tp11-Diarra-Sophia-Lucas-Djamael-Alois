/// \file sablier.cpp
/// \brief Implémentation de la classe Sablier

#include "sablier.h"
#include <iostream>
#include <unistd.h>

using namespace std;

///
/// \class Sablier
/// \brief Classe représentant un minuteur simple de 3 secondes.
///

// ====================== Constructeur ======================

///
/// \brief Constructeur par défaut de la classe Sablier
/// Initialise le temps à 0.
///
Sablier::Sablier(){
    this->temps = 0;
}


// ====================== Méthodes ======================

///
/// \brief Lance un compte à rebours de 3 secondes.
/// Affiche le temps restant à chaque seconde dans la console.
///
void Sablier::start_timer() {

    for(int i = 2; i >= 0; i--) {
        // Affiche le temps restant
        this->temps = i;
        cout << "Temps restant : " << this->temps << " secondes" << endl;
        sleep(1);///< Attente d'une seconde
    }
}