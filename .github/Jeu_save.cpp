
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
using namespace std;

#include "Jeu.h"



// Fonction pour vérifier si une position est libre pour eviter le chevauchement
bool estPositionLibre(int x, int y, const std::vector<Robot>& robots) {
    for (const auto& robot : robots) {
        if (robot.getX() == x && robot.getY() == y)
            return false; // Position occupée
    }
    return true; // Position libre
}



void Jeu::set_Joueurs(){
    
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
    nbr_joueurs = joueurs.size(); // Mettre à jour le nombre de joueurs
    cout<< "Nombre de joueurs : " << nbr_joueurs << endl;
    // Affichage des joueurs
    cout << "\nil y a " <<  << " joueurs dans la partie" << endl;
    cout << "\n=== Liste des joueurs ===" << endl;
    for (size_t i = 0; i < joueurs.size(); ++i) {
        cout << "Joueur " << i + 1 << " : " << joueurs[i].getNom() << endl;
    }
    
    //commencer la partie
    cout << "\n=== Partie commence ===" << endl;
 }


//a modifier
void Jeu::init_position_tuile()
{
    // Initialisation du generateur aleatoire
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // 1) Lister toutes les intersections (angles) de la grille 16×16 → indices 0..16
    std::vector<std::pair<int, int>> allAngles;
    for (int i = 0; i < 17; i++)
    {
        int x, y;
        for (int i = 0; i < 17; i++)
        {
            this->le_plateau.getPosition(x,y);
            allAngles.emplace_back(x,y);    
        }
    }

    // 3) Creation des tuiles
    std::array<Tuile_objectif, 17> tiles;

    // 3a) 16 tuiles standards (ROUGE→JAUNE × LOSANGE→ROND)
    int idx = 0;
    for (int c = ROUGE; c <= JAUNE; ++c)
    {
        for (int s = LOSANGE; s <= ROND; ++s)
        {
            // position
            auto p = allAngles[idx];
            tiles[idx] = Tuile_objectif(p.first, p.second,
                                        static_cast<TypeCouleur>(c),
                                        static_cast<TypeSymbole>(s));
            ++idx;
        }
    }

    // 3b) 1 tuile MULTICOLORE avec symbole aleatoire
    {
        auto p = allAngles[idx];
        TypeSymbole symRandom = static_cast<TypeSymbole>(std::rand() % (ROND + 1));
        tiles[idx] = Tuile_objectif(p.first, p.second,
                                    MULTICOLORE,
                                    symRandom);
    }

    // 4) Verifications

    // 4a) Unicite des positions
    std::set<std::pair<int, int>> posSet;
    for (auto &t : tiles)
    {
        int x, y;
        t.getPosition(&x, &y);
        posSet.insert({x, y});
    }
    bool positionsUniques = (posSet.size() == tiles.size());

    // 4b) Comptage couleur→symbole
    std::map<TypeCouleur, std::map<TypeSymbole, int>> countMap;
    for (auto &t : tiles)
    {
        countMap[t.getCouleur()][t.getSymbole()]++;
    }

    // 5) Affichage
    std::cout << "=== Resume des tuiles ===\n";
    std::cout << "Total : " << tiles.size() << " tuiles\n";
    std::cout << "Positions uniques ? " << (positionsUniques ? "OUI" : "NON") << "\n\n";

    std::cout << "Repartition (couleur = symbole) :\n";
    for (int c = ROUGE; c <= MULTICOLORE; ++c)
    {
        TypeCouleur col = static_cast<TypeCouleur>(c);
        std::cout << " Couleur ";
        switch (col)
        {
        case ROUGE:
            std::cout << "ROUGE";
            break;
        case VERT:
            std::cout << "VERT";
            break;
        case BLEU:
            std::cout << "BLEU";
            break;
        case JAUNE:
            std::cout << "JAUNE";
            break;
        case MULTICOLORE:
            std::cout << "MULTICOLORE";
            break;
        }
        std::cout << " :\n";
        for (int s = LOSANGE; s <= ROND; ++s)
        {
            TypeSymbole sym = static_cast<TypeSymbole>(s);
            int cnt = countMap[col][sym];
            std::cout << "   Symbole ";
            switch (sym)
            {
            case LOSANGE:
                std::cout << "LOSANGE";
                break;
            case CARRE:
                std::cout << "CARRE  ";
                break;
            case ETOILE:
                std::cout << "ETOILE ";
                break;
            case ROND:
                std::cout << "ROND   ";
                break;
            }
            std::cout << " = " << cnt << "\n";
        }
    }

    std::cout << "\nDetail de chaque tuile :\n";
    for (size_t i = 0; i < tiles.size(); ++i)
    {
        int x, y;
        string nomCouleur, nomSymbole;

        tiles[i].getPosition(&x, &y);

        switch (tiles[i].getSymbole())
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
        switch (tiles[i].getCouleur())
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
        std::cout << " Tuile[" << i << "] @(" << x << "," << y << ")  Couleur=" << nomCouleur
                  << "  Symbole=" << nomSymbole << "\n";
    }
};



    // Constructeur par défaut
