//Auteur : Antoine FAURIE
#pragma once

#include<iostream>
#include<SFML/Graphics.hpp>
#include<fstream>

#include"Settings.h"
#include"Scoreboard.h"
#include"Score.h"
#include"Game.h"

using namespace std;

class Menu
{
	//Paramètres
	Settings settings_;
	//Tableau des scores
	Scoreboard scoreboard_;

public:
	Menu();

	Settings getSettings() const { return settings_; }

	//Ecran titre
	void title() const;
	//Afficher le menu
	void display() const;
	//Choix du sous-menu
	int enterChoice() const;
	//Modifier le tableau des scores
	void editScoreboard(Score*);
	//Jouer
	void play();
	//Modifier les paramètres
	void setUp();
	//Voir le tableau des scores
	void goToScoreboard() const;
	//Sauvegarder les scores
	void save() const;
	//Charger les scores
	void load();
};