#ifndef LISTE_H_INCLUDED
#define LISTE_H_INCLUDED

#include "joueur.h"

class Saison{
private :
    vector <Joueur> liste;
    string nom;
    vector <int> poids;
    int numSaison;
    string nomFichier;
public :

    void add_joueur(Joueur &j);
    void set_nom(string &nom);
    void set_Poids(string &str);
    void set_numSaison(int numSaison);
    void set_nomFichier(string nomFichier);
    void initSaison(string &line);

    vector <Joueur> get_liste();
    int get_liste_size();
    string get_nom();
    vector <int> get_poids();
    int get_numSaison() const;
    string get_nomFichier();
    
    void duel(int indice1, int indice2);
    void tri();
    void faireClassement();

};


#endif // LISTE_H_INCLUDED
