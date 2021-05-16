#include "Game.h"

Game::Game(Settings settings)
{
	settings_ = settings;
	dictionary_ = Dictionary(settings.getDifficulty());
}

void Game::drawDictionary(sf::RenderWindow& renderWindow, sf::Font& font)
{
	dictionary_.draw(renderWindow, font);
}

void Game::playAGame(sf::RenderWindow& renderWindow, sf::Font& font)
{

}