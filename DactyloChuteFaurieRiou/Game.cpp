#include "Game.h"

Game::Game(Settings settings)
{
	settings_ = settings;
	dictionary_ = Dictionary();
	frequency_ = chooseFrequency(settings_.getDifficulty());
}

void Game::play(sf::RenderWindow& renderWindow)
{
	dictionary_.drawWords(renderWindow);
	if (getClockTime() > frequency_)
	{
		dictionary_.addNewWordToList();
		restartClock();
	}
}

void Game::restartClock()
{
	clock_.restart();
}

sf::Time Game::getClockTime()
{
	return clock_.getElapsedTime();
}

sf::Time Game::chooseFrequency(int speed)
{
	switch (speed)
	{
	case 1:
		return sf::seconds(3);
		break;
	case 2:
		return sf::seconds(2);
		break;
	case 3:
		return sf::seconds(1);
		break;
	default:
		return sf::seconds(3);
		break;
	}
}

void Game::restartTimer()
{
	timer_.restart();
}

sf::Time Game::remainingTime()
{
	sf::Time time = timer_.getElapsedTime();
	return sf::seconds(60) - time;
}

void Game::drawTimer(sf::RenderWindow& renderWindow)
{
	sf::Text timer;
	sf::Font font;
	font.loadFromFile(".\\Resources\\arial.ttf");
	timer.setFont(font);
	timer.setString("Remaining Time : " + to_string((remainingTime().asMilliseconds())/1000));
	timer.setPosition(sf::Vector2f(10, 10));
	timer.setCharacterSize(35);
	timer.setFillColor(sf::Color::White);
	renderWindow.draw(timer);
}