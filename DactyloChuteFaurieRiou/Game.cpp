#include "Game.h"

Game::Game(Settings settings)
{
	settings_ = settings;
	dictionary_ = Dictionary();
	score_ = Score();
	frequency_ = chooseFrequency(settings_.getDifficulty());
}

void Game::drawDictionary(sf::RenderWindow& renderWindow)
{
	dictionary_.drawWords(renderWindow);
	if (getClockTime() > frequency_)
	{
		dictionary_.addNewWordToList();
		restartClock();
	}
}

void Game::temp()
{
	dictionary_.addNewWordToList();
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

void Game::upScore()
{
	score_.up();
}

void Game::drawScore(sf::RenderWindow& renderWindow)
{
	sf::Text score;
	sf::Font font;
	font.loadFromFile(".\\Resources\\arial.ttf");
	score.setFont(font);
	score.setString("Score : " + to_string(score_.getNumberOfWords()));
	score.setPosition(sf::Vector2f(10, 50));
	score.setCharacterSize(35);
	score.setFillColor(sf::Color::White);
	renderWindow.draw(score);
}

void Game::drawSettings(sf::RenderWindow& renderWindow)
{
	sf::Text difficulty;
	sf::Font font;
	font.loadFromFile(".\\Resources\\arial.ttf");
	difficulty.setFont(font);
	difficulty.setString("Difficulty : " + settings_.getStrDifficulty());
	difficulty.setPosition(sf::Vector2f(10, 90));
	difficulty.setCharacterSize(35);
	difficulty.setFillColor(sf::Color::White);
	renderWindow.draw(difficulty);
}

//void Game::eventCurrentCaracter(sf::RenderWindow& renderWindow)
//{
//	sf::Event event;
//	while (renderWindow.pollEvent(event))
//	{
//
//		if (event.type == sf::Event::TextEntered)
//		{
//			if (event.text.unicode == sf::String("n"))
//			{
//				upScore();
//
//			}
//
//		}
//	}
//}

void Game::eventTextEntered(sf::RenderWindow& renderWindow, sf::Event& event)
{
	if (event.type == sf::Event::TextEntered)
	{
		dictionary_.eventTextEntered(renderWindow, event);
	}
}

void Game::eventClose(sf::RenderWindow& renderWindow, sf::Event& event)
{
	if (event.type == sf::Event::Closed)
	{
		renderWindow.close();
	}
}