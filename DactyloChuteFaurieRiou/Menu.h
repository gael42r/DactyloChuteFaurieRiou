#pragma once

#include "Settings.h"
#include "Scoreboard.h"

class Menu
{
private:
	Settings settings_;
	Scoreboard scoreboard_;

public:
	//Menu();
	Menu(Settings &, Scoreboard &);
	void Title() const;
	void display() const;
	int enterChoice() const;
	void play();
	void setUp();
	void goToScoreboard() const;
	void editScoreboard(Scoreboard &);
	//void exit();
};