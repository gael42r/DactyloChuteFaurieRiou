//Auteur : Ga�l RIOU
#pragma once

#include <iostream>
#include <string>

using namespace std;

class Settings
{
	//Difficult�
	int difficulty_;
	string strDifficulty_;
	//Vitesse
	int speed_;
	//Difficult� des mots
	int wordsDifficulty_;

public:
	Settings(int = 1);

	string getStrDifficulty() const { return strDifficulty_; }
	int getDifficulty() const { return difficulty_; }

	//Afficher les param�tres
	void display() const;
	//Modifier les param�tres
	bool edit();
};