#include "Game.h"

Game::Game(Settings settings)
{
	settings_ = settings;
	dictionary_ = Dictionary();
	score_ = Score();
	frequency_ = chooseFrequency(settings_.getDifficulty());

	madeByTexture_.loadFromFile(".\\Resources\\MadeBy.png");
	madeBy_.setTexture(madeByTexture_);
	madeBy_.setOrigin(madeByTexture_.getSize().x / 2, madeByTexture_.getSize().y / 2);

	dactyloChuteTexture_.loadFromFile(".\\Resources\\DactyloChute.png");
	dactyloChute_.setTexture(dactyloChuteTexture_);
	dactyloChute_.setOrigin(dactyloChuteTexture_.getSize().x / 2, dactyloChuteTexture_.getSize().y / 2);

	music_.openFromFile(".\\Resources\\theme.ogg");
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
	sfe::RichText timer;
	sf::Font font;
	font.loadFromFile(".\\Resources\\Starjedi.ttf");
	timer.setFont(font);
	timer.clear();
	timer << sf::Color::White << "Remaining Time : " << sf::Color::Yellow << to_string((remainingTime().asMilliseconds()) / 1000);
	timer.setPosition(sf::Vector2f(15, 10));
	timer.setCharacterSize(35);
	renderWindow.draw(timer);
}

void Game::upScore()
{
	score_.up(dictionary_.getNumberCharLastWord());
}

void Game::drawScore(sf::RenderWindow& renderWindow)
{
	sfe::RichText score;
	sf::Font font;
	font.loadFromFile(".\\Resources\\Starjedi.ttf");
	score.setFont(font);
	score.clear();
	score << sf::Color::White << "Score : " << sf::Color::Cyan << to_string(score_.getNumberOfChar());
	score.setPosition(sf::Vector2f(15, 50));
	score.setCharacterSize(35);
	renderWindow.draw(score);
}

void Game::drawSettings(sf::RenderWindow& renderWindow)
{
	sfe::RichText difficulty;
	sf::Font font;
	font.loadFromFile(".\\Resources\\Starjedi.ttf");
	difficulty.setFont(font);
	difficulty.clear();
	difficulty << sf::Color::White << "Difficulty : " << sf::Color::Magenta << settings_.getStrDifficulty();
	difficulty.setPosition(sf::Vector2f(15, 90));
	difficulty.setCharacterSize(35);
	renderWindow.draw(difficulty);
}

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

void Game::restartMadeByTimer()
{
	madeByTimer_.restart();
}

bool Game::isMadeByTimeIsUp()
{
	if (madeByTimer_.getElapsedTime() > sf::seconds(3))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Game::restartDactyloChuteTimer()
{
	dactyloChuteTimer_.restart();
}

bool Game::isDactyloChuteTimeIsUp()
{
	if (dactyloChuteTimer_.getElapsedTime() > sf::seconds(5))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Game::restartPreGameTimer()
{
	preGameTimer_.restart();
}

bool Game::isPreGameTimeIsUp()
{
	if (preGameTimer_.getElapsedTime() > sf::seconds(4))
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
	madeBy_.setPosition(Vector2f(1920 / 2, 1080 / 2));
	renderWindow.draw(madeBy_);
}

void Game::drawDactyloChute(sf::RenderWindow& renderWindow)
{
	dactyloChute_.setPosition(Vector2f(1920 / 2, 1080 / 2));
	renderWindow.draw(dactyloChute_);
	if (dactyloChute_.getScale().x > 0 && dactyloChute_.getScale().y > 0)
	{
		dactyloChute_.setScale(sf::Vector2f(dactyloChute_.getScale().x - 0.00475, dactyloChute_.getScale().y - 0.00475));
	}
}

void Game::playMusic()
{
	music_.play();
}