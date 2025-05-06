#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <array>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

#include "Jeu.h"

void Jeu::set_Joueurs()
{

    cout << "=== Ajout des joueurs ===" << endl;
    while (true)
    {
        cout << "Entrez le nom du joueur puis entrée pour valider (ou tapez 'commencer la partie' pour démarrer) :" << endl;
        string input;
        getline(cin, input);

        if (input == "commencer la partie")
            break;
        if (!input.empty())
        {
            Joueur j(input, 0, 0); // constructeur avec nom, score, déplacements
            joueurs.push_back(j);
        }
    }
    nbr_joueurs = joueurs.size(); // Mettre à jour le nombre de joueurs
    cout << "Nombre de joueurs : " << nbr_joueurs << endl;
    // Affichage des joueurs
    cout << "\nil y a " << nbr_joueurs << " joueurs dans la partie" << endl;
    cout << "\n=== Liste des joueurs ===" << endl;
    for (size_t i = 0; i < joueurs.size(); ++i)
    {
        cout << "Joueur " << i + 1 << " : " << joueurs[i].getNom() << endl;
    }

    // commencer la partie
    cout << "\n=== Partie commence ===" << endl;
}

// a modifier
void Jeu::init_position_tuile()
{
    // Initialisation du generateur aleatoire
    srand(static_cast<unsigned>(time(nullptr)));

    // 1) Lister toutes les intersections (angles) de la grille 16×16 → indices 0..16
    vector<pair<int, int>> allAngles;
    for (int i = 0; i < 17; i++)
    {
        int x, y;
        for (int i = 0; i < 17; i++)
        {
            this->le_plateau.getPositionAngles(x, y);
            allAngles.emplace_back(x, y);
        }
    }

    // 3) Creation des tuiles
    array<Tuile_objectif, 17> tuiles;

    // 3a) 16 tuiles standards (ROUGE→JAUNE × LOSANGE→ROND)
    int idx = 0;
    for (int c = ROUGE; c <= JAUNE; ++c)
    {
        for (int s = LOSANGE; s <= ROND; ++s)
        {
            // position
            auto p = allAngles[idx];
            tuiles[idx] = Tuile_objectif(p.first, p.second,
                                        static_cast<TypeCouleur>(c),
                                        static_cast<TypeSymbole>(s));
            ++idx;
        }
    }

    // 3b) 1 tuile MULTICOLORE avec symbole aleatoire
    {
        auto p = allAngles[idx];
        TypeSymbole symRandom = static_cast<TypeSymbole>(rand() % (ROND + 1));
        tuiles[idx] = Tuile_objectif(p.first, p.second,
                                    MULTICOLORE,
                                    symRandom);
    }

    // 4) Verifications

    // 4a) Unicite des positions
    set<pair<int, int>> posSet;
    for (auto &t : tuiles)
    {
        int x, y;
        t.getPosition(&x, &y);
        posSet.insert({x, y});
    }
    bool positionsUniques = (posSet.size() == tuiles.size());

    // 4b) Comptage couleur→symbole
    map<TypeCouleur, map<TypeSymbole, int>> countMap;
    for (auto &t : tuiles)
    {
        countMap[t.getCouleur()][t.getSymbole()]++;
    }

    // 5) Affichage
    cout << "=== Resume des tuiles ===\n";
    cout << "Total : " << tuiles.size() << " tuiles\n";
    cout << "Positions uniques ? " << (positionsUniques ? "OUI" : "NON") << "\n\n";

    cout << "Repartition (couleur = symbole) :\n";
    for (int c = ROUGE; c <= MULTICOLORE; ++c)
    {
        TypeCouleur col = static_cast<TypeCouleur>(c);
        cout << " Couleur ";
        switch (col)
        {
        case ROUGE:
            cout << "ROUGE";
            break;
        case VERT:
            cout << "VERT";
            break;
        case BLEU:
            cout << "BLEU";
            break;
        case JAUNE:
            cout << "JAUNE";
            break;
        case MULTICOLORE:
            cout << "MULTICOLORE";
            break;
        }
        cout << " :\n";
        for (int s = LOSANGE; s <= ROND; ++s)
        {
            TypeSymbole sym = static_cast<TypeSymbole>(s);
            int cnt = countMap[col][sym];
            cout << "   Symbole ";
            switch (sym)
            {
            case LOSANGE:
                cout << "LOSANGE";
                break;
            case CARRE:
                cout << "CARRE  ";
                break;
            case ETOILE:
                cout << "ETOILE ";
                break;
            case ROND:
                cout << "ROND   ";
                break;
            }
            cout << " = " << cnt << "\n";
        }
    }

    cout << "\nDetail de chaque tuile :\n";
    for (size_t i = 0; i < tuiles.size(); ++i)
    {
        int x, y;
        string nomCouleur, nomSymbole;

        tuiles[i].getPosition(&x, &y);

        switch (tuiles[i].getSymbole())
        {
        case LOSANGE:
            nomSymbole = "LOSANGE";
            break;
        case CARRE:
            nomSymbole = "CARRE  ";
            break;
        case ETOILE:
            nomSymbole = "ETOILE ";
            break;
        case ROND:
            nomSymbole = "ROND   ";
            break;
        }
        switch (tuiles[i].getCouleur())
        {
        case ROUGE:
            nomCouleur = "ROUGE";
            break;
        case VERT:
            nomCouleur = "VERT ";
            break;
        case BLEU:
            nomCouleur = "BLEU ";
            break;
        case JAUNE:
            nomCouleur = "JAUNE";
            break;
        case MULTICOLORE:
            nomCouleur = "MULTICOLORE";
            break;
        }
        cout << " Tuile[" << i << "] @(" << x << "," << y << ")  Couleur=" << nomCouleur
                  << "  Symbole=" << nomSymbole << "\n";
    }
};

