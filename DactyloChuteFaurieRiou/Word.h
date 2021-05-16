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
	//int state_;
	int currentChar_;
	sf::Vector2f pos_;
	bool isInGame_;
	bool isCurrent_;

public:
	Word(string);

	string getContent() const { return content_; }
	void setIsInGame(bool);
	void setIsCurrent(bool);
	
	void draw(sf::RenderWindow& renderWindow, sf::Font&);
	//void editState(int);
};
