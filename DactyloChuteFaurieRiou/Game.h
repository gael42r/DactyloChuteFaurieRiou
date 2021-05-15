#pragma once

#include <SFML/Graphics.hpp>

#include "Score.h"
#include "Settings.h"
#include "Dictionary.h"

class Game
{
private:
	sf::RenderWindow renderWindow_;
	Settings settings_;
	Score score_;
	Dictionary dictionary_;
public:
	Game(Settings);

	Dictionary getDictionary() const { return dictionary_; }
	void Window();
};
