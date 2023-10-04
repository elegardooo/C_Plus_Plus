#pragma once
#include "MyStringClass.h"

MyString::MyString()
{
	this->data = nullptr;
	this->len = 0;
}

MyString::MyString(unsigned len)
{
	this->data = new char[len];
	this->len = len;
}

MyString::MyString(const char* data)
{
	this->len = strlen(data) + 1;
	this->data = new char[len];
	for (int i = 0; i < len; i++)
		this->data[i] = data[i];
}

MyString::MyString(const MyString& string)
{
	this->len = string.len;
	this->data = new char[len];
	for (int i = 0; i < len; i++)
		this->data[i] = string.data[i];
}

MyString::~MyString()
{
	delete[] this->data;
}

int MyString::length()
{
	return len;
}

MyString MyString :: operator + (const MyString& right_str)
{
	char* new_data = new char[right_str.len + len];
	for (int i = 0; i < len - 1; i++)
		new_data[i] = data[i];
	for (int j = len - 1, i = 0; j < right_str.len + len; j++, i++)
		new_data[j] = right_str.data[i];
	MyString new_string(new_data);
	return new_string;
}

MyString MyString :: operator + (const char* right_str)
{
	char* new_data = new char[strlen(right_str) + 1 + len];
	for (int i = 0; i < len - 1; i++)
		new_data[i] = data[i];
	for (int j = len - 1, i = 0; j < strlen(right_str) + len; j++, i++)
		new_data[j] = right_str[i];
	MyString new_string(new_data);
	return new_string;
}

MyString& MyString :: operator = (const MyString& right_str)
{
	if (data != nullptr)
		delete[] this->data;
	this->data = new char[right_str.len];
	this->len = right_str.len;
	for (int i = 0; i < len; i++)
		this->data[i] = right_str.data[i];
	return *this;
}

MyString& MyString :: operator += (const MyString& right_str)
{
	*this = *this + right_str;
	return *this;
}

bool MyString::operator == (const MyString& right_str)
{
	for (int i = 0; i < this->len; i++)
	{
		if (this->data[i] != right_str.data[i])
			return false;
	}
	return true;
}

bool MyString::operator != (const MyString& right_str)
{
	for (int i = 0; i < this->len; i++)
	{
		if (this->data[i] != right_str.data[i])
			return true;
	}
	return false;
}

char& MyString :: operator[](const unsigned ind)
{
	if (ind >= this->len)
		throw string{ "Wrong index." };
	return this->data[ind];
}

MyString MyString :: operator()(const unsigned left_ind, const unsigned right_ind)
{
	if (left_ind >= len || right_ind >= len || left_ind < 0 || right_ind < 0)
		throw string("Wrong index.");
	MyString new_string(len);
	int j = 0;
	for (int i = left_ind; i <= right_ind; i++, j++)
		new_string[j] = this->data[i];
	new_string[j] = '\0';
	return new_string;
}

istream& operator >> (istream& input_stream, MyString& string)
{
	if (string.data != nullptr)
		delete[] string.data;
	std::string buf_string;
	input_stream >> buf_string;
	string.len = buf_string.size() + 1;
	string.data = new char[string.len];
	for (int i = 0; i < string.len; i++)
		string.data[i] = buf_string[i];
	return input_stream;
}

ostream& operator << (ostream& output_stream, MyString string)
{
	output_stream << string.data;
	return output_stream;
}