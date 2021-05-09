#include<iostream>

#include "Settings.h"

using namespace std;

Settings::Settings(int speed, int dictionary, int mode)
{
	speed_ = speed;
	dictionary_ = dictionary;
	mode_ = mode;
}

void Settings::display()
{
	cout << "-----------------------------------* SETTINGS *-----------------------------------" << endl;
	cout << "- Speed (1 to 5) : " << speed_ << endl;
	cout << "- Words difficulty (1 to 5) : " << dictionary_ << endl;
	cout << "- Mode (1:Infinite | 2:Timer | 3:List) : " << mode_ << endl;
	cout << "----------------------------------------------------------------------------------" << endl;
}

bool Settings::edit()
{
	char reply = '\0';
	while (reply != 'y' && reply != 'n')
	{
		cout << "> Do you want to change the settings? (y:YES | n:NO) : ";
		cin >> reply;
	}

	if (reply == 'y')
	{
		cout << "-------------------* SETTINGS EDITION *-------------------" << endl;

		int speed = 0;
		while (speed < 1 || speed > 5)
		{
			cout << "- Speed (1 to 5) : ";
			cin >> speed;
		}
		if (speed >= 1 && speed <= 5)
		{
			speed_ = speed;
		}

		int dictionary = 0;
		while (dictionary < 1 || dictionary > 5)
		{
			cout << "- Words difficulty (1 to 5) : ";
			cin >> dictionary;
		}
		if (dictionary >= 1 && dictionary <= 5)
		{
			dictionary_ = dictionary;
		}

		int mode = 0;
		while (mode < 1 || mode > 3)
		{
			cout << "- Mode (1:Infinite | 2:Timer | 3:List) : ";
			cin >> mode;
		}
		if (mode >= 1 && mode <= 3)
		{
			mode_ = mode;
		}

		cout << "----------------------------------------------------------" << endl;

		system("CLS");
		this->display();
		return true;
	}
	else if (reply == 'n')
	{
		return false;
	}
	else
	{
		return false;
	}
}