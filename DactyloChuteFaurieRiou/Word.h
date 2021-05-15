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
	int state_;
public:
	Word(string);
	void editState(int);
};
