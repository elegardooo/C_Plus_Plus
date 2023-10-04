#include <iostream>
#include "MyClass.h"
#include "MyStringClass.h"
#include "StringMenu.h"

using namespace std;

int main()
{
	//struct tm newtime;
	//__time64_t long_time;
	//errno_t err;
	//_time64(&long_time);
	//err = _localtime64_s(&newtime, &long_time);
	//if (err)
	//{
	//	printf("Invalid argument to _localtime64_s.");
	//	exit(1);
	//}
	//Time set_time,
	//	cur_time(newtime.tm_hour, newtime.tm_min, newtime.tm_sec);
	///*int a = set_time.getHour();
	//int b = set_time.getMinute();
	//int c = set_time.getSecond();*/
	//set_time.input();
	//set_time.checkTime(set_time);
	//cout << "Setted time(12/24 hour form): " << endl;
	//set_time.printStandart12();
	//set_time.printStandart24();
	//cout << "Current time(12/24 hour form): " << endl;
	//cur_time.printStandart12();
	//cur_time.printStandart24();
	//cout << endl;
	//int h = set_time.getHour();
	//int m = set_time.getMinute();
	//int s = set_time.getSecond();
	///*cout << a << ":" << b << ":" << c << endl;
	//cout << h << ":" << m << ":" << s << endl;*/
	//Time const_time1(6, 4, 2);
	//Time now_time1{ set_time + const_time1 };
	//now_time1.printStandart24();
	//int numbe1 = now_time1 + 2;
	//cout << numbe1 << endl;
	//Time now_time2{ set_time - const_time1 };
	//now_time2.printStandart24();
	//int numbe2 = now_time2 - 1;
	//cout << numbe2 << endl;
	
	/*MyString Str3(Str1 + Str2);
	MyString Str4(Str1);
	Str4 += Str2;

	cout << "Str sum( + ): " << Str3 << endl;
	cout << "Str sum ( += ): " << Str4 << endl;*/
	
	string_menu();
	
	return 0;
}