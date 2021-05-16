#pragma once


#include <list>

#include"Word.h"

class Dictionary
{
private:
	vector<Word*> word_;

	Word* currentWord_;
	list<Word*> wordsInGame_;

public:
	Dictionary(int = 1);

	//void draw(sf::RenderWindow&, sf::Font&);
	//void display() const;


	//void drawANewWord(sf::RenderWindow&, sf::Font&);
	//void setCurrentWord(Word*);

	void addANewWordToQueue(sf::RenderWindow&, sf::Font&);
	void update();
};