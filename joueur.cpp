#include "joueur.h"

/*
- Constructeur de la classe Joueur qui utilise les differente fonction set pour initialiser les valeurs des variables a partir de string et initialise le score a 0
- login représente le login du joueur, surnom représente le surnom du joueur, image est soit 1 soit 0 et représente la présence ou non d'une image pour ce joueur sur l'adresse projet.iut-orsay.fr/photos/login , strStrat représente la stratégie du joueur en chaîne de carctères
- cette fonction n'a pas de sortie
*/
Joueur::Joueur(string &login,string &surnom, string &image, string &strStrat)
{
    this->set_login(login);
    this->set_surnom(surnom);
    this->set_image(image);
    this->set_strat(strStrat);
    this->score = 0;
}

/*
Modifie le login du joueur
login_ devient le nouveau login du joueur
- cette fonction n'a pas de sortie
*/
void Joueur::set_login(string &login_)
{
    this->login=login_;
}

/*
- Modifie le surnom du joueur
- surnom_ devient le nouveau surnom du joueur
- cette fonction n'a pas de sortie
*/
void Joueur::set_surnom(string &surnom_)
{
    this->surnom=surnom_;
}

/*
- Modifie le booléen image associé à un joueur, ce booléen à la valeur vrai si le joueur à une image à l'adresse projet.iut-orsay.fr/photos/login et faux s'il n'en a pas
- image_ est soit égale à 1 soit à 0, 1 correspond à vrai et 0 à faux
- cette fonction n'a pas de sortie
*/
void Joueur::set_image(string &image_)
{
    this->image=(image_=="1");
}



/*
- isole ce qui ce se trouve avant le caractere '|' dans le string str 
et le transforme en int pour l'ajouter a la strategie du joueur
- str représente une tâche de la stratégie d'un joueur sous forme de chaîne caractère, avec en général le caractère délimiteur '|' à la fonction
- cette fonction n'a pas de sortie
*/
void Joueur::TacheStrToInt(string &str)
{
    int sep;
    sep = recherche(str,'|');
    this->strat.push_back(stoi(str.substr(0,sep)));
    if(sep!=str.size())
        for(int i=0;i<=sep;i++)
            str.erase(str.begin());
    return;
}

/* 
- converti le string strStrat en un vecteur d'entier representant 
la strategie du joueur a l'aide de la fonction TacheStrToInt
- strStrat correspond à la stratégie du joueur sous forme de chaîne de caractère
- cette fonction n'a pas de sortie
*/
void Joueur::set_strat(string &strStrat){
    const int NBTACHES = 8;
    int i;
    for(i=0 ; i < NBTACHES; i++)
        TacheStrToInt(strStrat);
    return;
}

/*
- cette fonction retourne le login du joueur
- cette fonction n'a pas d'arguments
- la sortie est un string
*/
string Joueur::get_login() const
{
    return(this->login);
}

/*
- cette fonction retourne le surnom du joueur
- cette fonction n'a pas d'arguments
- la sortie est un string
*/
string Joueur::get_surnom() const
{
    return(this->surnom);
}

/*
- retourne true si le joueur a une image, false s'il n'en a pas
- cette fonction n'a pas d'arguments
- la sortie est un booléen
*/
bool Joueur::get_image() const
{
    return(this->image);
}

/*
- cette fonction retourne la strategie du joueur sous forme d'un vecteur d'entier
- cette fonction n'a pas d'arguments
- la sortie est un vecteur d'entier 
*/
vector <int> Joueur::get_strat() const
{
    return(this->strat);
}

/*
- cette fonction retourne le score du joueur
- cette fonction n'a pas d'arguments
- la sortie est un entier
*/
int Joueur::get_score() const
{
    return(this->score);
}

/*
- cette fonction permet d'ajouter des points au score d'un joueur
- points correspond au nombre de points à ajouter au score du joueur
- cette fonction  n'a pas de sortie
*/
void Joueur::add_score(int points)
{
    this->score += points;
    return;
}

/*
Cet opérateur compare les scores des joueurs j1 et j2, il renvoie vrai si le score de j1 est inférieur à celui de j2 et faux sinon
*/
bool operator<(const Joueur &j1, const Joueur &j2)
{
    return(j1.get_score() < j2.get_score());
}

/*
Cet opérateur compare les scores des joueurs j1 et j2, il renvoie vrai si le score de j1 est égal à celui de j2 et faux sinon
*/
bool operator==(Joueur &j1, Joueur &j2)
{
    return(j1.get_login() == j2.get_login());
}

/*
Cet opérateur compare le login des joueurs j1 et j2, il renvoie faux si le login de j1 est le même que celui de j2 et vrai sinon
*/
bool operator!=(Joueur &j1, Joueur &j2)
{
    return(!(j1 == j2));
}

/*
- cette fonction modifie la position du joueur
- position_ devient la nouvelle position du joueur
- cette fonction n'a pas de sortie
*/
void Joueur::set_position(int position_)
{
  this->position = position_;
}

/*
- cette fonction retourne la position du joueur
- cette fonction n'a pas d'arguments
- la sortie est un entier 
*/
int Joueur::get_position() const
{
  return(this->position);
}

