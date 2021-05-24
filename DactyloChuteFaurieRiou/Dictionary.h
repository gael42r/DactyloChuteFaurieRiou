//Auteur : Gaël RIOU
#pragma once

#include <fstream>
#include <list>
#include <vector>

#include"Word.h"

class Dictionary
{
	//Tableau de poiteurs de mots
	vector<Word*> word_;
	//Tableau de poiteurs des mots à l'écran (mots en jeu)
	list<Word*> onScreenWords_;
	//Nombre de caractères du dernier mots tapé
	int numberCharLastWord_;

public:
	Dictionary(int = 1);

	int getNumberCharLastWord() const { return numberCharLastWord_; }

	//Dessiner les mots en jeu
	void drawWords(sf::RenderWindow&);
	//Ajouter un nouveau mot en jeu
	void addNewWordToList();
	//Eliminer un mot en jeu
	void deleteCurrentWord();
	//Evenement de saisie
	bool eventTextEntered(sf::RenderWindow&, sf::Event);
	//Vérifier si le mot courant est hors jeu
	bool isCurrentWordOutOfScreen();
	//Supprimer les mots hors jeu
	void deleteOutOfScreenWords();
};