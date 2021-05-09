#pragma once

#include<iostream>
#include <string>

using namespace std;

class Score
{
private:
	string player_;
	int numberOfWords_;
	int speed_;
	int dictionary_;
	int mode_;
	string date_;

public:
	Score(string, int, int, int, int);
	void display() const;
	int getNumberOfWords() const;
};
