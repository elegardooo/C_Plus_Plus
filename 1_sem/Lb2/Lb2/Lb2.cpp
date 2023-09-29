#include <iostream>
#include "MyClass.h"

using namespace std;
bool success = false;

////Time::Time(int hr, int min, int sec)
////{
////	setTime(hr, min, sec);
////}
//void Time::setTime(int h, int m, int s)
//{
//	hour = (h >= 0 && h < 24) ? h : 0;
//	minute = (m >= 0 && m < 60) ? m : 0;
//	second = (s >= 0 && s < 60) ? s : 0;
//}
//void Time::checkTime(Time t)
//{
//	hour = (hour >= 0 && hour < 24) ? hour : 0;
//	minute = (minute >= 0 && minute < 60) ? minute : 0;
//	second = (second >= 0 && second < 60) ? second : 0;
//}
//void Time::printStandart12()
//{
//	cout << ((hour == 0 || hour == 12) ? 12 : hour % 12)
//		<< ":" << (minute < 10 ? "0" : "") << minute
//		<< ":" << (second < 10 ? "0" : "") << second
//		<< (hour < 12 ? "AM" : "PM") << endl;
//}
//void Time::printStandart24()
//{
//	cout << (hour < 10 ? "0" : "") << hour
//		<< ":" << (minute < 10 ? "0" : "") << minute
//		<< ":" << (second < 10 ? "0" : "") << second << endl;
//}
//void Time::input()
//{
//	cout << "Enter the hour: ";
//	cin >> hour;
//	/*while(!success)
//	{
//		cin >> hour;
//		if (cin.good())
//		{
//			success = true;
//		}
//		else
//		{
//			cout << "error" << endl;
//			success = false;
//			cin.clear();
//			cin.ignore(cin.rdbuf()->in_avail());
//		}
//	}*/
//	cout << "Enter the minute: ";
//	cin >> minute;
//	cout << "Enter the second: ";
//	cin >> second;
//}
//
//int Time::getHour()
//{
//	return hour;
//}
//
//int Time::getMinute()
//{
//	return minute;
//}
//
//int Time::getSecond()
//{
//	return second;
//}

int main()
{
	struct tm newtime;
	__time64_t long_time;
	errno_t err;
	_time64(&long_time);
	err = _localtime64_s(&newtime, &long_time);
	if (err)
	{
		printf("Invalid argument to _localtime64_s.");
		exit(1);
	}
	Time set_time,
		cur_time(newtime.tm_hour, newtime.tm_min, newtime.tm_sec);
	int a = set_time.getHour();
	int b = set_time.getMinute();
	int c = set_time.getSecond();
	set_time.input();
	set_time.checkTime(set_time);
	cout << "Setted time(12/24 hour form): " << endl;
	set_time.printStandart12();
	set_time.printStandart24();
	cout << "Current time(12/24 hour form): " << endl;
	cur_time.printStandart12();
	cur_time.printStandart24();
	int h = set_time.getHour();
	int m = set_time.getMinute();
	int s = set_time.getSecond();
	cout << a << ":" << b << ":" << c << endl;
	cout << h << ":" << m << ":" << s << endl;
	return 0;
}