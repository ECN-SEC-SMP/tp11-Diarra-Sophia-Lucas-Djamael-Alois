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

#include "jeu.h"

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

Jeu::Jeu()
{

    // === Étape 1 : Créer les robots (liste de 4 robots de couleurs différentes)
    this->robots = creationRobots();
    
    for (auto& robot : this->robots) {
        this->le_plateau.placerRobot(&robot);
    }

    // === Étape 2 : Initialisation des positions de tuiles
    le_plateau.placerTuilesObjectif(this->liste_tuiles_objectifs);



    // === Étape 8 : Afficher le plateau et légendes
    std::cout << "\n=== Plateau généré ===\n";
    afficherLegendePlateau();
    le_plateau.afficherPlateau();

    // === Étape 9 : Ajouter les joueurs
    set_Joueurs();
}


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

        le_plateau.majPlateau(getPointers(robots));
        le_plateau.afficherPlateau();
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

        // Affichage des scores des joueurs
        cout << "\nil y a " << joueurs.size() << " joueurs dans la partie" << endl;
        cout << "\n=== Recapitulatif des scores des joueurs ===" << endl;
        for (size_t i = 0; i < joueurs.size(); ++i) {
            cout << "Joueur " << i + 1 << " : " << joueurs[i].getNom() << " - Score : " << joueurs[i].getScore() << endl;
        }
        return true;
    }
}

//Jeu::~Jeu()
//{
    // nothing to do here
//}

void Jeu::afficherLegendePlateau() {
    std::cout << "\n=== LÉGENDE ===\n";
    std::cout << "R = Robot Rouge      V = Vert    B = Bleu     J = Jaune\n";
    std::cout << "L = Losange          C = Carré   E = Étoile   R = Rond\n";
    std::cout << "# = Mur              espace = Vide\n\n";
}
