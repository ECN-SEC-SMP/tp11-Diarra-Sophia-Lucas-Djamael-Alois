#include "plateau.h"
#include "robot.h"
#include <iostream> // pour cout
#include <string>   // pour string
#include <vector>   // pour vector
#include <cstdlib>  // pour rand()
#include <ctime>    // pour time()
#include <utility> // pour pair
#include <random>    // pour std::default_random_engine

// Constructeur par défaut
/**
 * @brief Constructeur par défaut du plateau.
 * Initialise un plateau vide avec une grille de 32x32 cases.
 */
Plateau::Plateau()
{
    for (int i = 0; i < 32; ++i)
    {
        for (int j = 0; j < 32; ++j)
        {
            // Bords à 0
            if (i == 0 || i == 31 || j == 0 || j == 31)
            {
                grille[i][j] = 2;
            }
            else
            {
                // Case à 1 uniquement si ligne et colonne impaires
                grille[i][j] = (i % 2 == 1 && j % 2 == 1) ? 1 : 0;
            }
        }
    }
    ajouterMursQuadrants();
    ajouterAnglesQuadrants();
    // placerMur(30, 5, "droite"); // Place un mur à droite si la case (30,5) vaut 0
    // placerMur(1, 2, "gauche");  // Place un mur à gauche si la case (1,3) vaut 0

}

/**
 * @brief Ajoute des murs dans les différents quadrants du plateau.
 * Cette fonction ajoute des murs à des positions spécifiques du plateau.
 */
void Plateau::ajouterMursQuadrants() {
    srand(time(nullptr)); // Pour de l'aléatoire

    // Q1 : haut gauche
    int mursQ1 = 0;
    while (mursQ1 < 4) {
        if (rand() % 2) {
            int y = 1 + rand() % 15;
            if (grille[1][y] == 0) { // juste sous le haut
                grille[1][y] = 2;
                mursQ1++;
            }
        } else {
            int x = 1 + rand() % 15;
            if (grille[x][1] == 0) { // juste à droite du bord gauche
                grille[x][1] = 2;
                mursQ1++;
            }
        }
    }

    // Q2 : haut droit
    int mursQ2 = 0;
    while (mursQ2 < 4) {
        if (rand() % 2) {
            int y = 16 + rand() % 15;
            if (grille[1][y] == 0) { // juste sous le haut
                grille[1][y] = 2;
                mursQ2++;
            }
        } else {
            int x = 1 + rand() % 15;
            if (grille[x][30] == 0) { // juste à gauche du bord droit
                grille[x][30] = 2;
                mursQ2++;
            }
        }
    }

    // Q3 : bas gauche
    int mursQ3 = 0;
    while (mursQ3 < 4) {
        if (rand() % 2) {
            int y = 1 + rand() % 15;
            if (grille[30][y] == 0) { // juste au-dessus du bas
                grille[30][y] = 2;
                mursQ3++;
            }
        } else {
            int x = 16 + rand() % 15;
            if (grille[x][1] == 0) { // juste à droite du bord gauche
                grille[x][1] = 2;
                mursQ3++;
            }
        }
    }

    // Q4 : bas droit
    int mursQ4 = 0;
    while (mursQ4 < 4) {
        if (rand() % 2) {
            int y = 16 + rand() % 15;
            if (grille[30][y] == 0) { // juste au-dessus du bas
                grille[30][y] = 2;
                mursQ4++;
            }
        } else {
            int x = 16 + rand() % 15;
            if (grille[x][30] == 0) { // juste à gauche du bord droit
                grille[x][30] = 2;
                mursQ4++;
            }
        }
    }
}

/**
 * @brief Place un mur à une position donnée avec une orientation spécifiée.
 * @param x La coordonnée x de la position du mur.
 * @param y La coordonnée y de la position du mur.
 * @param orientation L'orientation du mur (par exemple, "gauche", "droite", "haut", "bas").
 */
