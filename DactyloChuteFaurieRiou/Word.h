#pragma once

#include<iostream>
#include <SFML/Graphics.hpp>
#include <string>

#include"FText.h"

using namespace std;

class Word
{
private:
	string content_;
	FText text_;
	int state_;
public:
	Word(string);

	string getContent() const { return content_; }
	
	void draw(sf::RenderWindow& renderWindow, sf::Font&);
	void editState(int);
};
