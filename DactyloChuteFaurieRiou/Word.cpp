#include "Word.h"

Word::Word(string content)
{
	content_ = content;

	pos_.x = rand() % 1520 + 200;
	pos_.y = 0;

	currentCaracter_ = 0;
	isTextAlreadyAssigned_ = false;
	isTextUpdated_ = false;
}

//string alreadyEntered = content_.substr(0, currentCaracter_);
//string currentCharacter = content_.substr(currentCaracter_);
//string stillToBeEntered = content_.substr(currentCaracter_, content_.size());
//text_ << sf::Color::Green << alreadyEntered << sf::Color::Yellow << currentCharacter << sf::Color::Red << stillToBeEntered;

void Word::draw(sf::RenderWindow& renderWindow)
{
	sf::Font font;
	font.loadFromFile(".\\Resources\\arial.ttf");
	text_.setFont(font);
	string alreadyEntered = content_.substr(0, currentCaracter_);
	string currentCharacter = content_.substr(currentCaracter_, 1);
	string stillToBeEntered = content_.substr(currentCaracter_ + 1, content_.size());
	if (!isTextAlreadyAssigned_)
	{
		text_ << sf::Color::Green << alreadyEntered << sf::Color::Yellow << currentCharacter << sf::Color::Red << stillToBeEntered;
		isTextAlreadyAssigned_ = true;
	}
	else
	{
		if (isTextUpdated_)
		{
			text_.clear();
			text_ << sf::Color::Green << alreadyEntered << sf::Color::Yellow << currentCharacter << sf::Color::Red << stillToBeEntered;
		}
	}
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
			isTextUpdated_ = true;
			return false;
		}
		else
		{
			return true;
		}
	}
}