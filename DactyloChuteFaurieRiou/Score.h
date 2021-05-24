#pragma once

#include<iostream>
#include<iomanip>  
#include<ctime>
#include<string>
#include<fstream>

using namespace std;

class Score
{
	//Nom du joueur
	string player_;
	//Nombre caractères tapés (caractères par minutes)
	int numberOfChar_;
	//Nombre de caractères par secondes
	float charPerSec_;
	//Difficulté
	string difficulty_;
	//Date
	string date_;

public:
	Score(string = "Unknown" , string = "Unknown", int = 0);
	Score(const Score&);

	int getNumberOfChar() const { return numberOfChar_; }
	void setPlayer(string str) { player_ = str; }

	//Afficher un score
	void display() const;
	//Augmenter le score
	void up(int);
	//Sauvegarder un score
	void save(ofstream& ofs) const;
	//Charger un score
	void load(ifstream& ifs);
};
