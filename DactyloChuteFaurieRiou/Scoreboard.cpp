#include<iostream>
#include <iomanip>  

#include "Scoreboard.h"

using namespace std;

Scoreboard::Scoreboard()
{
}

Scoreboard::~Scoreboard()
{
	list<Score*>::iterator it;
	for (it = scoreboard_.begin(); it != scoreboard_.end(); it++)
	{
		delete *it;
	}
}

void Scoreboard::display() const
{
	cout << "----------------------------------* SCOREBOARD *----------------------------------" << endl;
	cout << setw(11) << "Player" << " | " << setw(16) << "Number of words" << " | " << setw(10) << "Difficulty" << " | " << setw(17) << "Date" << endl;
	list<Score*>::const_iterator it;
	for (it = scoreboard_.begin(); it != scoreboard_.end(); it++)
	{
		(*it)->display();
	}
	cout << "----------------------------------------------------------------------------------" << endl;
}

void Scoreboard::addScore(Score* score)
{
	scoreboard_.push_back(score);
}