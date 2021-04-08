#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <stdexcept>

#include "joueur.h"
#include "saison.h"
#include "fonction.h"

using namespace std;
const string MESSAGE_EXPLICATIF = "Vous devez spécifiez des fichiers d'entrée au format .csv comme ceci :\n<nom programme> <nom fichier>\nVous pouvez ajoutez autant de fichiers que vous le souhaitez en les séparant d'un espace";
const int NBTACHES = 8;

int main(int argc, char* argv[])
{
  //vérification qu'il y ait au moins un fichier en entrée
  if(argc < 2)
  {
    cout << MESSAGE_EXPLICATIF << endl;
    return 1;
  }

  //sauvegarde du nom des fichiers dans le vecteur nomsFichiers et vérifications qu'il n'y est que des fichiers dont l'extension est .csv
  int cptFichier;
  vector <string> nomsFichiers;
  
  
  // Verification de l'extension du fichier
  try
  {
    for(int i=1; i < argc; i++)
    {
      string extension, arg = argv[i];
      int point = recherche(arg, '.');
      if(point == arg.size())
        throw int(1);
      extension = arg.substr(point,arg.size());
      if(extension != ".csv")
        throw int(2);
    
     nomsFichiers.push_back(arg.substr(0,point));
    }
  }
  catch(int n)
  {
    if(n == 1)
    {
      cout << "Un des paramètres n'est pas un fichier" << endl;
      cout << MESSAGE_EXPLICATIF << endl;
      exit(1);
    }
    if(n == 2)
    {
      cout << "Un fichier à une mauvaise extrension, seul les fichiers au format .csv sont acceptés" << endl;
      cout << MESSAGE_EXPLICATIF << endl;
      exit(1);
    }
  }
  
  //boucle qui s'éxecute une fois par fichier en entrée
  for(cptFichier = 1; cptFichier < argc; cptFichier++)
  {
	  // read file
	  
    Saison saison;
    // definition du fichier qui sera traité lors de cette itération
	  string csv_filename = argv[cptFichier];

	  ifstream csv(csv_filename);
	  if(!csv.is_open())
	  {
	  	cout << "csv file not found" << endl;
	  	exit(1);
	  }

	  string line;
    bool debut = true, vide = true;
	  while(getline(csv, line))
	  {
      vide = false;
		  // TODO: loop over lines in file
      /*conditionelle pour separer la premiere ligne qui contient les info sur la saison de Swan et les suivantes qui contiennent les info des joueurs*/
      if(debut)
      {
        if(!verifLigneSaison(line))
        {
          cout << "La première ligne :" << endl << line << endl << "comportant les informations sur la saison dans le fichier " << argv[cptFichier] << " n'a pas une structure correcte" << endl;
          exit (1);
        }
        saison.initSaison(line);
        debut = false;
      }
      else
      {
        if(!verifLigneJoueur(line))
        {
          cout << "La ligne :" << endl << line << endl << "comportant des informations sur un joueur dans le fichier " << argv[cptFichier] << " n'a pas une structure correcte" << endl;
          exit (1);
        }
        int ind;
        string login, surnom, strImage, strStrat;
        //separation de chaque information des joueurs en differentes variables
        ind = recherche(line,',');
        login = line.substr(0,ind);
        for(int i=0;i<=ind;i++)
          line.erase(line.begin());
        ind = recherche(line,',');
        surnom = line.substr(0,ind);
        for(int i=0;i<=ind;i++)
          line.erase(line.begin());
        ind = recherche(line,',');
        strImage = line.substr(0,ind);
        for(int i=0;i<=ind;i++)
          line.erase(line.begin());
        ind = recherche(line,',');
        strStrat = line.substr(0,ind);
        //creation d'un joueur avec les informations recupere
        Joueur j(login,surnom,strImage,strStrat);
        //ajout du joueur dans la saison
        saison.add_joueur(j);
      }
	  }
    if(vide)
    {
      cout << "Un des fichiers est vide" << endl;
      cout << MESSAGE_EXPLICATIF << endl;
      return 1;
    }
    //On effectue les duel entre chaque joueur
    int i, j;
    for(i=0; i<saison.get_liste_size(); i++)
      for(j=i+1; j<saison.get_liste_size(); j++)
        saison.duel(i,j);
    //tri des joueurs selon leurs score
    saison.tri();
    //classement des joueurs selon leurs points
    saison.faireClassement();


	  // write file
	  string html_filename = nomsFichiers[cptFichier-1] + ".html";
    

	  ofstream html(html_filename);
	  if(!html.is_open())
	  {
	  	cout << "could not open html file" << endl;
	  	exit(1);
	  }




    html << "<!DOCTYPE html>" << endl;
	  html << "<html lang='fr'>" << endl;

	  // TODO
  
    html << "\t<head>" << endl;
    html << "\t\t<link href='style.css' rel='stylesheet' media='all' type='text/css'> " << endl;
    html << "\t\t<title>Projet Tuteuré</title>" << endl;
    html << "\t</head>" << endl << endl;
	  html << "\t<body>" << endl << endl;


    // Menu navigation

    html << "\t<header>" << endl;
    html << "\t\t<nav id='MenuNav'>" << endl;
    
    html << "\t\t<ul>" << endl;
    
    // logo Swan
    html << "\t\t\t<li class='logo'> " << endl;
    html << "\t\t\t\t<img id='logo' src='https://projet.iut-orsay.fr/Swan/Logo.svg'" << endl;
    html << "\t\t\t\t\talt='Logo'" << endl;
    html << "\t\t\t\t\twidth='130'" << endl;
    html << "\t\t\t\t\theight='130'>" << endl;
    html << "\t\t\t</li> " << endl;

    // S'il y a au moins 2 fichiers, on créé un menu en fonction des noms des fichiers
    if(nomsFichiers.size() > 1){
      for(int i=0; i<nomsFichiers.size();i++){
        html << "\t\t\t<li class='Menu'><a href='"<< nomsFichiers[i] <<".html'> " << nomsFichiers[i]<<" </a></li>"<< endl;
      }
    }


    html << "\t\t</ul>" << endl;

    html << "\t\t</nav>" << endl;
    html << "\t</header>" << endl << endl;




    // Affichage saison
    html << "\t<h2> " << saison.get_nom()<< " </h2>" << endl << endl;

    // Affichage de son poids
    html << "\t<h3> ";
    for(int i=0; i < NBTACHES-1; i++){
      html << saison.get_poids()[i]<< " | ";
    }
    html << saison.get_poids()[NBTACHES-1];
    html <<" </h3>" << endl << endl;




    // Début tableau
    html << "\t\t<table>" << endl;
  
    // En-tête du tableau
    html << "\t\t\t<tr>" << endl;
    html << "\t\t\t\t<th> Classement </th>" << endl;
    html << "\t\t\t\t<th> Joueurs </th>" << endl;
    html << "\t\t\t\t<th> Images </th>" << endl;
    html << "\t\t\t\t<th> Points </th>" << endl;
    html << "\t\t\t\t<th> Stratégies </th>" << endl;
    html << "\t\t\t</tr>" << endl << endl;

    // Pour chaque ligne du classement
	  for(int cpt=0; cpt<saison.get_liste_size(); cpt++){
      html << "\t\t\t<tr>" << endl;

      // Classement avec 1er, 2ème, 3ème,...
      if((saison.get_liste())[cpt].get_position()==1){
        html << "\t\t\t\t<td class='info'> " << 1 << "er </td>" << endl;
      }
      else {
      html << "\t\t\t\t<td class='info'> " << ((saison.get_liste())[cpt]).get_position() << "ème </td>" << endl;
      }


      // Noms des joueurs 
      html << "\t\t\t\t<td class='info'> " <<  ((saison.get_liste())[cpt]).get_surnom() << " </td>" << endl;


      // Leurs images
      // renvoie 0 si pas d'image et 1 si image
      if(((saison.get_liste())[cpt]).get_image()){
        html << "\t\t\t\t<td> " << "<img src='https://projet.iut-orsay.fr/photos/" << ((saison.get_liste())[cpt]).get_login() << ".jpg' alt='Bug affichage image' height='105' width='135' > "<< " </td>" << endl;
      }
      else{
        html << "\t\t\t\t<td> " << "<div class='carre'></div> "<< " </td>" << endl;
      }


      // Leurs nombres de points
      html << "\t\t\t\t<td class='info'> " << ((saison.get_liste())[cpt]).get_score() << " </td>" << endl;


      // Leurs stratégies
      html << "\t\t\t\t<td> ";
      for(int i=0; i < NBTACHES-1; i++){
        html << ((saison.get_liste())[cpt]).get_strat()[i] << "|";
      }
      html << ((saison.get_liste())[cpt]).get_strat()[NBTACHES-1];
      html << " </td>"<< endl;
    

      html << "\t\t\t</tr>" << endl << endl;
    }

    html << "\t\t</table>" << endl;
  
    // Fin tableau


	  html << "\t</body>" << endl;

	  html << "</html>";

  }
}
