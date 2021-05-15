#include<iostream>

#include "Word.h"

using namespace std;

Word::Word(string content)
{
	content_ = content;
	position_ = sf::Vector2i(rand() % 1080, 0);
	state_ = 0;
}

void Word::editState(int state)
{
	if (state >= 1 && state <= 3)
	{
		state_ = state;
	}
	else
	{
		state_ = 0;
	}
}