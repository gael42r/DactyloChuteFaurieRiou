#pragma once

#include<SFML/Graphics.hpp>
#include<iostream>
#include<string>


#include"RichText.hpp"

using namespace std;

class Word
{
private:
	string content_;
	sf::Text text_;
	sf::Vector2f pos_;

	int currentCaracter_;

public:
	Word(string);

	void draw(sf::RenderWindow&);

	bool eventTextEntered(sf::RenderWindow&, sf::Event);
};
