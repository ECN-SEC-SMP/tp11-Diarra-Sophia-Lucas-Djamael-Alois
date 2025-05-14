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
#include <ctime> // Pour srand()

#ifdef _WIN32
#include <windows.h> // Pour Sleep()
#else
#include <unistd.h> // Pour sleep()
#endif

#include <vector>
#include "robot.h"
#include "sablier.h"
#include "joueur.h"
#include "plateau.h"
#include "Tuile_objectif.h"
#include "jeu.h"


// using namespace std;

// int main()
// {
//     SetConsoleOutputCP(CP_UTF8);
//     // === Étape 0 : Initialisation du plateau de jeu ===
//     cout << "=== Initialisation de l'ensemble du jeu ===" << endl;
//     Jeu game; // Crée un objet de la classe Jeu avec le constructeur par défaut qui initialise tout le jeu

//     // boucle while pour lancer une manche
//     while (true)
//     {

//         // === Étape 1 : Tirage de la tuile objectif ===
//         cout << "=== Tirage de la tuile objectif ===" << endl;
//         game.tirer_tuile_objectif(); // Tire une tuile objectif et l'affiche

//         // === Étape 2 : Attente de la confirmation du joueur ===
//         string input_ok;
//         while (true)
//         {
//             cout << "Tapez 'ok' pour continuer..." << endl;
//             getline(cin, input_ok);
//             if (input_ok == "ok")
//                 break;
//             cout << "Entrée invalide. Veuillez taper 'ok'." << endl;
//         }

//         // === Étape 3 : Lancer le sablier ===
//         cout << "Lancement du sablier, il reste 60 secondes..." << endl;
//         game.annoncer_Solution(); // active le sablier de 60 secondes

//         // === Étape 4 & 5 : Proposition et validation de la solution ===
//         bool solutionValide = false;
//         while (solutionValide == false)
//         {

//             // === Étape 4 : Proposition de la solution ===
//             cout << "\n=== Proposition de la solution par le joueur ===" << endl;
//             game.proposer_Solution();

//             // === Étape 5 : Validation de la solution ===
//             cout << "Entrez le nom du joueur qui a proposé la solution : " << endl;
//             string nomJoueurProposition;
//             getline(cin, nomJoueurProposition);
//             cout << "Nom du joueur : " << nomJoueurProposition << endl;

//             cout << "\n=== Validation de la solution en cours ===" << endl;
//             if (game.valider_solution(nomJoueurProposition) == true)
//             {
//                 cout << "Solution valide. Fin de la manche." << endl;
//                 solutionValide = true;
//             }
//             else
//             {
//                 cout << "Un autre joueur peut maintenant proposer une nouvelle solution." << endl;
//                 // Retourne à l'étape 4 automatiquement
//             }
//         }

//         // attente de 5 secondes avant de recommencer une nouvelle manche
//         cout << "Attendez 5 secondes avant de recommencer une nouvelle manche..." << endl;
// #ifdef _WIN32
//         Sleep(5000); // Windows: millisecondes
// #else
//         sleep(5); // Unix/Linux: secondes
// #endif

//         cout << "=== Continuer la partie : OUI / NON ===" << endl;
//         string continuerPartie;
//         getline(cin, continuerPartie);
//         if (continuerPartie == "NON")
//         {
//             cout << "Fin de la partie." << endl;
//             break; // Sort de la boucle while pour terminer le jeu
//         }
//         else if (continuerPartie != "OUI")
//         {
//             cout << "Entrée invalide, la partie continue." << endl;
//         }
//     }
// }

#include <iostream>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    Plateau leplateau;
    vector<Robot> robots = creationRobots();
    cout<<robots.size()<<endl;
    for (auto& robot : robots) {
        leplateau.placerRobot(&robot);
    }
    vector<Tuile_objectif> tuiles;
    leplateau.placerTuilesObjectif(tuiles);
    leplateau.afficherPlateau();
    return 0;
}
