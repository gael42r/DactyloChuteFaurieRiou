#pragma once

#include<iostream>
#include <iomanip>  
#include <ctime>
#include <string>

using namespace std;

class Score
{
private:
	string player_;
	int numberOfChar_;
	string difficulty_;
	string date_;

public:
	Score(string = "Unknown" , string = "Unknown", int = 0);

	int getNumberOfChar() const { return numberOfChar_; }
	void setPlayer(string str) { player_ = str; }
	void display() const;
	void up(int);
};
