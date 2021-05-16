#pragma once


#include <list>

#include"Word.h"

class Dictionary
{
private:
	vector<Word*> word_;

	Word* currentWord_;
	Word* newtWord_;
	vector<Word*> wordsInGame_;

public:
	Dictionary(int = 1);

	void draw(sf::RenderWindow&, sf::Font&);
	void display() const;


	void drawANewWord(sf::RenderWindow&, sf::Font&);
	void setCurrentWord(Word*);
};