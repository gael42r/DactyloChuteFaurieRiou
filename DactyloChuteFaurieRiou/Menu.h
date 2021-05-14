#pragma once

#include "Settings.h"
#include "Scoreboard.h"
#include "Game.h"

class Menu
{
private:
	Settings settings_;
	Scoreboard scoreboard_;
	Game* game;

public:
	Menu();

	Settings getSettings() const { return settings_; }
	//Scoreboard getScoreboard() const { return scoreboard_; }

	void title() const;
	void display() const;
	int enterChoice() const;
	void editScoreboard(Score*);

	void play();
	void setUp();
	void goToScoreboard() const;
};