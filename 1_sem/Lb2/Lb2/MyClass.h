#pragma once
#include <iostream>
#include <time.h>

using namespace std;

class Time
{
	int hour;
	int minute;
	int second;
public:
	Time(int = 0, int = 0, int = 0);
	void setTime(int, int, int);
	void printStandart12();
	void printStandart24();
	int getHour();
	int getMinute();
	int getSecond();
	void input();
	void checkTime(Time t);
	friend Time operator + (const Time& c1, const Time& c2);
	int operator + (int number);
	friend Time operator - (const Time& c1, const Time& c2);
	int operator - (int number);
	~Time() {};
};

