/*
 * LUCAS
 * SOPHIA
 * DJAMAEL
 * DIARRA
 * TP11 - SEC - 28/04/2025
 * Ricochet Robots
*/


#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <ctime>    // Pour srand()
#include <unistd.h> // Pour sleep()
#include <vector>
#include "robot.h" 
#include "sablier.h"
#include "joueur.h"
#include "plateau.h"
#include "tuile_objectif.h"
#include "jeu.h" 

using namespace std;

 
int main(){   

    // === Étape 0 : Initialisation du plateau de jeu ===
    cout << "=== Initialisation de l'ensemble du jeu ===" << endl;
    Jeu game(); // Crée un objet de la classe Jeu avec le constructeur par défaut qui initialise tout le jeu


    //boucle while pour lancer une manche
    while(true){

        // === Étape 1 : Tirage de la tuile objectif === 
        cout << "=== Tirage de la tuile objectif ===" << endl;
        game.tirerTuileObjectif(); // Tire une tuile objectif et l'affiche

        // === Étape 2 : Attente de la confirmation du joueur ===
        string input_ok;
        while (true) {
            cout << "Tapez 'ok' pour continuer..." << endl;
            getline(cin, input_ok);
            if (input_ok == "ok") break;
            cout << "Entrée invalide. Veuillez taper 'ok'." << endl;
        }


        // === Étape 3 : Lancer le sablier ===
        cout << "Lancement du sablier, il reste 60 secondes..." << endl;
        game.annoncerSolution(); // active le sablier de 60 secondes

        // === Étape 4 & 5 : Proposition et validation de la solution ===
        bool solutionValide = false;
        while (solutionValide == false) {

            // === Étape 4 : Proposition de la solution ===
            cout << "\n=== Proposition de la solution par le joueur ===" << endl;
            cout << "Entrez le nom du joueur qui propose la solution : ";
            string nomJoueurProposition;
            getline(cin, nomJoueurProposition);
            game.propositionSolution(nomJoueurProposition);

            // === Étape 5 : Validation de la solution ===
            cout << "\n=== Validation de la solution en cours ===" << endl;
            if (game.validationSolution() == true) {
                cout << "Solution valide. Fin de la manche." << endl;
                solutionValide = true;
            } else {
                cout << "Solution invalide. Le joueur perd 1 point." << endl;
                cout << "Un autre joueur peut maintenant proposer une nouvelle solution." << endl;
                // Retourne à l'étape 4 automatiquement
            }
        }

        //attente de 5 secondes avant de recommencer une nouvelle manche
        cout << "Attendez 5 secondes avant de recommencer une nouvelle manche..." << endl;
        sleep(5); // Pause de 5 secondes
    }
}