#pragma once

class Settings
{
private:
	int speed_;
	int dictionary_;
	int mode_;

public:
	Settings(int = 3, int = 3, int = 1);
	void display() const;
	bool edit();
};