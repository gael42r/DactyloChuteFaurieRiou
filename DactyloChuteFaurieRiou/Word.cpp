#include<iostream>

#include "Word.h"

using namespace std;

Word::Word(string content)
{
	content_ = content;
	state_ = 0;

	text_.setString(content_);
	text_.setFillColor(sf::Color::Blue);
	text_.setCharacterSize(25);
	text_.setPosition(rand() % 1920, 10);
}

void Word::draw(sf::RenderWindow& renderWindow, sf::Font& font)
{
	text_.setFont(font);
	renderWindow.draw(text_);
}


void Word::editState(int state)
{
	if (state >= 1 && state <= 3)
	{
		state_ = state;
	}
	else
	{
		state_ = 0;
	}
}