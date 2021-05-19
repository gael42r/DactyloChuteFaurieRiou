#include "Word.h"

Word::Word(string content)
{
	content_ = content;

	pos_.x = rand() % 1520 + 200;
	pos_.y = 0;

	currentCaracter_ = 0;
}

void Word::draw(sf::RenderWindow& renderWindow)
{
	sf::Font font;
	font.loadFromFile(".\\Resources\\arial.ttf");
	text_.setFont(font);
	text_.setString(content_.substr(currentCaracter_,content_.size()));
	text_.setFillColor(sf::Color::Red);
	text_.setCharacterSize(25);
	text_.setPosition(pos_);
	pos_.y = pos_.y + 3;
	renderWindow.draw(text_);

}

bool Word::eventTextEntered(sf::RenderWindow& renderWindow, sf::Event event)
{
	if (event.text.unicode == sf::String(content_[currentCaracter_]))
	{
		if (currentCaracter_ < content_.size() - 1)
		{
			currentCaracter_++;
			return false;
		}
		else
		{
			return true;
		}
	}
}