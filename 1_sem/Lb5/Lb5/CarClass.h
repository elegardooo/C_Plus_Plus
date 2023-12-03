#pragma once
#include <iostream>
#include <string.h>

class Engine
{
private:
	enum type { petrol = 1, diesel = 2 };
	double volume;
	int power;
	int enum_index;
public:
	Engine(int enum_index, double volume, int power);
	~Engine() { std::cout << "Engine destructor" << std::endl; }
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
	void const SetVolume(double new_volume)
	{
		this->volume = new_volume;
	}
	void const SetPower(int new_power)
	{
		this->power = new_power;
	}
	void const SetEnumIndex(int new_enum_index)
	{
		this->enum_index = new_enum_index;
	}
};

class Body
{
private:
	int door_num;
	int Len_Wid_Height[3];
public:
	Body(int door_num, int Len_Wid_Height[]);
	~Body() { std::cout << "Body destructor" << std::endl; }
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
	void const SetDoor_Num(int new_door_num)
	{
		this->door_num = new_door_num;
	}
	void const SetLen_Wid_Height(int new_Len_Wid_Height[])
	{
		for (int i = 0; i < 3; i++)
			this->Len_Wid_Height[i] = new_Len_Wid_Height[i];
	}
};

class Color
{
private:
	char color[20];
public:
	Color(const char* color);
	~Color() { std::cout << "Color destructor" << std::endl; }
	const char* GetColor()
	{
		return this->color;
	}
	void const SetColor(const char* new_color)
	{
		strcpy_s(color, 20, new_color);
	}
};

class Car : public Engine, public Body, public Color
{
private:
	char brand[20];
	//char brand[20];
	//int brand_len;
public:
	Car(const char* Brand, int enum_index, double volume, int power, int door_num, int Len_Wid_Height[], const char* Color);
	~Car() { std::cout << "Car destructor" << std::endl; }
	const char* GetBrand() const
	{
		return this->brand;
	}
	void SetBrand(const char* new_brand)
	{
		strcpy_s(brand, 20, new_brand);
	}
};


