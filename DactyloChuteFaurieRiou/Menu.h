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
	Menu(Settings, Scoreboard&);
	void Title();
	void display();
	int enterChoice();
	void play();
	void setUp();
	void goToScoreboard();
	void editScoreboard(Scoreboard&);
	//void exit();
};