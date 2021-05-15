#pragma once


#include <list>

#include"Word.h"

class Dictionary
{
private:
	list<Word*> word_;
public:
	Dictionary(int = 1);

	list<Word*> getListOfWords() { return word_; }
	void display() const;
};