#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED

#include <iostream>
#include <string>
#include <fstream>
#include <vector>


using namespace std;

int recherche(const string &str, char c);
bool verifLigneJoueur(string line);
bool verifLigneSaison(string line);

#endif // FONCTION_H_INCLUDED
