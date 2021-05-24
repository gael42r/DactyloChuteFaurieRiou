//Auteur : Antoine FAURIE
#pragma once

#include <iostream>
#include <iomanip>  
#include <list>
#include<fstream>

#include "Score.h"

using namespace std;

class Scoreboard
{
	//Tableau de pointeurs vers des scores
	list<Score*> scoreboard_;
public:
	Scoreboard();
	~Scoreboard();

	//Afficher le tableau des scores
	void display() const;
	//Ajouter un score
	void addScore(Score*);
	//Sauvegarder les scores
	void save(ofstream& ofs) const;
	//Charger les scores
	void load(ifstream& ifs);
};