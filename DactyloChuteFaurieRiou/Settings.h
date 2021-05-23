#pragma once

#include <iostream>
#include <string>

using namespace std;

class Settings
{
private:
	int difficulty_;
	string strDifficulty_;
	int speed_;
	int wordsDifficulty_;

public:
	Settings(int = 2);

	string getStrDifficulty() const { return strDifficulty_; }
	int getDifficulty() const { return difficulty_; }

	void display() const;
	bool edit();
};