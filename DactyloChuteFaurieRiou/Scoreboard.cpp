#include<iostream>
#include <iomanip>  

#include "Scoreboard.h"

using namespace std;

Scoreboard::Scoreboard()
{

}

void Scoreboard::display() const
{
	cout << "----------------------------------* SCOREBOARD *----------------------------------" << endl;
	cout << setw(11) << "Player" << " | " << setw(16) << "Number of words" << " | " << setw(6) << "Speed" << " | " << setw(11) << "Dictionary" << " | " << setw(5) << "Mode" << " | " << setw(17) << "Date" << endl;
	list<Score>::const_iterator it;
	for (it = scoreboard_.begin(); it != scoreboard_.end(); it++)
	{
		(*it).display();
	}
	cout << "----------------------------------------------------------------------------------" << endl;
}

void Scoreboard::addScore(Score score)
{
	scoreboard_.push_back(score);
}