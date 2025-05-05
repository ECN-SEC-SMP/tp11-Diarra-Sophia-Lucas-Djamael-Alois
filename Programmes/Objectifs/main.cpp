#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <ctime>
#include "Tuile_objectif.h"

int main() {
    // Initialisation du generateur aleatoire
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // 1) Lister toutes les intersections (angles) de la grille 16×16 → indices 0..16
    std::vector<std::pair<int,int>> allAngles;
    for(int x = 0; x <= MAX_POSITION_X; ++x) {
        for(int y = 0; y <= MAX_POSITION_Y; ++y) {
            allAngles.emplace_back(x, y);
        }
    }

    // 2) Melanger et prendre les 17 premières positions
    std::random_shuffle(allAngles.begin(), allAngles.end());
    allAngles.resize(17);

    // 3) Creation des tuiles
    std::array<Tuile_objectif,17> tiles;

    // 3a) 16 tuiles standards (ROUGE→JAUNE × LOSANGE→ROND)
    int idx = 0;
    for(int c = ROUGE; c <= JAUNE; ++c) {
        for(int s = LOSANGE; s <= ROND; ++s) {
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
    std::set<std::pair<int,int>> posSet;
    for(auto& t : tiles) {
        int x,y;
        t.getPosition(&x,&y);
        posSet.insert({x,y});
    }
    bool positionsUniques = (posSet.size() == tiles.size());

    // 4b) Comptage couleur→symbole
    std::map<TypeCouleur, std::map<TypeSymbole,int>> countMap;
    for(auto& t : tiles) {
        countMap[t.getCouleur()][t.getSymbole()]++;
    }

    // 5) Affichage
    std::cout << "=== Resume des tuiles ===\n";
    std::cout << "Total : " << tiles.size() << " tuiles\n";
    std::cout << "Positions uniques ? " << (positionsUniques ? "OUI" : "NON") << "\n\n";

    std::cout << "Repartition (couleur = symbole) :\n";
    for(int c = ROUGE; c <= MULTICOLORE; ++c) {
        TypeCouleur col = static_cast<TypeCouleur>(c);
        std::cout << " Couleur ";
        switch(col) {
            case ROUGE:        std::cout<<"ROUGE"; break;
            case VERT:         std::cout<<"VERT"; break;
            case BLEU:         std::cout<<"BLEU"; break;
            case JAUNE:        std::cout<<"JAUNE"; break;
            case MULTICOLORE: std::cout<<"MULTICOLORE"; break;
        }
        std::cout << " :\n";
        for(int s = LOSANGE; s <= ROND; ++s) {
            TypeSymbole sym = static_cast<TypeSymbole>(s);
            int cnt = countMap[col][sym];
            std::cout << "   Symbole ";
            switch(sym) {
                case LOSANGE: std::cout<<"LOSANGE"; break;
                case CARRE:   std::cout<<"CARRE  ";   break;
                case ETOILE:  std::cout<<"ETOILE ";  break;
                case ROND:    std::cout<<"ROND   ";    break;
            }
            std::cout << " = " << cnt << "\n";
        }
    }

    std::cout << "\nDetail de chaque tuile :\n";
    for(size_t i = 0; i < tiles.size(); ++i) {
        int x,y;
        string nomCouleur, nomSymbole;

        tiles[i].getPosition(&x,&y);
        
        switch(tiles[i].getSymbole()) {
            case LOSANGE: nomSymbole = "LOSANGE"; break;
            case CARRE:   nomSymbole = "CARRE  ";   break;
            case ETOILE:  nomSymbole = "ETOILE ";  break;
            case ROND:    nomSymbole = "ROND   ";    break;
        }
        switch(tiles[i].getCouleur()) {
            case ROUGE: nomCouleur = "ROUGE"; break;
            case VERT:  nomCouleur = "VERT ";   break;
            case BLEU:  nomCouleur = "BLEU ";  break;
            case JAUNE: nomCouleur = "JAUNE";    break;
            case MULTICOLORE: nomCouleur = "MULTICOLORE";    break;
        }
        std::cout << " Tuile["<<i<<"] @("<<x<<","<<y<<")  Couleur="<<nomCouleur
                  <<"  Symbole="<<nomSymbole<<"\n";
    }

    return 0;
}
