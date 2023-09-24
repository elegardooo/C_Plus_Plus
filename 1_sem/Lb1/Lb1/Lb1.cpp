
#include "Header.h"

using namespace std;
bool success = false;

//class Time
//{
//	int hour;
//	int minute;
//	int second;
//public:
//	Time(int = 0, int = 0, int = 0);
//	void setTime(int, int, int);
//	void printStandart12();
//	void printStandart24();
//	void input();
//	void checkTime(Time t);
//	~Time() {};
//};
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
	cin >> hour;
	/*while(!success)
	{
		cin >> hour;
		if (cin.good())
		{
			success = true;
		}
		else
		{
			cout << "error" << endl;
			success = false;
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
		}
	}*/
	cout << "Enter the minute: ";
	cin >> minute;
	cout << "Enter the second: ";
	cin >> second;
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

int main()
{
	time_t t1 = time(NULL);
	tm local_time = *localtime(&t1);
	//printf("%.2d:%.2d:%.2d\n", local_time.tm_hour, local_time.tm_min, local_time.tm_sec);
	Time set_time,
		cur_time(local_time.tm_hour, local_time.tm_min, local_time.tm_sec);
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