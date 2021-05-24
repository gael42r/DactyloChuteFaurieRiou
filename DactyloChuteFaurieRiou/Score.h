#pragma once

#include<iostream>
#include<iomanip>  
#include<ctime>
#include<string>
#include<fstream>

using namespace std;

class Score
{
private:
	string player_;
	int numberOfChar_;
	float charPerSec_;
	string difficulty_;
	string date_;

public:
	Score(string = "Unknown" , string = "Unknown", int = 0);
	Score(const Score&);
	int getNumberOfChar() const { return numberOfChar_; }
	void setPlayer(string str) { player_ = str; }
	void display() const;
	void up(int);

	void save(ofstream& ofs) const;
	void load(ifstream& ifs);
};
