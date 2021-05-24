#pragma once

#include<SFML/Graphics.hpp>
#include<iostream>
#include<string>

//Biblioth�que permettant de g�rer plusieurs couleurs pour un m�me mot (impossible pour un sf::Text)
#include"RichText.hpp"

using namespace std;

class Word
{
	//Contenu d'un mot
	string content_;
	//Texte du mot
	sfe::RichText text_;
	//Position du mot
	sf::Vector2f pos_;
	//Caract�re courant du mot
	int currentCaracter_;


	bool isTextAlreadyAssigned_;
	bool isTextUpdated_;

public:
	Word(string);

	float getPosY() const { return pos_.y; }
	int getNumberOfChar() const { return content_.length(); }

	//Dessiner le mot courant
	void drawCurrent(sf::RenderWindow&);
	//Dessiner un mot en jeu
	void draw(sf::RenderWindow&);
	//Evenement de saisie
	bool eventTextEntered(sf::RenderWindow&, sf::Event);
};
