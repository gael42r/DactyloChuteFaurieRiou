#pragma once

#include <iostream>
#include <iomanip>  
#include <list>

#include "Score.h"

using namespace std;

class Scoreboard
{
private:
	list<Score*> scoreboard_;
public:
	Scoreboard();
	~Scoreboard();

	void display() const;
	void addScore(Score*);
};