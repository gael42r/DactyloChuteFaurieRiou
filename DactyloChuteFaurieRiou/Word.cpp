#include<iostream>

#include "Word.h"

using namespace std;

Word::Word(string content)
{
	content_ = content;
	state_ = 0;
	currentChar_ = 2;

	text_.setCharacterSize(25);
	text_.setPosition(rand() % 1920, 10);
}

void Word::draw(sf::RenderWindow& renderWindow, sf::Font& font)
{
	string fisrtPart = "%3" + content_.substr(0, currentChar_);
	string secondPart = "%4" + content_.substr(currentChar_, 1);
	string thirdPart = "%5" + content_.substr(currentChar_ + 1, content_.length() - currentChar_);
	text_.setFont(font);
	text_.setString(fisrtPart + secondPart + thirdPart);
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