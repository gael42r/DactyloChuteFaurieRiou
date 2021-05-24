#include "Dictionary.h"

Dictionary::Dictionary(int difficulty)
{
	ifstream flux1(".\\Resources\\Words\\words1.txt");
	ifstream flux2(".\\Resources\\Words\\words2.txt");
	ifstream flux3(".\\Resources\\Words\\words3.txt");

	switch (difficulty)
	{
	case 1:
		while (!flux1.eof())
		{
			string str;
			getline(flux1, str);
			word_.push_back(new Word(str));
		}
		flux1.close();
		break;
	case 2:
		while (!flux2.eof())
		{
			string str;
			getline(flux2, str);
			word_.push_back(new Word(str));
		}
		flux2.close();
		break;
	case 3:
		while (!flux3.eof())
		{
			string str;
			getline(flux3, str);
			word_.push_back(new Word(str));
		}
		flux3.close();
		break;
	default:
		while (!flux1.eof())
		{
			string str;
			getline(flux1, str);
			word_.push_back(new Word(str));
		}
		flux1.close();
		break;
	}

	

	numberCharLastWord_ = 0;
}

void Dictionary::drawWords(sf::RenderWindow& renderWindow)
{
	for (list<Word*>::iterator it = onScreenWords_.begin(); it != onScreenWords_.end(); it++)
	{
		if (it == onScreenWords_.begin())
		{
			(*it)->drawCurrent(renderWindow);
		}
		else
		{
			(*it)->draw(renderWindow);
		}
		
	}
}

//void Dictionary::addNewWordToList()
//{
//	onScreenWords_.push_back((*it_));
//	it_++;
//}

void Dictionary::addNewWordToList()
{
	onScreenWords_.push_back(word_[rand() % word_.size()]);
}

void Dictionary::deleteCurrentWord()
{
	numberCharLastWord_ = onScreenWords_.front()->getNumberOfChar();
	onScreenWords_.pop_front();
}

bool Dictionary::eventTextEntered(sf::RenderWindow& renderWindow, sf::Event event)
{
	if (!onScreenWords_.empty())
	{
		if (onScreenWords_.front()->eventTextEntered(renderWindow, event))
		{
			deleteCurrentWord();
			return true;
		}
		else
		{
			return false;
		}
	}
}

bool Dictionary::isCurrentWordOutOfScreen()
{
	if (!onScreenWords_.empty())
	{
		if (onScreenWords_.front()->getPosY() > 1080)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

void Dictionary::deleteOutOfScreenWords()
{
	if (!onScreenWords_.empty())
	{
		if (isCurrentWordOutOfScreen())
		{
			deleteCurrentWord();
		}
	}
}