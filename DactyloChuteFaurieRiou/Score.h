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
	int numberOfWords_;
	string difficulty_;
	string date_;

public:
	Score(string = "Unknown" , string = "Unknown", int = 0);
	void display() const;
};
