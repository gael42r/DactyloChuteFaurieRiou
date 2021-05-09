#pragma once

#include <iostream>
#include <list>

#include "Score.h"

using namespace std;

class Scoreboard
{
private:
	list<Score> scoreboard_;
public:
	Scoreboard();
	void display();
	void addScore(Score);
};