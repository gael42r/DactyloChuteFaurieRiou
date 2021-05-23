#include "Game.h"

Game::Game(Settings settings)
{
	settings_ = settings;
	dictionary_ = Dictionary();
	score_ = Score();
	frequency_ = chooseFrequency(settings_.getDifficulty());

	madeByTexture_.loadFromFile(".\\Resources\\MadeBy.png");
	madeBy_.setTexture(madeByTexture_);

	dactyloChuteTexture_.loadFromFile(".\\Resources\\DactyloChute.png");
	dactyloChute_.setTexture(dactyloChuteTexture_);
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
		if (dictionary_.eventTextEntered(renderWindow, event))
		{
			upScore();
		}
	}
}

void Game::eventClose(sf::RenderWindow& renderWindow, sf::Event& event)
{
	if (event.type == sf::Event::Closed)
	{
		renderWindow.close();
	}
}


void Game::deleteOutWords()
{
	dictionary_.deleteOutOfScreenWords();
}

bool Game::isTimeIsUp()
{
	if (remainingTime() < sf::Time::Zero)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//void Game::drawPreGame(sf::RenderWindow& renderWindow)
//{
//
//}

void Game::restartPreGameTimer()
{
	preGameTimer_.restart();
}

bool Game::isPreGameTimeIsUp()
{
	if (preGameTimer_.getElapsedTime() > sf::seconds(5))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Game::drawMadeBy(sf::RenderWindow& renderWindow)
{
	madeBy_.setPosition(Vector2f(220, 510));
	renderWindow.draw(madeBy_);
}

void Game::drawDactyloChute(sf::RenderWindow& renderWindow)
{
	dactyloChute_.setPosition(Vector2f(220, 510));
	renderWindow.draw(dactyloChute_);
	dactyloChute_.setScale(sf::Vector2f(dactyloChute_.getScale().x - 0.01, dactyloChute_.getScale().y - 0.01));
}