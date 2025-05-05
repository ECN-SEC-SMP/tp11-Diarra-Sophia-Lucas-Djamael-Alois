#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;



class Sablier{
protected:
    int temps;
public:
    Sablier();

    //affiche le nombre de seconde (timer de 60 secondes quand fonction appelée)
    void start_timer(); 

};