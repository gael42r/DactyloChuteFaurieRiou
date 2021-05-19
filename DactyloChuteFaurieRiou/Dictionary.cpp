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
}

void Dictionary::drawWords(sf::RenderWindow& renderWindow)
{
	for (list<Word*>::iterator it = onScreenWords_.begin(); it != onScreenWords_.end(); it++)
	{
		(*it)->draw(renderWindow);
	}
}

void Dictionary::addNewWordToList()
{
	onScreenWords_.push_back((*it_));
	it_++;
}

void Dictionary::deleteCurrentWord()
{
	onScreenWords_.pop_front();
}

void Dictionary::eventTextEntered(sf::RenderWindow& renderWindow, sf::Event event)
{
	if (onScreenWords_.front()->eventTextEntered(renderWindow, event))
	{
		deleteCurrentWord();
	}
}