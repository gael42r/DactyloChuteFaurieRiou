#pragma once

#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
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
	sf::Clock madeByTimer_;
	sf::Clock dactyloChuteTimer_;
	sf::Clock preGameTimer_;
	sf::Texture madeByTexture_;
	sf::Sprite madeBy_;
	sf::Texture dactyloChuteTexture_;
	sf::Sprite dactyloChute_;
	sf::Music music_;

	string nameEntered_;

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
	void restartMadeByTimer();
	bool isMadeByTimeIsUp();
	void restartDactyloChuteTimer();
	bool isDactyloChuteTimeIsUp();
	void restartPreGameTimer();
	bool isPreGameTimeIsUp();
	void drawMadeBy(sf::RenderWindow&);
	void drawDactyloChute(sf::RenderWindow&);
	void playMusic();
	void drawEndScore(sf::RenderWindow&);
	void drawName(sf::RenderWindow&);
	void drawPressEnter(sf::RenderWindow&);
	void eventTextName(sf::Event&);
	Score eventEnter(sf::Event&, sf::RenderWindow&);
};
