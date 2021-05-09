#include<iostream>

#include "Menu.h"

using namespace std;

Menu::Menu(Settings settings, Scoreboard& scoreboard)
{
	settings_ = settings;
	scoreboard_ = scoreboard;
}

void Menu::Title()
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

int Menu::enterChoice()
{
	int choice;
	cout << "> ";
	cin >> choice;
	return choice;
}

void Menu::setUp()
{
	settings_.display();
	while (settings_.edit());
}

void Menu::display()
{
	cout << "-------------------------------------* MENU *-------------------------------------" << endl;
	cout << "- 1 : Play" << endl;
	cout << "- 2 : Settings" << endl;
	cout << "- 3 : Scores" << endl;
	cout << "- 4 : Exit" << endl;
	cout << "----------------------------------------------------------------------------------" << endl;
}

void Menu::editScoreboard(Scoreboard& scoreboard)
{
	scoreboard_ = scoreboard;
}

void Menu::goToScoreboard() {
	scoreboard_.display();
}