#include<iostream>

#include "Menu.h"

using namespace std;

Menu::Menu()
{
}

void Menu::title() const
{
	cout << "    ###                       ##               ###                                ###                 ##" << endl;
	cout << "     ##                       ##                ##                                 ##                 ##" << endl;
	cout << "     ##    ####     ####     #####   ##  ##     ##      ####              ####     ##      ##  ##    #####    ####" << endl;
	cout << "  #####       ##   ##  ##     ##     ##  ##     ##     ##  ##   ######   ##  ##    #####   ##  ##     ##     ##  ##" << endl;
	cout << " ##  ##    #####   ##         ##     ##  ##     ##     ##  ##            ##        ##  ##  ##  ##     ##     ######" << endl;
	cout << " ##  ##   ##  ##   ##  ##     ## ##   #####     ##     ##  ##            ##  ##    ##  ##  ##  ##     ## ##  ##" << endl;
	cout << "  ######   #####    ####       ###       ##    ####     ####              ####    ###  ##   ######     ###    #####" << endl;
	cout << "                                     #####" << endl;
	system("PAUSE");
	system("CLS");
}

int Menu::enterChoice() const
{
	int choice;
	cout << "> ";
	cin >> choice;
	return choice;
}

void Menu::editScoreboard(Score* score)
{
	scoreboard_.addScore(score);
}

void Menu::play()
{
	sf::Texture texture;
	texture.loadFromFile(".\\Resources\\background.png");

	sf::Sprite sprite;
	sprite.setTexture(texture);

	sf::Vector2u sz = texture.getSize();
	sf::RenderWindow renderWindow;
	
	renderWindow.create(sf::VideoMode(sz.x, sz.y), "image", sf::Style::Fullscreen);
	
	renderWindow.setFramerateLimit(40);

	Game game(settings_);

	game.restartPreGameTimer();

	sf::Event event;

	/*sf::CircleShape s(50.f);
	s.setFillColor(sf::Color::Blue);*/


	while (renderWindow.isOpen())
	{
		while (renderWindow.pollEvent(event))
		{
			game.eventClose(renderWindow, event);
		}
		while (!game.isPreGameTimeIsUp())
		{
			while (renderWindow.pollEvent(event))
			{
				game.eventClose(renderWindow, event);
			}
			renderWindow.clear(sf::Color::White);
			renderWindow.draw(sprite);
			game.drawMadeBy(renderWindow);
			game.drawDactyloChute(renderWindow);
			renderWindow.display();
		}
		game.restartTimer();
		while (!game.isTimeIsUp())
		{
			while (renderWindow.pollEvent(event))
			{
				game.eventClose(renderWindow, event);
				game.eventTextEntered(renderWindow, event);
			}




			renderWindow.clear(sf::Color::White);
			renderWindow.draw(sprite);

			game.drawDictionary(renderWindow);
			game.deleteOutWords();
			game.drawTimer(renderWindow);
			game.drawScore(renderWindow);
			game.drawSettings(renderWindow);
			renderWindow.display();
		}
		while (game.isTimeIsUp())
		{
			while (renderWindow.pollEvent(event))
			{
				game.eventClose(renderWindow, event);
			}
			renderWindow.clear(sf::Color::White);
			renderWindow.draw(sprite);
			renderWindow.display();
		}
	}
}

void Menu::setUp()
{
	system("CLS");
	settings_.display();
	while (settings_.edit());
}

void Menu::display() const
{
	cout << "-------------------------------------* MENU *-------------------------------------" << endl;
	cout << "- 1 : Play" << endl;
	cout << "- 2 : Settings" << endl;
	cout << "- 3 : Scores" << endl;
	cout << "- 4 : Exit" << endl;
	cout << "----------------------------------------------------------------------------------" << endl;
}

void Menu::goToScoreboard() const
{
	system("CLS");
	scoreboard_.display();
	cout << "> ";
	system("PAUSE");
}