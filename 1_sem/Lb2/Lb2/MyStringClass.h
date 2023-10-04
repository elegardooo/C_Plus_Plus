#pragma once
#include <iostream>
#include <string.h>

using namespace std;

class MyString
{
	char* data;
	int len;
public:
	MyString();
	MyString(unsigned len);
	MyString(const char* data);
	//MyString(const string& data);
	MyString(const MyString& string);
	int length();
	MyString operator + (const MyString& right_str);
	MyString operator +(const char* right_str);
	MyString& operator = (const MyString& right_str);
	MyString& operator += (const MyString& right_str);
	bool operator == (const MyString& right_str);
	bool operator != (const MyString& right_str);
	char& operator [] (const unsigned ind);
	MyString operator ()(const unsigned left_ind, const unsigned right_ind);
	friend istream& operator >> (istream& input_stream, MyString& string);
	friend ostream& operator << (ostream& output_stream, MyString string);
	//friend MyString& operator = (const MyString& str1, const MyString& str2);
	~MyString();
};