#pragma once

#include<iostream>
#include <string>

using namespace std;

class Score
{
private:
	string player_;
	int numberOfWords_;
	string difficulty_;
	string date_;

public:
	Score(string, string, int);
	void display() const;
	int getNumberOfWords() const;
};