void Plateau::placerMur(int x, int y, string orientation) {
    if (orientation == "gauche") {
        if (x == 1 && y > 0 && y < 31 && grille[x][y] == 0) {
            grille[x][y] = 2;
        }
    } else if (orientation == "droite") {
        if (x == 30 && y > 0 && y < 31 && grille[x][y] == 0) {
            grille[x][y] = 2;
        }
    } else if (orientation == "haut") {
        if (y == 1 && x > 0 && x < 31 && grille[x][y] == 0) {
            grille[x][y] = 2;
        }
    } else if (orientation == "bas") {
        if (y == 30 && x > 0 && x < 31 && grille[x][y] == 0) {
            grille[x][y] = 2;
        }
    }
}

/**
 * @brief Place un angle sur le plateau.
 * @param row La ligne où placer l'angle.
 * @param col La colonne où placer l'angle.
 * @param orientation L'orientation de l'angle (par exemple, "haut-gauche").
 * @return True si l'angle a été placé avec succès, sinon false.
 */
bool Plateau::placerAngle(int row, int col, const string& orientation) {
    int r1 = row,   c1 = col;
    int r2, c2, r3, c3;
    int rd, cd; // coordonnées de la case diagonale intérieure

    if (orientation == "haut-gauche") {
        r2 = row-1; c2 = col;
        r3 = row;   c3 = col-1;
        rd = row-1; cd = col-1;
    }
    else if (orientation == "haut-droit") {
        r2 = row-1; c2 = col;
        r3 = row;   c3 = col+1;
        rd = row-1; cd = col+1;
    }
    else if (orientation == "bas-gauche") {
        r2 = row+1; c2 = col;
        r3 = row;   c3 = col-1;
        rd = row+1; cd = col-1;
    }
    else if (orientation == "bas-droit") {
        r2 = row+1; c2 = col;
        r3 = row;   c3 = col+1;
        rd = row+1; cd = col+1;
    }
    else {
        return false;  // orientation invalide
    }

    // Vérification bornes + case libre (==0) pour les 3 branches
    if (r1<0||r1>=32||c1<0||c1>=32|| grille[r1][c1]!=0) return false;
    if (r2<0||r2>=32||c2<0||c2>=32|| grille[r2][c2]!=0) return false;
    if (r3<0||r3>=32||c3<0||c3>=32|| grille[r3][c3]!=0) return false;
    // Vérifie aussi que la case diagonale est bien à 1 avant transformation
    if (rd<0||rd>=32||cd<0||cd>=32|| grille[rd][cd]!=1) return false;

    // Pose de l’angle
    grille[r1][c1] = 2;
    grille[r2][c2] = 2;
    grille[r3][c3] = 2;
    // Transformation de la case intérieure
    grille[rd][cd] = 3;

    return true;
}

/**
 * @brief Ajoute des angles dans les différents quadrants du plateau.
 * Cette fonction ajoute des angles dans les quadrants du plateau.
 */
void Plateau::ajouterAnglesQuadrants() {
    // Initialise l’aléatoire une seule fois
    static bool seeded = false;
    if (!seeded) {
        srand(static_cast<unsigned>(time(nullptr)));
        seeded = true;
    }

    // Définition des quadrants : {row_min, row_max, col_min, col_max}
    int quadrants[4][4] = {
        { 1, 15,  1, 15 },  // Q1 : haut-gauche
        { 1, 15, 16, 30 },  // Q2 : haut-droit
        {16, 30,  1, 15 },  // Q3 : bas-gauche
        {16, 30, 16, 30 }   // Q4 : bas-droit
    };
    const vector<string> orientations = {
        "haut-gauche", "haut-droit", "bas-gauche", "bas-droit"
    };

    // Pour chaque quadrant
    for (int q = 0; q < 4; ++q) {
        int placed = 0;
        int rmin = quadrants[q][0], rmax = quadrants[q][1];
        int cmin = quadrants[q][2], cmax = quadrants[q][3];

        // On place 4 angles aléatoires
        while (placed < 4) {
            int row = rmin + rand() % (rmax - rmin + 1);
            int col = cmin + rand() % (cmax - cmin + 1);
            const string& ori = orientations[ rand() % orientations.size() ];

            // Tente de poser l'angle ; si succès, on incrémente
            if (placerAngle(row, col, ori)) {
                ++placed;
            }
            // Sinon on réessaie
        }
    }
}

