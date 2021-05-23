#include "Settings.h"

Settings::Settings(int difficulty)
{
	difficulty_ = difficulty;
	switch (difficulty)
	{
	case 1: //Easy
		strDifficulty_ = "Easy";
		speed_ = 1;
		wordsDifficulty_ = 1;
		break;
	case 2: //Normal
		strDifficulty_ = "Normal";
		speed_ = 2;
		wordsDifficulty_ = 2;
		break;
	case 3: //Hard
		strDifficulty_ = "Hard";
		speed_ = 3;
		wordsDifficulty_ = 3;
		break;
	default:
		strDifficulty_ = "Easy";
		speed_ = 1;
		wordsDifficulty_ = 1;
		break;
	}
}

void Settings::display() const
{
	cout << "-------------------------------------* SETTINGS *-------------------------------------" << endl;
	cout << "- Difficulty : " << strDifficulty_ << endl;
	cout << "--------------------------------------------------------------------------------------" << endl;
}

bool Settings::edit()
{
	char reply = '\0';
	while (reply != 'y' && reply != 'n')
	{
		cout << "> Do you want to change the difficulty? (y:YES | n:NO) : ";
		cin >> reply;
	}

	if (reply == 'y')
	{
		cout << "---------------------------------* SETTINGS EDITION *---------------------------------" << endl;

		int difficulty = 0;
		while (difficulty < 1 || difficulty > 3)
		{
			cout << "- Difficulty (1:Easy | 2:Normal | 3:Hard) : ";
			cin >> difficulty;
		}
		if (difficulty >= 1 && difficulty <= 3)
		{
			difficulty_ = difficulty;
			switch (difficulty)
			{
			case 1: //Easy
				strDifficulty_ = "Easy";
				speed_ = 1;
				wordsDifficulty_ = 1;
				break;
			case 2: //Normal
				strDifficulty_ = "Normal";
				speed_ = 2;
				wordsDifficulty_ = 2;
				break;
			case 3: //Hard
				strDifficulty_ = "Hard";
				speed_ = 3;
				wordsDifficulty_ = 3;
				break;
			default:
				strDifficulty_ = "Easy";
				speed_ = 1;
				wordsDifficulty_ = 1;
				break;
			}
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