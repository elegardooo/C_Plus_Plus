#pragma once
#include "MyClass.h"

int input_check(int limit_left, int limit_right)
{
	int input = 0;
	std::cin >> input;
	while (true)
	{
		if (!(std::cin) || input > limit_right || input < limit_left)
		{
			std::cout << "Wrong input, try again: " << std::endl;

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			std::cin >> input;
		}
		else
			break;
	}
	return input;
}

Time::Time(int hr, int min, int sec)
{
	setTime(hr, min, sec);
}

void Time::setTime(int h, int m, int s)
{
	hour = (h >= 0 && h < 24) ? h : 0;
	minute = (m >= 0 && m < 60) ? m : 0;
	second = (s >= 0 && s < 60) ? s : 0;
}

void Time::checkTime(Time t)
{
	hour = (hour >= 0 && hour < 24) ? hour : 0;
	minute = (minute >= 0 && minute < 60) ? minute : 0;
	second = (second >= 0 && second < 60) ? second : 0;
}

void Time::printStandart12()
{
	cout << ((hour == 0 || hour == 12) ? 12 : hour % 12)
		<< ":" << (minute < 10 ? "0" : "") << minute
		<< ":" << (second < 10 ? "0" : "") << second
		<< (hour < 12 ? "AM" : "PM") << endl;
}

void Time::printStandart24()
{
	cout << (hour < 10 ? "0" : "") << hour
		<< ":" << (minute < 10 ? "0" : "") << minute
		<< ":" << (second < 10 ? "0" : "") << second << endl;
}

void Time::input()
{
	cout << "Enter the hour: ";
	hour = input_check(0, 24);
	cout << "Enter the minute: ";
	minute = input_check(0, 59);
	cout << "Enter the second: ";
	second = input_check(0, 59);
}

int Time::getHour()
{
	return hour;
}

int Time::getMinute()
{
	return minute;
}

int Time::getSecond()
{
	return second;
}

Time operator + (const Time& c1, const Time& c2)
{
	return Time(c1.hour + c2.hour, c1.minute + c2.minute, c1.second + c2.second);
}

int Time::operator + (int number)
{
	return hour + number;
}

Time operator - (const Time& c1, const Time& c2)
{
	return Time(c1.hour - c2.hour, c1.minute - c2.minute, c1.second - c2.second);
}

int Time::operator - (int number)
{
	return hour - number;
}
