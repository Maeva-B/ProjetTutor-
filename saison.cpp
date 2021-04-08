#include "saison.h"

/*
- cette fonction récupère les informations d'une chaîne de caractères pour assigner un nom, un numéro et un poids à la saison
- line est une chaîne de caractère contennat le nom, le numéro et le poids de la saison séparé par des virgules
- cette fonction n'a pas de sortie
*/
void Saison::initSaison(string &line)
{
  int ind;
	string numSaison,nomSaison,poids;

  ind = recherche(line,',');
  numSaison = line.substr(0,ind);
  this->numSaison = stoi(numSaison);
  for(int i=0;i<=ind;i++)
    line.erase(line.begin());
  ind = recherche(line,',');
  nomSaison = line.substr(0,ind);
  this->nom = nomSaison;
  for(int i=0;i<=ind;i++)
    line.erase(line.begin());
  ind = recherche(line,',');
  poids = line.substr(0,ind);
  this->set_Poids(poids);
}

/*
- cette fonction ajoute le joueur j a la liste de joueur de cette saison
- j est le joueur qui va être ajouté à la liste
- cette fonction n'a pas de sortie
*/
void Saison::add_joueur(Joueur &j)
{
    this->liste.push_back(j);
    return;
}

/*
- cette fonction effectue un duel entre deux joueurs de la liste de joueurs de la saison et leur attribut des points selon le résultat du duel
- indice1 est l'indice du premier joueur participant au duel et indice2 est l'indice du second joueur participant au duel
- cette fonction n'a pas de sortie 
*/
void Saison::duel(int indice1, int indice2)
{
    Joueur j1 = this->liste[indice1], j2 = this->liste[indice2];
    int i, score1 = 0, score2 = 0;
    for(i=0; i<j1.get_strat().size(); i++)
    {
        if(j1.get_strat()[i] != j2.get_strat()[i])
        {
            if(j1.get_strat()[i] > j2.get_strat()[i])
                score1 += this->poids[i];
            else score2 += this->poids[i];
        }
    }
    if(score1 != score2)
    {
        if(score1 > score2)
            this->liste[indice1].add_score(2);
        else this->liste[indice2].add_score(2);
    }
    else
    {
        this->liste[indice1].add_score(1);
        this->liste[indice2].add_score(1);
    }
}

/*
- cette fonction modifie le poids des tâches d'une saison
- str correspond au poids des tâches de la saison sous forme de chaîne de caractères avec '|' en tant que caractère délimiteur
- cette fonction n'a pas de sortie
*/
void Saison::set_Poids(string &str)
{
    int i, sep;
    for(i=0;i<8;i++)
    {
        sep = recherche(str,'|');
        this->poids.push_back(stoi(str.substr(0,sep)));
        if(sep!=str.size())
            for(int i=0;i<=sep;i++)
                str.erase(str.begin());
    }
    return;
}

/*
- cette fonction retourne la liste de joueur de la saison
- cette fonction n'a pas d'arguments
- la sortie est un vecteur de joueur
*/
vector <Joueur> Saison::get_liste()
{
    return(this->liste);
}

/*
- cette fonction retourne la taille de la liste de joueur de la saison
- cette fonction n'a pas d'arguments
- la sortie est un entier
*/
int Saison::get_liste_size()
{
    return(this->liste.size());
}

/*
- cette fonction tri dans l'ordre décroissant les joueurs de la liste de joueur de la saion en fonction de leurs scores
- cette fonction n'a pas d'arguments
- cette fonction n'a pas de sortie
*/
void Saison::tri()
{
  int i, j;
  for(i=0; i<this->liste.size()-1;i++)
  {
    int indMaxScore = i;
    for(j=i+1; j<this->liste.size(); j++)
    {
      if( this->liste[indMaxScore] < this->liste[j])
        indMaxScore = j;
    }
    if(indMaxScore != i)
    {
      Joueur temp = this->liste[indMaxScore];
      this->liste[indMaxScore] = this->liste[i];
      this->liste[i] = temp;
    }
  }
}

/*
- cette fonction modifie le nom de la saison
- nom_ devient le nouveau nom de la saison
- cette fonction n'a pas de sortie
*/
void Saison::set_nom(string &nom_)
{
    this->nom = nom_;
    return;
}

/*
- cette fonction retourne le nom de la saison
- cette fonction n'a pas d'arguments
- la sortie est un string
*/
string Saison::get_nom()
{
    return(this->nom);
}

/*
- cette fonction modifie le numéro de la saison
- numSaison_ devient le nouveau numéro de la saison
- cette fonction n'a pas de sortie
*/
void Saison::set_numSaison(int numSaison_)
{
  this->numSaison = numSaison_;
  return;
}

/*
- cette fonction retourne le numéro de la saison
- cette fonction n'a pas d'arguments
- la sortie est un entier
*/
int Saison::get_numSaison() const
{
  return(this->numSaison);
}

/*
- cette fonction fait le classement des joueurs de la saison en leur attribuant une position
- cette fonction n'a pas d'arguments
- cette fonction n'a pas de sortie
*/
void Saison::faireClassement()
{
  int i,position = 1;
  this->liste[0].set_position(1);
  for(i=1; i<this->get_liste_size(); i++)
  {
    if((this->liste[i]).get_score() == (this->liste[i-1]).get_score())
    {
      this->liste[i].set_position(position);
    }
    else
    {
      position++;
      this->liste[i].set_position(position);
    }
  }
}

/*
- cette fonction modifie le nom qui sera donné au fichier correspondant à la saison
- nomFichier devient le nouveau nom qui sera donné au fichier correspondant à la saison
- cette fonction n'a pas de sortie
*/
void Saison::set_nomFichier(string nomFichier)
{
  this->nomFichier = nomFichier;
  return;
}

/*
- cette fonction retourne le nom qui sera donné au fichier correspondant à la saison
- cette fonction n'a pas d'arguments
- la sortie est un string
*/
string Saison::get_nomFichier()
{
  return(this->nomFichier);
}

/*
- cette fonction retourne le poids associé à chaque tâche de la saison
- cette fonction n'a pas d'arguments
- la sortie est un vecteur d'entier
*/
vector <int> Saison::get_poids()
{
  return(this->poids);
}