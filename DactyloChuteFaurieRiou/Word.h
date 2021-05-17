#pragma once

#include<iostream>
#include <SFML/Graphics.hpp>
#include <string>

using namespace std;

class Word
{
private:
	string content_;
	sf::Text text_;
	sf::Vector2f pos_;

public:
	Word(string);

	void draw(sf::RenderWindow&);
};
