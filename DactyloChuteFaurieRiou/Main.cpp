#include <iostream>
#include <SFML/Graphics.hpp>

#include "Menu.h"
#include "Settings.h"
#include "Scoreboard.h"
#include "Score.h"

using namespace std;

void test()
{
	sf::Font font;
	if (!font.loadFromFile(".\\Resources\\arial.ttf"))
	{
		// erreur...
	}

	sf::Text text;

	// choix de la police � utiliser
	text.setFont(font); // font est un sf::Font

	// choix de la cha�ne de caract�res � afficher
	text.setString("Hello world");

	// choix de la taille des caract�res
	text.setCharacterSize(24); // exprim�e en pixels, pas en points !

	// choix de la couleur du texte
	text.setFillColor(sf::Color::Red);

	// choix du style du texte
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);



	sf::Texture texture;
	if (!texture.loadFromFile(".\\Resources\\test.png"))
	{
		// erreur...
	}
	sf::Sprite sprite;
	sprite.setTexture(texture);

	// Cr�ation de la fen�tre
	sf::Vector2u sz = texture.getSize();
	sf::RenderWindow window(sf::VideoMode(sz.x, sz.y), "image", sf::Style::Fullscreen);

	// Boucle principale
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event)) {
			// Demande de fermeture de la fen�tre
			if (event.type == sf::Event::Closed)
				window.close();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				// la touche "fl�che gauche" est enfonc�e : on bouge le personnage
				text.move(sf::Vector2f(0,5));
			}

		}

		// On efface la fen�tre (en blanc)
		window.clear(sf::Color::White);

		// Affichage du sprite
		window.draw(sprite);

		window.draw(text);

		// Mise � jour de la fen�tre
		window.display();
	}
}


int main()
{
	Menu menu;
	menu.editScoreboard(new Score("Gael", menu.getSettings().getStrDifficulty(), 25));


	menu.title();

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