#include<iostream>
#include <iomanip>  
#include <ctime>

#include "Score.h"

using namespace std;

Score::Score(string player, string difficulty, int numberOfWords)
{
	player_ = player;
	numberOfWords_ = numberOfWords;
	difficulty_ = difficulty;

	//Current date
	time_t date = time(NULL);
	tm* d;
	char date_string[100];
	time(&date);
	#pragma warning(suppress : 4996)
	d = localtime(&date);
	strftime(date_string, 50, "%d/%m/%Y %R", d);

	date_ = string(date_string);
}

void Score::display() const
{
	cout << setw(11) << player_ << " | " << setw(16) << numberOfWords_ << " | " << setw(10) << difficulty_ << " | " << setw(17) << date_ << endl;
}