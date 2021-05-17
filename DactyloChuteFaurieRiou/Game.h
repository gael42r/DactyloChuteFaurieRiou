#pragma once

#include <SFML/Graphics.hpp>

#include "Score.h"
#include "Settings.h"
#include "Dictionary.h"

class Game
{
private:
	Settings settings_;
	Score score_;
	Dictionary dictionary_;
	sf::Clock clock_;
	sf::Time frequency_;

	void restartClock();
	sf::Time getClockTime();
	sf::Time chooseFrequency(int);

public:
	Game(Settings);

	void play(sf::RenderWindow&);
};
