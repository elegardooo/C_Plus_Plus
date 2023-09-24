#include<iostream>
#include<time.h>

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
	~Time() {};
};

//Time::Time(int hr, int min, int sec)
//{
//	setTime(hr, min, sec);
//}