/**
 * @brief Place un robot sur le plateau.
 * @param robot Un pointeur vers l'objet robot à placer sur le plateau.
 */
void Plateau::placerRobot(Robot* robot) {
    int x = 1 + 2 * robot->getX();
    int y = 1 + 2 * robot->getY();
    
    // Vérifie que la case est libre
    if (grille[x][y] == 1) {
        switch (robot->getCouleur()) {
            case ROUGE: grille[x][y] = 4; break;
            case VERT:  grille[x][y] = 5; break;
            case BLEU:  grille[x][y] = 6; break;
            case JAUNE: grille[x][y] = 7; break;
            case MULTICOLORE: grille[x][y] = 8; break;
        }
    } else {
        cout << "Position (" << robot->getX() << "," << robot->getY() << ") déjà occupée ! Recherche d'une position libre..." << endl;

        const int max_radius = 15;
        bool placed = false;

        for (int r = 1; r <= max_radius && !placed; ++r) {
            for (int dx = -r; dx <= r; ++dx) {
                for (int dy = -r; dy <= r; ++dy) {
                    // On ne garde que le bord de la couronne (évite de re-tester les cases déjà testées)
                    if (abs(dx) != r && abs(dy) != r) continue;

                    int nx = x + dx;
                    int ny = y + dy;

                    if (nx >= 0 && nx < 33 && ny >= 0 && ny < 33 && grille[nx][ny] == 1) {
                        grille[nx][ny] = 4 + robot->getCouleur();
                        robot->setX((nx - 1) / 2);
                        robot->setY((ny - 1) / 2);
                        cout << "Robot déplacé et placé en (" << robot->getX() << "," << robot->getY() << ")." << endl;
                        placed = true;
                        break;
                    }
                }
                if (placed) break;
            }
        }

        if (!placed) {
            cout << "Aucune position libre trouvée pour le robot." << endl;
        }
    }
}

// Renvoie le code ANSI pour la couleur du robot / tuile
/**
 * @param c La couleur du robot ou de la tuile.
 * @return Le code ANSI correspondant à la couleur.
 */
static const char* ansiCouleur(int c) {
    switch (c) {
        case ROUGE: return "\033[31m";  // rouge
        case VERT:  return "\033[32m";  // vert
        case BLEU:  return "\033[34m";  // bleu
        case JAUNE: return "\033[33m";  // jaune
        default:    return "\033[0m";   // reset
    }
}

// Donne la lettre de la tuile selon son “dizaine”
// (10→carré, 20→losange, 30→étoile, 40→rond)
/**
 * @param val La valeur de la tuile.
 * @return La lettre correspondant à la forme de la tuile.
 */
static char lettreTuile(int val) {
    switch (val / 10) {
        case 1: return 'C';  // carré
        case 2: return 'L';  // losange
        case 3: return 'E';  // étoile
        case 4: return 'I';  // rond
        default:return '?';
    }
}

/**
 * @brief Affiche le plateau de jeu.
 * Affiche l'état actuel de la grille du plateau dans la console.
 */
void Plateau::afficherPlateau() {
    for (int i = 0; i < 32; ++i) {
        for (int j = 0; j < 32; ++j) {
            if(grille[i][j] >= 10 && grille[i][j] < 50)
            {
                // couleur = unité, forme = dizaine
                std::cout
                    << ansiCouleur(grille[i][j] % 10)    // couleur ANSI
                    << lettreTuile(grille[i][j]) << ' '  // lettre + espace
                    << "\033[0m";             // reset
            }
            else switch (grille[i][j]) {
                case 2:
                    cout << "🧱";
                    break;
                case 3:
                    cout << "  ";
                    break;
                case 4: // R rouge
                    cout << "\033[31mR\033[0m ";
                    break;
                case 5: // R vert
                    cout << "\033[32mR\033[0m ";
                    break;
                case 6: // R bleu
                    cout << "\033[34mR\033[0m ";
                    break;
                case 7: // R jaune
                    cout << "\033[33mR\033[0m ";
                    break;
                case 8: // R violet
                    cout << "\033[35mR\033[0m ";
                    break;
                default:
                    // valeur 0 ou 1 : case vide
                    cout << "  ";
                    break;
            }
        }
        cout << endl;
    }
}

