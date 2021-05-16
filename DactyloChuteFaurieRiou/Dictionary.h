#pragma once


#include <list>

#include"Word.h"

class Dictionary
{
private:
	vector<Word*> word_;
public:
	Dictionary(int = 1);

	void draw(sf::RenderWindow&, sf::Font&);
	vector<Word*> getListOfWords() { return word_; }
	void display() const;
};