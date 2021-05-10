#include <iostream>
#include <SFML/Graphics.hpp>

#include "Menu.h"
#include "Settings.h"
#include "Scoreboard.h"
#include "Score.h"

using namespace std;

void test()
{
	sf::Texture texture;
	if (!texture.loadFromFile(".\\Resources\\test.png"))
	{
		// erreur...
	}
	sf::Sprite sprite;
	sprite.setTexture(texture);

	// Création de la fenêtre
	sf::Vector2u sz = texture.getSize();
	sf::RenderWindow window(sf::VideoMode(sz.x, sz.y), "image", sf::Style::Fullscreen);

	// Boucle principale
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event)) {
			// Demande de fermeture de la fenêtre
			if (event.type == sf::Event::Closed)
				window.close();

		}

		// On efface la fenêtre (en blanc)
		window.clear(sf::Color::White);

		// Affichage du sprite
		window.draw(sprite);

		// Mise à jour de la fenêtre
		window.display();
	}
}


int main()
{
	Settings settings;
	Scoreboard scoreboard;
	Menu menu(settings, scoreboard);

	Score score1("Gael", 1, 1, 1, 1);
	Score score2("Antoine", 2, 1, 3, 1);
	scoreboard.addScore(score1);
	scoreboard.addScore(score2);
	menu.editScoreboard(scoreboard);

	menu.Title();

	for (;;)
	{
		menu.display();

		int choice = 0;
		while (choice < 1 || choice > 4)
		{
			choice = menu.enterChoice();
		}

		switch (choice)
		{
		case 1: //Play
			test();
			break;
		case 2: //Settings
			menu.setUp();
			break;
		case 3: //Scoreboard
			menu.goToScoreboard();
			break;
		case 4: //Exit
			return 0;
			break;
		default:
			break;
			return 0;
		}
		system("CLS");
	}


	//Score score1("Gael", 1, 1, 1, 1);
	//Score score2("Antoine", 2, 1, 3, 1);
	//scoreboard.addScore(score1);
	//scoreboard.addScore(score2);
	//scoreboard.display();
	////menu.editScoreboard(scoreboard);

	system("PAUSE");
	return 0;
}