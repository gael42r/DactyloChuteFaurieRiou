#pragma once

#include <fstream>
#include <list>

#include"Word.h"

class Dictionary
{
private:
	list<Word*> word_;
	list<Word*> onScreenWords_;

	list<Word*>::iterator it_;

public:
	Dictionary();

	void drawWords(sf::RenderWindow&);
	void addNewWordToList();
	void deleteCurrentWord();

	bool eventTextEntered(sf::RenderWindow&, sf::Event);
};