// Constructeur par défaut
Jeu::Jeu()
{
    // Création des robots
    this->robots = creationRobots();
    
    vector<Robot *> robotPtrs;
    robotPtrs = getPointers(this->robots);
    
    // initialisation des tuiles: disposition des 17 tuiles
    init_position_tuile();

    // initialisation du plateau
    Plateau le_plateau;            // creation d'un plateau temporaire
    le_plateau.genererGrille();    // creation d'un plateau de jeu
    le_plateau.placerMur();        // affichage du plateau de jeu
    le_plateau.placerAngle();      // placement des angles
    le_plateau.afficher_plateau(); // affichage du plateau de jeu

    // initialisation de la liste de joueurs en utilisant set_Joueurs
    set_Joueurs(); // initialisation de la liste de joueurs
};

// set tuile objectif_actuel, met a jour la position de cette tuile
// tirer une tuile parmi les 17 et le placer au centre

// set tuile objectif_actuel, met a jour la position de cette tuile
void Jeu::tirer_tuile_objectif()
{
    int random_tuile = rand() % 17;
    // Definir la tuile principale comme étant une tuile aléatoire choisit parmis les 17 tuiles définies
    this->objectif_actuel = this->liste_tuiles_objectifs[random_tuile];
    // Afficher un message informant sur la tuile choisi
    cout << "L'objectif est la tuile de couleur " << objectif_actuel.getCouleur()
         << " et de symbole " << objectif_actuel.getSymbole() << endl
         << "Positionnée en (" << objectif_actuel.get_X() << "; " << objectif_actuel.get_Y() << ")" << endl;
};

// demarre la phase de recherche et activation du sablier
void Jeu::annoncer_Solution()
{
    // Entrer le nombre de deplacement
    le_sablier.start_timer();
};

//
void Jeu::proposer_Solution()
{
    vector<Robot *> robotPtrs;
    robotPtrs = getPointers(this->robots);

    while (true)
    {

        cout << "\nEntrez la couleur du robot a deplacer (rouge, vert, bleu, jaune) ou 'fin' pour terminer : " << endl;
        string couleurInput;
        getline(cin, couleurInput);

        if (couleurInput == "fin")
            break;
        // Convertir la chaine de caractères couleurInput en TypeCouleur
        TypeCouleur couleurRobot;
        if (couleurInput == "rouge")
        {
            couleurRobot = ROUGE;
        }
        else if (couleurInput == "vert")
        {
            couleurRobot = VERT;
        }
        else if (couleurInput == "bleu")
        {
            couleurRobot = BLEU;
        }
        else if (couleurInput == "jaune")
        {
            couleurRobot = JAUNE;
        }
        else
        {
            cout << "Couleur invalide" << endl;
            continue; // Passer à l'itération suivante de la boucle
        }

        cout << "Entrez la direction (haut, bas, gauche, droite) du robot " << couleurInput << " : " << endl;
        string directionInput;
        getline(cin, directionInput);

        robots[couleurRobot].deplacement(directionInput, robotPtrs);
        cout << "Robot " << couleurInput << " : (" << robots[couleurRobot].getX() << ", " << robots[couleurRobot].getY() << ")" << endl;

        le_plateau.afficher_plateau();
    }

    // nombre de deplacements effectues par les 4 robots
    for (size_t i = 0; i < robots.size(); ++i)
    {
        cout << "Robot " << i + 1 << " : "
                  << robots[i].getNombreDeDeplacements()
                  << " deplacements" << endl;
    }

    // nombre de deplacements total
    int total_deplacements = 0;
    for (size_t i = 0; i < robots.size(); ++i)
    {
        total_deplacements += robots[i].getNombreDeDeplacements();
    }
    cout << "Nombre total de deplacements : " << total_deplacements << endl;

    // objectif_courantX = robots[couleurRobot].getX();
    // objectif_courantY = robots[couleurRobot].getY();
    // objectif_courant.Set_position(objectif_courantX, objectif_courantY);
};

// verifier si la position de la tuile objectif actuel est celle de la case objectif
bool Jeu::valider_solution(string NomJoueur)
{
    Joueur *joueur_courant;
    for (int i = 0; i < nbr_joueurs; i++) // La boucle permet de parcourir la liste de joueur
                                          // afin de retrouver le joueur ayant proposé la solution
                                          // à partir de son nom
    {
        if (NomJoueur == this->joueurs[i].getNom())
        {
            joueur_courant = &(this->joueurs[i]);   // joueur_courant pointe sur le 
                                                    // joueur parmi la liste ayant le nom indiqué en paramètre
        }
    }

    if (!((objectif_actuel.get_X() == robots[objectif_actuel.getCouleur()].getX()) && (objectif_actuel.get_Y() == robots[objectif_actuel.getCouleur()].getY())))
    {
        // Si la solution proposé par le joueur n'est pas valide alors son score est décrémenté.
        joueur_courant->setScore(joueur_courant->getScore() - 1); // Décrémentation du score
        cout<<"Proposition invalide : "<<endl;
        cout<<joueur_courant->getNom()<<" vient de perdre 1 point suite à mauvaise proposition!"<<endl;
        cout<<"Son score passe à "<< joueur_courant->getScore()<<endl;
        return false;
    }
    else
    {
        // Si la solution proposé par le joueur est valide alors son score est incrémenté.
        joueur_courant->setScore(joueur_courant->getScore() + 1); // Incrémentation du score
        cout<<"Proposition valide : "<<endl;
        cout<<joueur_courant->getNom()<<" vient de gagner 1 point !"<<endl;
        cout<<"Son score passe à "<< joueur_courant->getScore()<<endl;
        return true;
    }
}

Jeu::~Jeu()
{
    // nothing to do here
}