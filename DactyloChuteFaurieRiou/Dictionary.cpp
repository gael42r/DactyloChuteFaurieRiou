#include<iostream>
#include <fstream>

#include "Dictionary.h"

using namespace std;

Dictionary::Dictionary(int difficulty)
{
	ifstream flux(".\\Resources\\words.txt");

	while (!flux.eof())
	{
		string str;
		getline(flux, str);
		switch (difficulty)
		{
		case 1:
			if (str.length() == 4 || str.length() == 5)
			{
				word_.push_back(new Word(str));
			}
			break;
		case 2:
			if (str.length() == 6 || str.length() == 7)
			{
				word_.push_back(new Word(str));
			}
			break;
		case 3:
			if (str.length() == 8 || str.length() == 9)
			{
				word_.push_back(new Word(str));
			}
			break;
		default:
			if (str.length() == 4 || str.length() == 5)
			{
				word_.push_back(new Word(str));
			}
			break;
		}
		
	}
	flux.close();
}

void Dictionary::display() const
{
	list<Word*>::const_iterator it;
	for (it = word_.begin(); it != word_.end(); it++)
	{
		cout << (*it)->getContent() << endl;
	}	
	system("PAUSE");
}