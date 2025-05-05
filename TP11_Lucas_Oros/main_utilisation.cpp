#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <ctime>    // Pour srand()
#include "robot.h"
#include "sablier.h"
#include "joueur.h"


using namespace std;


int main() {
vector<Joueur> joueurs; // vecteur de joueurs

cout << "=== Ajout des joueurs ===" << endl;
while (true) {
    cout << "Entrez le nom du joueur puis entrée pour valider (ou tapez 'commencer la partie' pour démarrer) :" << endl;
    string input;
    getline(cin, input);

    if (input == "commencer la partie") break;
    if (!input.empty()) {
        Joueur j(input, 0, 0); // constructeur avec nom, score, déplacements
        joueurs.push_back(j);
    }
}

// Affichage des joueurs
cout << "\nil y a " << joueurs.size() << " joueurs dans la partie" << endl;
cout << "\n=== Liste des joueurs ===" << endl;
for (size_t i = 0; i < joueurs.size(); ++i) {
    cout << "Joueur " << i + 1 << " : " << joueurs[i].getNom() << endl;
}

//commencer la partie
cout << "\n=== Partie commence ===" << endl;
}