#pragma once

#include<iostream>
#include <SFML/Graphics.hpp>
#include <string>

using namespace std;

class Word
{
private:
	string content_;
	sf::Vector2i position_;
	sf::Text text_;
	int state_;
public:
	Word(string);

	string getContent() const { return content_; }

	void draw(sf::RenderWindow&);
	void editState(int);
};
