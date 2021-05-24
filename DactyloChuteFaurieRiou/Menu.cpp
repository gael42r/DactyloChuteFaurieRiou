#include "Menu.h"

Menu::Menu(){}

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

void Menu::display() const
{
	cout << "---------------------------------------* MENU *---------------------------------------" << endl;
	cout << "- 1 : Play" << endl;
	cout << "- 2 : Settings" << endl;
	cout << "- 3 : Scores" << endl;
	cout << "- 4 : Exit and save" << endl;
	cout << "--------------------------------------------------------------------------------------" << endl;
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
	//Chargement de la texture du fond
	sf::Texture texture;
	texture.loadFromFile(".\\Resources\\Pictures\\background.png");

	sf::Sprite sprite;
	sprite.setTexture(texture);

	//Création de la fenêtre
	sf::RenderWindow renderWindow;
	sf::Vector2u sz = texture.getSize();
	
	renderWindow.create(sf::VideoMode(sz.x, sz.y), "image", sf::Style::Fullscreen);
	renderWindow.setFramerateLimit(40);

	//Création d'une partie
	Game game(settings_);

	//Démarrage de la partie
	game.restartMadeByTimer();

	sf::Event event;
	while (renderWindow.isOpen())
	{
		while (renderWindow.pollEvent(event))
		{
			game.eventClose(renderWindow, event);
		}

		//Affichage "made by"
		while (!game.isMadeByTimeIsUp())
		{
			while (renderWindow.pollEvent(event))
			{
				game.eventClose(renderWindow, event);
			}
			renderWindow.clear(sf::Color::Black);
			renderWindow.draw(sprite);
			game.drawMadeBy(renderWindow);
			renderWindow.display();
		}

		//Affichage titre "DactyloChute"
		game.restartDactyloChuteTimer();
		game.playMusic();
		while (!game.isDactyloChuteTimeIsUp())
		{
			while (renderWindow.pollEvent(event))
			{
				game.eventClose(renderWindow, event);
			}
			renderWindow.clear(sf::Color::Black);
			renderWindow.draw(sprite);
			game.drawDactyloChute(renderWindow);
			renderWindow.display();
		}
		game.restartPreGameTimer();
		while (!game.isPreGameTimeIsUp())
		{
			while (renderWindow.pollEvent(event))
			{
				game.eventClose(renderWindow, event);
			}
			renderWindow.clear(sf::Color::Black);
			renderWindow.draw(sprite);
			renderWindow.display();
		}

		//Affichage de la partie
		game.restartTimer();
		while (!game.isTimeIsUp())
		{
			while (renderWindow.pollEvent(event))
			{
				game.eventClose(renderWindow, event);
				game.eventTextEntered(renderWindow, event);
			}
			renderWindow.clear(sf::Color::Black);
			renderWindow.draw(sprite);

			game.drawDictionary(renderWindow);
			game.deleteOutWords();
			game.drawTimer(renderWindow);
			game.drawScore(renderWindow);
			game.drawSettings(renderWindow);
			renderWindow.display();
		}

		//Affichage de la fin de partie
		while (game.isTimeIsUp() && !game.isEnterAlreadyPressed())
		{
			while (renderWindow.pollEvent(event))
			{
				game.eventClose(renderWindow, event);
				game.eventTextName(event);
				game.eventEnter(event, renderWindow);
			}
			renderWindow.clear(sf::Color::Black);
			renderWindow.draw(sprite);
			game.drawEndScore(renderWindow);
			game.drawName(renderWindow);
			game.drawPressEnter(renderWindow);
			renderWindow.display();
		}
	}

	//Aajout du score dans le tableau des scores
	editScoreboard(new Score(game.getScore()));
}

void Menu::setUp()
{
	system("CLS");
	settings_.display();
	while (settings_.edit());
}

void Menu::goToScoreboard() const
{
	system("CLS");
	scoreboard_.display();
	cout << "> ";
	system("PAUSE");
}

void Menu::save() const
{
	ofstream os(".\\Resources\\Data\\data.txt");
	scoreboard_.save(os);
	os.close();
}

void Menu::load()
{
	ifstream is(".\\Resources\\Data\\data.txt");
	scoreboard_.load(is);
	is.close();
}