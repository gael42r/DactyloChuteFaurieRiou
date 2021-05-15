#pragma once

#include <SFML/Graphics.hpp>

#include "Score.h"
#include "Settings.h"

class Game
{
private:
	sf::RenderWindow renderWindow_;
	Settings settings_;
	Score score_;
public:
	Game(Settings);
	void Window();
};
