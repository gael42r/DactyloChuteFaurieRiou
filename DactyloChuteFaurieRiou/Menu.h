#pragma once
#include<SFML/Graphics.hpp>
#include<fstream>

#include"Settings.h"
#include"Scoreboard.h"
#include"Score.h"
#include"Game.h"

class Menu
{
private:
	Settings settings_;
	Scoreboard scoreboard_;

public:
	Menu();

	Settings getSettings() const { return settings_; }

	void title() const;
	void display() const;
	int enterChoice() const;
	void editScoreboard(Score*);

	void play();
	void setUp();
	void goToScoreboard() const;

	void save() const;
	void load();
};