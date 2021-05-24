#pragma once

#include <fstream>
#include <list>
#include <vector>

#include"Word.h"

class Dictionary
{
private:
	vector<Word*> word_;
	list<Word*> onScreenWords_;

	int numberCharLastWord_;

public:
	Dictionary(int = 1);

	void drawWords(sf::RenderWindow&);
	void addNewWordToList();
	void deleteCurrentWord();
	bool eventTextEntered(sf::RenderWindow&, sf::Event);
	bool isCurrentWordOutOfScreen();
	void deleteOutOfScreenWords();
	int getNumberCharLastWord() const { return numberCharLastWord_; }
};