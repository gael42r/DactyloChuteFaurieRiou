#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <xstring>

#include "Menu.h"
#include "Settings.h"
#include "Scoreboard.h"
#include "Score.h"

using namespace std;
//
//void test()
//{
//	//sf::Font font;
//	//if (!font.loadFromFile(".\\Resources\\arial.ttf"))
//	//{
//	//	// erreur...
//	//}
//
//	//sf::Text text;
//
//	//// choix de la police à utiliser
//	//text.setFont(font); // font est un sf::Font
//
//	//// choix de la chaîne de caractères à afficher
//	//text.setString("Hello world");
//
//	//// choix de la taille des caractères
//	//text.setCharacterSize(24); // exprimée en pixels, pas en points !
//
//	//// choix de la couleur du texte
//	//text.setFillColor(sf::Color::Red);
//
//	//// choix du style du texte
//	//text.setStyle(sf::Text::Italic | sf::Text::Underlined);
//
//
//
//	//sf::Texture texture;
//	//if (!texture.loadFromFile(".\\Resources\\test.png"))
//	//{
//	//	// erreur...
//	//}
//	//sf::Sprite sprite;
//	//sprite.setTexture(texture);
//
//	//// Création de la fenêtre
//	//sf::Vector2u sz = texture.getSize();
//	//sf::RenderWindow window(sf::VideoMode(sz.x, sz.y), "image", sf::Style::Fullscreen);
//
//	//// Boucle principale
//	//while (window.isOpen())
//	//{
//	//	sf::Event event;
//	//	while (window.pollEvent(event)) {
//	//		// Demande de fermeture de la fenêtre
//	//		if (event.type == sf::Event::Closed)
//	//			window.close();
//
//	//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
//	//		{
//	//			// la touche "flèche gauche" est enfoncée : on bouge le personnage
//	//			text.move(sf::Vector2f(0, 5));
//	//		}
//
//	//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
//	//		{
//	//			// la touche "flèche gauche" est enfoncée : on bouge le personnage
//	//			text.move(sf::Vector2f(0, -5));
//	//		}
//
//	//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
//	//		{
//	//			// la touche "flèche gauche" est enfoncée : on bouge le personnage
//	//			text.move(sf::Vector2f(-5, 0));
//	//		}
//
//	//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
//	//		{
//	//			// la touche "flèche gauche" est enfoncée : on bouge le personnage
//	//			text.move(sf::Vector2f(5, 0));
//	//		}
//
//	//	}
//
//	//	// On efface la fenêtre (en blanc)
//	//	window.clear(sf::Color::White);
//
//	//	// Affichage du sprite
//	//	window.draw(sprite);
//
//	//	window.draw(text);
//
//	//	// Mise à jour de la fenêtre
//	//	window.display();
//	//}
//
//	/*list<string> strList;
//	ifstream flux(".\\Resources\\words.txt");
//
//	while (!flux.eof())
//	{
//		string str;
//		getline(flux, str);
//		if (str.length() == 4 || str.length() == 5)
//		{
//			strList.push_back(str);
//		}
//		
//	}
//	
//	list<string>::iterator it;
//	for (it = strList.begin(); it != strList.end(); it++) 
//	{
//		cout << *it << endl;
//	}
//	flux.close();
//	system("PAUSE");*/
//}
//
//void GameWindow(sf::RenderWindow& renderWindow, Game& game)
//{
//	sf::Font font;
//	if (!font.loadFromFile(".\\Resources\\arial.ttf"))
//	{
//		// erreur...
//	}
//
//	sf::Text text;
//
//	// choix de la police à utiliser
//	text.setFont(font); // font est un sf::Font
//
//	// choix de la chaîne de caractères à afficher
//	text.setString("Hello world");
//
//	// choix de la taille des caractères
//	text.setCharacterSize(24); // exprimée en pixels, pas en points !
//
//	// choix de la couleur du texte
//	text.setFillColor(sf::Color::Red);
//
//	// choix du style du texte
//	text.setStyle(sf::Text::Italic | sf::Text::Underlined);
//
//	text.setPosition(50, 50);
//
//	sf::Texture texture;
//	if (!texture.loadFromFile(".\\Resources\\test.png"))
//	{
//		cout << "err";
//	}
//	sf::Sprite sprite;
//	sprite.setTexture(texture);
//
//	sf::Vector2u sz = texture.getSize();
//	renderWindow.create(sf::VideoMode(sz.x, sz.y), "image", sf::Style::Fullscreen);
//
//	while (renderWindow.isOpen())
//	{
//		sf::Event event;
//		while (renderWindow.pollEvent(event))
//		{
//			if (event.type == sf::Event::Closed)
//				renderWindow.close();
//		}
//		
//		//renderWindow.clear(sf::Color::White);
//		game.getDictionary().drawDictionary(&renderWindow);
//		renderWindow.draw(sprite);
//		renderWindow.draw(text);
//		renderWindow.display();
//		
//
//	}
//}
//
int main()
{
	


	Menu menu;
	menu.editScoreboard(new Score("Gael", menu.getSettings().getStrDifficulty(), 250));
	menu.editScoreboard(new Score("Antoine", menu.getSettings().getStrDifficulty(), 120));


	menu.title();

	for (;;)
	{
		sf::Font font;
		if (font.loadFromFile(".\\Resources\\arial.ttf"))
		{
			// erreur...
		}

		sf::Texture texture;
		if (!texture.loadFromFile(".\\Resources\\test.png"))
		{
			// erreur...
		}
		sf::Sprite sprite;
		sprite.setTexture(texture);

		sf::Vector2u sz = texture.getSize();
		sf::RenderWindow renderWindow;
		

		Game game(menu.getSettings());
		
		menu.display();

		int choice = 0;
		while (choice < 1 || choice > 4)
		{
			choice = menu.enterChoice();
		}

		switch (choice)
		{
		case 1: //Play
			renderWindow.create(sf::VideoMode(sz.x, sz.y), "image", sf::Style::Fullscreen);
			while (renderWindow.isOpen())
			{
				sf::Event event;
				while (renderWindow.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						renderWindow.close();
				}

				renderWindow.clear(sf::Color::White);
				renderWindow.draw(sprite);
				game.drawDictionary(renderWindow, font);
				renderWindow.display();
			}
			//test();
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
