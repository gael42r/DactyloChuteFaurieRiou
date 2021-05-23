#include "Score.h"

Score::Score(string difficulty, string player, int numberOfWords)
{
	player_ = player;
	numberOfChar_ = numberOfWords;
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

Score::Score(const Score& score)
{
	player_ = score.player_;
	numberOfChar_ = score.numberOfChar_;
	difficulty_ = score.difficulty_;
	date_ = score.date_;
}

void Score::display() const
{
	cout << setw(11) << player_ << " | " << setw(16) << numberOfChar_ << " | " << setw(10) << difficulty_ << " | " << setw(17) << date_ << endl;
}

void Score::up(int nbChar)
{
	numberOfChar_ = numberOfChar_ + nbChar;
}