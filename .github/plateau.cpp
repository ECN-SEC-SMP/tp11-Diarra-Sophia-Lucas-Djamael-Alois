#include "plateau.h"
#include "robot.h"  
#include <iostream>    // pour std::cout
#include <string>      // pour std::string
#include <vector>      // pour std::vector
#include <cstdlib> // pour rand()
#include <ctime>   // pour time()

// Constructeur de Plateau : Initialise la grille à vide (toutes cases = 0)
Plateau::Plateau() {
    for (int i = 0; i < 16; i++){
            for (int j = 0; j < 16; j++)
            {
                grille[i][j]=0;
            }
    }
}

// Méthode générerGrille : Met des murs sur les bords du plateau
void Plateau::genererGrille() {
    for (int i = 0; i < 16; i++) {
    grille[0][i] = 1;        // haut
    grille[15][i] = 1;       // bas
    grille[i][0] = 1;        // gauche
    grille[i][15] = 1;       // droite
    // Croix centrale (zone fixe au centre du plateau)
    grille[7][7] = 1;
    grille[7][8] = 1;
    grille[8][7] = 1;
    grille[8][8] = 1;
}
}

void Plateau::placerMur(int x, int y, std::string orientation) { 
   if (orientation == "horizontal") {
    grille[x][y] = 1;           // mur à gauche
    grille[x][y + 1] = 1;       // mur à droite
}
    else if (orientation == "vertical") {
        grille[x][y] = 1;           // mur en haut
        grille[x + 1][y] = 1;       // mur en bas
    } 
}

void Plateau::placerRobot(Robot robot) {
    int x = robot.getX();
    int y = robot.getY();
    
    // Vérifie que la case est libre
    if (grille[y][x] == 0) {
        switch (robot.getCouleur()) {
            case ROUGE: grille[y][x] = 2; break;
            case VERT:  grille[y][x] = 3; break;
            case BLEU:  grille[y][x] = 4; break;
            case JAUNE: grille[y][x] = 5; break;
        }
    } else {
        std::cout << "Position (" << x << "," << y << ") déjà occupée !" << std::endl;
    }
}


void Plateau::afficherPlateau() {
    const int TAILLE = 16;

    // Ligne du haut
    std::cout << "+";
    for (int j = 0; j < TAILLE; ++j) {
        std::cout << "--";
    }
    std::cout << "+" << std::endl;

    // Affichage ligne par ligne
    for (int i = 0; i < TAILLE; ++i) {
        std::cout << "|";
        for (int j = 0; j < TAILLE; ++j) {
            if (grille[i][j] == 0) std::cout << "  ";
            else if (grille[i][j] == 1) std::cout << "# ";
            else if (grille[i][j] == 2) std::cout << "R ";
            else if (grille[i][j] == 3) std::cout << "V ";
            else if (grille[i][j] == 4) std::cout << "B ";
            else if (grille[i][j] == 5) std::cout << "J ";
            else std::cout << "? "; // pour tout autre code
        }
        std::cout << "|" << std::endl;
    }

    // Ligne du bas
    std::cout << "+";
    for (int j = 0; j < TAILLE; ++j) {
        std::cout << "--";
    }
    std::cout << "+" << std::endl;
}

