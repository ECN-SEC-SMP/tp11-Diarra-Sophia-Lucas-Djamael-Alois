// Class Temps

#include "sablier.h"
#include <iostream>
#include <unistd.h> // Pour sleep()

using namespace std;

// Constructeur par défaut
Sablier::Sablier(){
    // Initialisation du temps à 0
    this->temps = 0;
}


// Fonction pour démarrer le timer
void Sablier::start_timer() {

    for(int i = 2; i >= 0; i--) {
        // Affiche le temps restant
        this->temps = i;
        cout << "Temps restant : " << this->temps << " secondes" << endl;
        // Attendre une seconde
        sleep(1);
    }
}