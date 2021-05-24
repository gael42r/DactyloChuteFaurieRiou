#include "Scoreboard.h"

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
	cout << "------------------------------------* SCOREBOARD *------------------------------------" << endl;
	cout << setw(11) << "Player" << " | " << setw(18) << "Words per minutes" << " | " << setw(18) << "Words per seconds" << " | " << setw(10) << "Difficulty" << " | " << setw(17) << "Date" << endl;
	list<Score*>::const_iterator it;
	for (it = scoreboard_.begin(); it != scoreboard_.end(); it++)
	{
		(*it)->display();
	}
	cout << "--------------------------------------------------------------------------------------" << endl;
}

void Scoreboard::addScore(Score* score)
{
	scoreboard_.push_back(score);
}



void Scoreboard::save(ofstream& ofs) const
{
	ofs << scoreboard_.size() << endl;
	for (list<Score*>::const_iterator it = scoreboard_.begin(); it != scoreboard_.end(); it++)
	{
		(*it)->save(ofs);
	}
}

void Scoreboard::load(ifstream& ifs)
{
	for (list<Score*>::const_iterator it = scoreboard_.begin(); it != scoreboard_.end(); it++)
	{
		delete (*it);
	}
	scoreboard_.clear();
	size_t nb;
	ifs >> nb;
	//ifs.ignore();
	for (int i = 0; i < (int)nb; i++)
	{
		Score* score = new Score;
		score->load(ifs);
		addScore(score);
	}
}