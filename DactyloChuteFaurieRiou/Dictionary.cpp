#include "Dictionary.h"

Dictionary::Dictionary()
{
	ifstream flux(".\\Resources\\words.txt");

	while (!flux.eof())
	{
		string str;
		getline(flux, str);
		word_.push_back(new Word(str));	
	}
	flux.close();
	it_ = word_.begin();

	numberCharLastWord_ = 0;
}

void Dictionary::drawWords(sf::RenderWindow& renderWindow)
{
	for (list<Word*>::iterator it = onScreenWords_.begin(); it != onScreenWords_.end(); it++)
	{
		if (it == onScreenWords_.begin())
		{
			(*it)->drawCurrent(renderWindow);
		}
		else
		{
			(*it)->draw(renderWindow);
		}
		
	}
}

void Dictionary::addNewWordToList()
{
	onScreenWords_.push_back((*it_));
	it_++;
}

void Dictionary::deleteCurrentWord()
{
	numberCharLastWord_ = onScreenWords_.front()->getNumberOfChar();
	onScreenWords_.pop_front();
}

bool Dictionary::eventTextEntered(sf::RenderWindow& renderWindow, sf::Event event)
{
	if (!onScreenWords_.empty())
	{
		if (onScreenWords_.front()->eventTextEntered(renderWindow, event))
		{
			deleteCurrentWord();
			return true;
		}
		else
		{
			return false;
		}
	}
}

bool Dictionary::isCurrentWordOutOfScreen()
{
	if (!onScreenWords_.empty())
	{
		if (onScreenWords_.front()->getPosY() > 1080)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

void Dictionary::deleteOutOfScreenWords()
{
	if (!onScreenWords_.empty())
	{
		if (isCurrentWordOutOfScreen())
		{
			deleteCurrentWord();
		}
	}
}