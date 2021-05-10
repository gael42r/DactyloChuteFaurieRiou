#include<iostream>

#include "Menu.h"

using namespace std;

Menu::Menu(Settings & settings, Scoreboard & scoreboard)
{
	settings_ = settings;
	scoreboard_ = scoreboard;
}

void Menu::Title() const
{
	cout << "    ###                       ##               ###                                ###                 ##" << endl;
	cout << "     ##                       ##                ##                                 ##                 ##" << endl;
	cout << "     ##    ####     ####     #####   ##  ##     ##      ####              ####     ##      ##  ##    #####    ####" << endl;
	cout << "  #####       ##   ##  ##     ##     ##  ##     ##     ##  ##   ######   ##  ##    #####   ##  ##     ##     ##  ##" << endl;
	cout << " ##  ##    #####   ##         ##     ##  ##     ##     ##  ##            ##        ##  ##  ##  ##     ##     ######" << endl;
	cout << " ##  ##   ##  ##   ##  ##     ## ##   #####     ##     ##  ##            ##  ##    ##  ##  ##  ##     ## ##  ##" << endl;
	cout << "  ######   #####    ####       ###       ##    ####     ####              ####    ###  ##   ######     ###    #####" << endl;
	cout << "                                     #####" << endl;
}

int Menu::enterChoice() const
{
	int choice;
	cout << "> ";
	cin >> choice;
	return choice;
}

void Menu::play()
{
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

void Menu::editScoreboard(Scoreboard & scoreboard)
{
	scoreboard_ = scoreboard;
}