#include "fonction.h"

/*
- Recherche un caractère dans une chaîne de caractère et renvoie son indice ou la taille de la chaîne s'il n'est pas présent
- c est le caractère recherché, str est la chaîne de caractère dans laquellle on le recherche
- la sortie est un entier
*/
int recherche(const string &str, char c)
{
    int i = -1;
    bool trouve;
    do{
        i++;
        trouve = str[i]==c;
    }while(!trouve && i<str.size());
    if(!trouve)
        i=str.size();
    return i;
}

/*
- cette fonction vérifie que la ligne du fichier définissant la saison comporte bien toute les informations nécessaire, elle ne provoque pas d'erreur s'il y a plus d'informations que nécessaires puisque celles ci ne seront pas traités
- line est la ligne du fichier définissant la saison qui sera vérifié
- la sortie est un booléen qui est vrai s'il n'y a pas d'erreur et faux s'il y en a une
*/
bool verifLigneSaison(string line)
{
  int indSep;
  for(int i=0; i < 2; i++)
  {
    indSep = recherche(line, ',');
    if(indSep < 1 || indSep >= line.size())
    return false;
    line = line.substr(indSep+1, line.size());
  }
  for(int i=0; i<7; i++)
  {
    indSep = recherche(line, '|');
    if(indSep < 1 || indSep >= line.size())
    return false;
    line = line.substr(indSep+1, line.size());
  }
  return true;  
}


/*
- cette fonction vérifie que la ligne du fichier définissant un joueur comporte bien toute les informations nécessaire, elle ne provoque pas d'erreur s'il y a plus d'informations que nécessaires puisque celles ci ne seront pas traités
- line est la ligne du fichier définissant un joueur qui sera vérifié
- la sortie est un booléen qui est vrai s'il n'y a pas d'erreur et faux s'il y en a une
*/
bool verifLigneJoueur(string line)
{
  int indSep;
  indSep = recherche(line, '.');
  if(indSep == 0 || indSep >= line.size())
    return false;
  line = line.substr(indSep+1, line.size());
  for(int i=0; i < 3; i++)
  {
    indSep = recherche(line, ',');
    if(indSep < 1 || indSep >= line.size())
    return false;
    line = line.substr(indSep+1, line.size());
  }
  for(int i=0; i<7; i++)
  {
    indSep = recherche(line, '|');
    if(indSep < 1 || indSep >= line.size())
    return false;
    line = line.substr(indSep+1, line.size());
  }
  return true;  
}