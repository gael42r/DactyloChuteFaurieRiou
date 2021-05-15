#include<iostream>

#include "Word.h"

using namespace std;

Word::Word(string content)
{
	content_ = content;

	text_.setString(content);
	sf::Font font;
	if (!font.loadFromFile(".\\Resources\\arial.ttf"))
	{
		cout << "Error : Font loading failed." << endl;
	}
	text_.setPosition(100,100);
	text_.setFont(font);
	text_.setCharacterSize(24);
	text_.setFillColor(sf::Color::Red);
	text_.setStyle(sf::Text::Bold);

	position_ = sf::Vector2i(rand() % 1080, 0);
	state_ = 0;
}

void Word::draw(sf::RenderWindow& renderWindow)
{
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