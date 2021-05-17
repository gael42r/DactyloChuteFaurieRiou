#include "Game.h"

Game::Game(Settings settings)
{
	settings_ = settings;
	dictionary_ = Dictionary();
}

void Game::play(sf::RenderWindow& renderWindow)
{
	dictionary_.drawWords(renderWindow);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		dictionary_.addNewWordToList();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		dictionary_.deleteCurrentWord();
	}
}