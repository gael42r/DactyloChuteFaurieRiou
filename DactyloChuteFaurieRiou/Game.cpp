#include "Game.h"

Game::Game(Settings settings)
{
	//Copie des paramètres du menu dans le jeu
	settings_ = settings;
}

void Game::openWindow()
{
	sf::Texture texture;
	if (!texture.loadFromFile(".\\Resources\\test.png"))
	{
		cout << "ERROR : Loding background failed." << endl;
	}
	sf::Sprite sprite;
	sprite.setTexture(texture);

	// Création de la fenêtre
	sf::Vector2u sz = texture.getSize();
	renderWindow_.create(sf::VideoMode(sz.x, sz.y), "image", sf::Style::Fullscreen);

	// Boucle principale
	while (renderWindow_.isOpen())
	{
		sf::Event event;
		while (renderWindow_.pollEvent(event)) {
			// Demande de fermeture de la fenêtre
			if (event.type == sf::Event::Closed)
				renderWindow_.close();
		}

		// On efface la fenêtre (en blanc)
		renderWindow_.clear(sf::Color::White);

		// Affichage du sprite
		renderWindow_.draw(sprite);

		// Mise à jour de la fenêtre
		renderWindow_.display();
	}
}