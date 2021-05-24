//Auteur : Gaël RIOU
#pragma once

#include <iostream>
#include <string>

using namespace std;

class Settings
{
	//Difficulté
	int difficulty_;
	string strDifficulty_;
	//Vitesse
	int speed_;
	//Difficulté des mots
	int wordsDifficulty_;

public:
	Settings(int = 1);

	string getStrDifficulty() const { return strDifficulty_; }
	int getDifficulty() const { return difficulty_; }

	//Afficher les paramètres
	void display() const;
	//Modifier les paramètres
	bool edit();
};