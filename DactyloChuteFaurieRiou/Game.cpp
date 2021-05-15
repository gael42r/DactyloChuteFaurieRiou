#include "Game.h"

Game::Game(Settings settings)
{
	//Copy of settings
	settings_ = settings;
	dictionary_ = Dictionary(settings.getDifficulty());
}

void Game::drawWords()
{
	/*list<Word*>::iterator it;
	for (it = dictionary_.getListOfWords().begin(); it != dictionary_.getListOfWords().end(); it++)
	{
		(*it)->draw(renderWindow_);
	}*/
	/*list<Word*>::iterator it;
	it = dictionary_.getListOfWords().begin();
	(*it)->draw(renderWindow_);*/
}

void Game::Window()
{
	sf::Texture texture;
	if (!texture.loadFromFile(".\\Resources\\test.png"))
	{
		cout << "ERROR : Loding background failed." << endl;
	}
	sf::Sprite sprite;
	sprite.setTexture(texture);

	sf::Vector2u sz = texture.getSize();
	renderWindow_.create(sf::VideoMode(sz.x, sz.y), "image", sf::Style::Fullscreen);

	// Main loop
	while (renderWindow_.isOpen())
	{
		sf::Event event;
		while (renderWindow_.pollEvent(event)) {
			// Close the window
			if (event.type == sf::Event::Closed)
				renderWindow_.close();
		}

		//renderWindow_.clear(sf::Color::White);
		renderWindow_.draw(sprite);
		renderWindow_.display();
	}
}