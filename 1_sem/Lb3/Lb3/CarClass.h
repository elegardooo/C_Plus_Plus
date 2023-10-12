#pragma once
#include <iostream>
#include <string.h>

using namespace std;
class Car
{
private:
	char* brand;
	//char brand[20];
	//int brand_len;
public:
	Car(const char* Brand);
	~Car() { cout << "Car destructor" << endl; }
	const char* GetBrand() const
	{
		return this->brand;
	}
};

class Engine : virtual public Car
{
private:
	enum type { petrol = 1, diesel = 2 };
	double volume;
	int power;
	int enum_index;
public:
	Engine(const char* brand, int enum_index, double volume, int power);
	~Engine() { cout << "Engine destructor" << endl; }
	double const GetVolume() const
	{
		return this->volume;
	}
	int const GetPower() const
	{
		return this->power;
	}
	const char* GetTextForEnum(int enum_index)
	{
		switch (enum_index)
		{
		case petrol:
			return "petrol type";
		case diesel:
			return "diesel type";
		default:
			return "Not recognized..";
		}
	}
};

class Body : virtual public Car
{
private:
	int door_num;
	int Len_Wid_Height[3];
public:
	Body(const char* brand, int door_num, int Len_Wid_Height[]);
	~Body() { cout << "Body destructor" << endl; }
	int const GetDoorNum() const
	{
		return this->door_num;
	}
	/*int* const GetLenWidHeight() const
	{
		int* Array = new int[3];
		for (int i = 0; i < 3; i++)
			Array[i] = Len_Wid_Height[i];
		return Array;
	}*/
	int const GetLength() const
	{
		return this->Len_Wid_Height[0];
	}
	int const GetWidth() const
	{
		return this->Len_Wid_Height[1];
	}
	int const GetHeight() const
	{
		return this->Len_Wid_Height[2];
	}
};

class Color : virtual public Car
{
private:
	char* color;
public:
	Color(const char* brand, const char* color);
	~Color() { cout << "Color destructor" << endl; }
	const char* GetColor()
	{
		return this->color;
	}
};

class Shop : public Engine, public Body, public Color
{
private:
	char* mag;
public:
	Shop(const char* brand, int enum_index, double volume, int power, int door_num, int Len_Wid_Height[], const char* color, const char* mag);
	~Shop() { cout << "Shop destructor" << endl; }
	const char* GetMag()
	{
		return this->mag;
	}
};


