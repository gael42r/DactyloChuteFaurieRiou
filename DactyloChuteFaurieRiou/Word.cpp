#include<iostream>

#include "Word.h"

using namespace std;

Word::Word(string content)
{
	content_ = content;

	pos_.x = rand() % 1520 + 200;
	pos_.y = 0;

	
}

void Word::draw(sf::RenderWindow& renderWindow)
{
	sf::Font font;
	font.loadFromFile(".\\Resources\\arial.ttf");
	text_.setFont(font);
	text_.setString(content_);
	text_.setFillColor(sf::Color::Red);
	text_.setCharacterSize(25);
	text_.setPosition(pos_);
	pos_.y = pos_.y + 3;
	renderWindow.draw(text_);

}