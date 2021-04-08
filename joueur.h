#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "fonction.h"

using namespace std;

class Joueur {
private :
    string login;
    string surnom;
    bool image;
    vector <int> strat;
    int score;
    int position;
public :
    Joueur(string &login,string &surnom, string &image, string &strStrat);

    void set_login(string &login_);
    void set_surnom(string &surnom_);
    void set_image(string &image_);
    void set_strat(string &strStrat);
    void set_position(int position_);
    void add_score(int points);

    void TacheStrToInt(string &str);

    string get_login() const;
    string get_surnom() const;
    bool get_image() const;
    vector <int> get_strat() const;
    int get_score() const;
    int get_position() const;

};


bool operator<(const Joueur &j1, const Joueur &j2);
bool operator==(Joueur &j1, Joueur &j2);
bool operator!=(Joueur &j1, Joueur &j2);

#endif // JOUEUR_H_INCLUDED
