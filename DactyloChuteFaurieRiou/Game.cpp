#include "Game.h"

Game::Game(Settings settings)
{
	settings_ = settings;
	dictionary_ = Dictionary();
	score_ = Score(settings_.getStrDifficulty());
	frequency_ = chooseFrequency(settings_.getDifficulty());

	madeByTexture_.loadFromFile(".\\Resources\\MadeBy.png");
	madeBy_.setTexture(madeByTexture_);
	madeBy_.setOrigin(madeByTexture_.getSize().x / 2, madeByTexture_.getSize().y / 2);

	dactyloChuteTexture_.loadFromFile(".\\Resources\\DactyloChute.png");
	dactyloChute_.setTexture(dactyloChuteTexture_);
	dactyloChute_.setOrigin(dactyloChuteTexture_.getSize().x / 2, dactyloChuteTexture_.getSize().y / 2);

	music_.openFromFile(".\\Resources\\theme.ogg");

	nameEntered_ = "";

	isEnterPressed_ = false;
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
	timer << sf::Color::White << "remaining time : " << sf::Color::Yellow << to_string((remainingTime().asMilliseconds()) / 1000);
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
	score << sf::Color::White << "score : " << sf::Color::Cyan << to_string(score_.getNumberOfChar());
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
	difficulty << sf::Color::White << "difficulty : " << sf::Color::Magenta << settings_.getStrDifficulty();
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
	madeBy_.setPosition(1920 / 2, 1080 / 2);
	renderWindow.draw(madeBy_);
}

void Game::drawDactyloChute(sf::RenderWindow& renderWindow)
{
	dactyloChute_.setPosition(1920 / 2, 1080 / 2);
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

void Game::drawEndScore(sf::RenderWindow& renderWindow)
{
	sfe::RichText endScore;
	sfe::RichText score;
	sf::Font font;
	font.loadFromFile(".\\Resources\\Starjedi.ttf");

	endScore.setFont(font);
	endScore.clear();
	endScore << sf::Color::Yellow << "score";
	endScore.setCharacterSize(90);
	endScore.setOrigin(endScore.getLocalBounds().left + endScore.getLocalBounds().width / 2.0f, endScore.getLocalBounds().top + endScore.getLocalBounds().height / 2.0f);
	endScore.setPosition(sf::Vector2f(1920 / 2.0f, 300));

	score.setFont(font);
	score.clear();
	score << sf::Color::Cyan << to_string(score_.getNumberOfChar());
	score.setCharacterSize(90);
	score.setOrigin(score.getLocalBounds().left + score.getLocalBounds().width / 2.0f, score.getLocalBounds().top + score.getLocalBounds().height / 2.0f);
	score.setPosition(sf::Vector2f(1920 / 2.0f, 400));

	renderWindow.draw(endScore);
	renderWindow.draw(score);
}

//void Game::drawName(sf::RenderWindow& renderWindow)
//{
//	sfe::RichText name;
//	sf::Font font;
//	font.loadFromFile(".\\Resources\\Starjedi.ttf");
//
//	name.setFont(font);
//	name.clear();
//	name << sf::Color::Yellow << "name";
//	name.setCharacterSize(90);
//	name.setOrigin(name.getLocalBounds().left + name.getLocalBounds().width / 2.0f, name.getLocalBounds().top + name.getLocalBounds().height / 2.0f);
//	name.setPosition(sf::Vector2f(1920 / 2.0f, 600));
//
//	renderWindow.draw(name);
//}

void Game::drawName(sf::RenderWindow& renderWindow)
{
	sfe::RichText name;
	sfe::RichText nameEntered;
	sf::Font font;
	font.loadFromFile(".\\Resources\\Starjedi.ttf");

	name.setFont(font);
	name.clear();
	name << sf::Color::Yellow << "name";
	name.setCharacterSize(90);
	name.setOrigin(name.getLocalBounds().left + name.getLocalBounds().width / 2.0f, name.getLocalBounds().top + name.getLocalBounds().height / 2.0f);
	name.setPosition(sf::Vector2f(1920 / 2.0f, 600));

	nameEntered.setFont(font);
	nameEntered.clear();
	nameEntered << sf::Color::Magenta << nameEntered_;
	nameEntered.setCharacterSize(90);
	nameEntered.setOrigin(nameEntered.getLocalBounds().left + nameEntered.getLocalBounds().width / 2.0f, nameEntered.getLocalBounds().top + nameEntered.getLocalBounds().height / 2.0f);
	nameEntered.setPosition(sf::Vector2f(1920 / 2.0f, 700));

	renderWindow.draw(name);
	renderWindow.draw(nameEntered);
}


void Game::eventTextName(sf::Event& event)
{
	if (event.type == sf::Event::TextEntered)
	{
		if (event.text.unicode == 8)
		{
			if (!nameEntered_.empty())
			{
				nameEntered_.pop_back();
			}
		}
		else if(event.text.unicode >= 65 && event.text.unicode <=90 || event.text.unicode >= 97 && event.text.unicode <= 122)
		{
			nameEntered_.push_back(event.text.unicode);
		}
	}
}

void Game::drawPressEnter(sf::RenderWindow& renderWindow)
{
	if (!nameEntered_.empty())
	{
		sfe::RichText pressEnter;
		sf::Font font;
		font.loadFromFile(".\\Resources\\Starjedi.ttf");

		pressEnter.setFont(font);
		pressEnter.clear();
		pressEnter << sf::Color::White << "Press ENTER to continue...";
		pressEnter.setCharacterSize(40);
		pressEnter.setOrigin(pressEnter.getLocalBounds().left + pressEnter.getLocalBounds().width / 2.0f, pressEnter.getLocalBounds().top + pressEnter.getLocalBounds().height / 2.0f);
		pressEnter.setPosition(sf::Vector2f(1920 / 2.0f, 900));

		renderWindow.draw(pressEnter);
	}
}

void Game::eventEnter(sf::Event& event, sf::RenderWindow& renderWindow)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			if (!nameEntered_.empty())
			{
				isEnterPressed_ = true;
				score_.setPlayer(nameEntered_);
				renderWindow.close();
			}
		}
	}
}

bool Game::isEnterAlreadyPressed()
{
	if (isEnterPressed_)
	{
		return true;
	}
	else
	{
		false;
	}
}