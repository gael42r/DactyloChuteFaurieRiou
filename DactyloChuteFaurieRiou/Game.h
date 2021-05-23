#pragma once

#include <SFML/Graphics.hpp>
#include<iostream>
#include<string>

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
	sf::Clock timer_;
	sf::Clock preGameTimer_;

	sf::Texture madeByTexture_;
	sf::Sprite madeBy_;

	sf::Texture dactyloChuteTexture_;
	sf::Sprite dactyloChute_;

	void restartClock();
	sf::Time getClockTime();
	sf::Time chooseFrequency(int);
	sf::Time remainingTime();

public:
	Game(Settings);

	void drawTimer(sf::RenderWindow&);
	void drawDictionary(sf::RenderWindow&);
	void restartTimer();
	void upScore();
	void drawScore(sf::RenderWindow&);
	void drawSettings(sf::RenderWindow&);
	void eventTextEntered(sf::RenderWindow&, sf::Event&);
	void eventClose(sf::RenderWindow&, sf::Event&);
	void deleteOutWords();
	bool isTimeIsUp();
	void restartPreGameTimer();
	bool isPreGameTimeIsUp();

	void drawMadeBy(sf::RenderWindow&);
	void drawDactyloChute(sf::RenderWindow&);
};
