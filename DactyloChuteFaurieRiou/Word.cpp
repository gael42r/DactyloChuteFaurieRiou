#include<iostream>

#include "Word.h"

using namespace std;

Word::Word(string content)
{
	content_ = content;
	state_ = 0;
	text_.setPosition(rand() % 1000, rand() % 1000);
}

void Word::drawWord(sf::RenderWindow& renderWindow)
{
	text_.setString(content_);
	sf::Font font;
	if (!font.loadFromFile(".\\Resources\\arial.ttf"))
	{
		cout << "Error : Font loading failed." << endl;
	}
	
	text_.setFont(font);
	text_.setCharacterSize(24);
	text_.setFillColor(sf::Color::Red);
	text_.setStyle(sf::Text::Bold);
	renderWindow.draw(text_);
	renderWindow.display();
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