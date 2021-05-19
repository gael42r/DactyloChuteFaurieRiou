#pragma once

#include<SFML/Graphics.hpp>
#include<iostream>
#include<string>


#include"RichText.hpp"
#include"FText.h"

using namespace std;

class Word
{
private:
	string content_;
	sfe::RichText text_;
	sf::Vector2f pos_;

	int currentCaracter_;

	bool isTextAlreadyAssigned_;
	bool isTextUpdated_;

public:
	Word(string);

	void draw(sf::RenderWindow&);

	bool eventTextEntered(sf::RenderWindow&, sf::Event);
};