/**
 * @brief Retourne les coordonnées des cases ayant une valeur spécifiée.
 * @param valeur La valeur à rechercher sur la grille du plateau.
 * @return Un vecteur de paires représentant les coordonnées des cases correspondantes.
 */
vector<pair<int, int>> Plateau::getCoordonneesCases(int valeur) const {
    vector<pair<int, int>> coordonnees;

    for (int i = 0; i < 33; ++i) {
        for (int j = 0; j < 33; ++j) {
            if (grille[i][j] == valeur) {
                coordonnees.push_back({i, j});
                // cout<<i<<';'<<j<<endl;
            }
        }
    }
    return coordonnees;
}

/**
 * @brief Met à jour l'état du plateau en fonction des positions des robots.
 * @param robots Un vecteur contenant les robots présents sur le plateau.
 */
void Plateau::majPlateau(const std::vector<Robot*>& robots) {
    // 1) Nettoyer les anciennes positions des robots
    for (int i = 0; i < 32; ++i) {
        for (int j = 0; j < 32; ++j) {
            if (grille[i][j] >= 4 && grille[i][j] <= 8) {
                grille[i][j] = 1;
            }
        }
    }

    // // 2) Replacer les robots uniquement sur des cases libres (== 1)
    // for (auto robot : robots) {
    //     int lx = robot->getX();
    //     int ly = robot->getY();
    //     int gx = 1 + 2 * lx;
    //     int gy = 1 + 2 * ly;

    //     // Vérifie les bornes
    //     if (gx >= 0 && gx < 32 && gy >= 0 && gy < 32) {
    //         if (grille[gx][gy] == 1) {
    //             grille[gx][gy] = 4 + robot->getCouleur();
    //         } else {
    //             std::cerr << "Impossible de placer robot à (" << lx << ", " << ly 
    //                       << ") : case occupée (valeur=" << grille[gx][gy] << ")\n";
    //         }
    //     } else {
    //         std::cerr << "Coordonnées hors limites : (" << lx << ", " << ly << ")\n";
    //     }
    // }
}

/**
 * @brief Place les tuiles objectifs sur le plateau.
 * @param tuilesPlacees Un vecteur de tuiles à placer sur le plateau.
 */
void Plateau::placerTuilesObjectif(vector<Tuile_objectif>& tuilesPlacees) {
    // Récupère toutes les positions valides (cases == 3)
    vector<pair<int, int>> emplacements = getCoordonneesCases(3);

    // Vérifie qu’il y a au moins 16 emplacements disponibles
    if (emplacements.size() < 16) {
        cerr << "Erreur : pas assez d’emplacements disponibles pour placer les 16 tuiles objectif." << endl;
        return;
    }

    // Prépare toutes les combinaisons de tuiles (4 couleurs × 4 symboles)
    vector<Tuile_objectif> toutesTuiles;
    for (int s = 0; s < 4; ++s) { // symboles : 0 à 3
        for (int c = 0; c < 4; ++c) { // couleurs : 0 à 3 (exclut MULTICOLORE)
            toutesTuiles.emplace_back(0, 0, static_cast<TypeCouleur>(c), static_cast<TypeSymbole>(s));
        }
    }

    // Place chaque tuile sur un emplacement libre
    for (int i = 0; i < 16; ++i) {
        int gx = emplacements[i].first;
        int gy = emplacements[i].second;

        // Convertir les coordonnées de grille vers coordonnées logiques
        int lx = (gx - 1) / 2;
        int ly = (gy - 1) / 2;

        // Met à jour la position de la tuile
        toutesTuiles[i].setPosition(lx, ly);

        // Calcule la valeur à inscrire dans la grille
        int valeur = 10 * toutesTuiles[i].getSymbole() + toutesTuiles[i].getCouleur();
        grille[gx][gy] = valeur;
        // Ajoute à la liste des tuiles placées
        tuilesPlacees.push_back(toutesTuiles[i]);
        // cout<<"valeur associée à la tuile "<<valeur<<':';
        // printTuile(&tuilesPlacees[i]);
    }
}