Jeu::Jeu(){


    //reprendre la fonction creationRobot de la branche main_test de 
    //intialisation des robots
    srand(time(0)); // Initialisation du générateur aléatoire
    for (int i = 0; i < 4; ++i) {
        int x, y;
        do {
            x = rand() % 16;
            y = rand() % 16;
        } while (!estPositionLibre(x, y, this->robots)); // Vérifie la position dans le vecteur déjà créé
 
        robots.push_back(Robot(x, y, static_cast<TypeCouleur>(i))); // Crée un robot avec une couleur différente
    }
    return robots; // Retourne la liste créée
    
    //initialisation des tuiles: disposition des 17 tuiles
    Jeu.init_position_tuile();

    //initialisation du plateau
    Plateau le_plateau; //creation d'un plateau temporaire
    le_plateau.genererGrille(); //creation d'un plateau de jeu
    le_plateau.placerMur(); //affichage du plateau de jeu
    le_plateau.placerAngle(); //placement des angles
    le_plateau.afficher_plateau(); //affichage du plateau de jeu

    //initialisation de la liste de joueurs en utilisant set_Joueurs
    set_Joueurs(); //initialisation de la liste de joueurs
    //initialisation du sablier
    le_sablier.Sablier(); //init le sablier a 0
};

//set tuile objectif_actuel, met a jour la position de cette tuile
//tirer une tuile parmi les 17 et le placer au centre 

// set tuile objectif_actuel, met a jour la position de cette tuile
Tuile_objectif Jeu::Tuile_objectif tirer_tuile_objectif()
{
    int random_tuile = rand()%17;
    this->objectif_actuel = this->liste_tuiles_objectifs[random_tuile];
    tuile_couleur= objectif_actuel.get_couleur();
    tuile_symbole= objectif_actuel.get_symbole();
};

 //demarre la phase de recherche et activation du sablier
void Jeu::annoncer_Solution(){
    //Entrer le nombre de deplacement
    le_sablier.activer_Sablier();
};

 //
void Jeu::proposer_Solution(){
    
while (true) {

    cout << "\nEntrez la couleur du robot a deplacer (rouge, vert, bleu, jaune) ou 'fin' pour terminer : " << endl;
    string couleurInput;
    getline(cin, couleurInput);

    if (couleurInput == "fin") break;
    // Convertir la chaine de caractères couleurInput en TypeCouleur
    TypeCouleur couleurRobot;
    if (couleurInput == "rouge") {
        couleurRobot = ROUGE;
    } else if (couleurInput == "vert") {
        couleurRobot = VERT;
    } else if (couleurInput == "bleu") {
        couleurRobot = BLEU;
    } else if (couleurInput == "jaune") {
        couleurRobot = JAUNE;
    } else {
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

//nombre de deplacements effectues par les 4 robots
for(size_t i = 0; i < robots.size(); ++i) {
    std::cout << "Robot " << i+1 << " : " 
                << robots[i].getNombreDeDeplacements() 
                << " deplacements" << std::endl;
}

//nombre de deplacements total
int total_deplacements = 0;
for(size_t i = 0; i < robots.size(); ++i) {
    total_deplacements += robots[i].getNombreDeDeplacements();
}
cout << "Nombre total de deplacements : " << total_deplacements << endl;

objectif_courantX = robots[couleurRobot].getX();
objectif_courantY = robots[couleurRobot].getY();
objectif_courant.Set_position(objectif_courantX,objectif_courantY);
};


//verifier si la position de la tuile objectif actuel est celle de la case objectif
void Jeu::valider_solution(Tuile_objectif objectif_courant){
    posX= objectif_actuel.get_X();
    posY= objectif_actuel.get_Y();
    if ((posX,posY)= (objectif_courant.get_X(),objectif_courant.get_Y())){
        cout << "Solution incorrecte" << endl;
};
}

Jeu::~Jeu() {
    //nothing to do here
}