/**
 * @brief Retourne la valeur de la case à une position donnée.
 * @param i La coordonnée de la ligne.
 * @param j La coordonnée de la colonne.
 * @return La valeur de la case à la position (i, j).
 */
int Plateau::getGrille(int i, int j) const {
    return grille[i][j];
}


// void Plateau::afficherPlateau()
// {
//     for (int i = 0; i < 32; i++)
//     {
//         for (int j = 0; j < 32; j++)
//         {
//             cout <<"|"<< this->grille[i][j];
//         }
//         cout << endl;
//     }
// }

// void Plateau::placerMurs()
// {
//     int rowStart, rowEnd, colStart, colEnd, quadrant;
//     int choix_cote = rand() % 2;
//     int choix_element;
//     int x, y;
//     quadrant = 1;
//     switch (quadrant)
//     {
//     case 0:
//         rowStart = 0;
//         rowEnd = 16;
//         colStart = 0;
//         colEnd = 16;
//         break; // Haut-gauche

//         if (choix_cote == 1) // Haut de Haut-gauche
//         {
//             choix_element = colStart + rand() % colEnd;
//             x = rowStart + 2;
//             y = choix_element;
//             cout<<x<<endl<<y<<endl;
//         }
//         else // Gauche de Haut-gauche
//         {
//             choix_element = rowStart + rand() % rowEnd;
//             x = choix_element;
//             y = colStart + 2;
//             cout<<x<<endl<<y<<endl;
//         }

//     case 1:
//         rowStart = 0;
//         rowEnd = 16;
//         colStart = 16;
//         colEnd = 32;
//         break; // Haut-droite

//         if (choix_cote == 1) // Haut de Haut-droite
//         {
//             choix_element = colStart + rand() % colEnd;
//             x = rowStart + 2;
//             y = choix_element;
//             cout<<x<<endl<<y<<endl;
//         }
//         else // Droite de Haut-droite
//         {
//             choix_element = rowStart + rand() % rowEnd;
//             x = choix_element;
//             y = colStart - 2;
//             cout<<x<<endl<<y<<endl;
//         }

//     case 2:
//         rowStart = 16;
//         rowEnd = 32;
//         colStart = 0;
//         colEnd = 16;
//         break;               // Bas-gauche
//         if (choix_cote == 1) // Bas de Haut-gauche
//         {
//             choix_element = colStart + rand() % colEnd;
//             x = rowStart - 2;
//             y = choix_element;
//             cout<<x<<endl<<y<<endl;
//         }
//         else // Gauche de Haut-gauche
//         {
//             choix_element = rowStart + rand() % rowEnd;
//             x = choix_element;
//             y = colStart + 2;
//             cout<<x<<endl<<y<<endl;
//         }
//     case 3:
//         rowStart = 16;
//         rowEnd = 32;
//         colStart = 16;
//         colEnd = 32;
//         break;               // Bas-droite
//         if (choix_cote == 1) // Haut de Haut-gauche
//         {
//             choix_element = colStart + rand() % colEnd;
//             x = rowStart - 2;
//             y = choix_element;
//             cout<<x<<endl<<y<<endl;
//         }
//         else // Gauche de Haut-gauche
//         {
//             choix_element = rowStart + rand() % rowEnd;
//             x = choix_element;
//             y = colStart - 2;
//             cout<<x<<endl<<y<<endl;
//         }
//     default:
//     cout<<"non";
//         return;
//     }
//     cout << "indice (" << x << ";" << y << ")" << endl;
//     this->grille[x][y]=2;
// }
