#include "CarClass.h"

Car::Car(const char* Brand)
{
	/*brand = new char[strlen(Brand) + 1];
	strcpy_s(this->brand, sizeof(brand), Brand);*/
	int len = strlen(Brand) + 1;
	this->brand = new char[len];
	for (int i = 0; i < len; i++)
		this->brand[i] = Brand[i];
	cout << "Car created" << endl;
}

Engine::Engine(const char* brand, int enum_index, double volume, int power) : Car(brand)
{
	this->enum_index = enum_index;
	this->volume = volume;
	this->power = power;
	cout << "Engine created" << endl;
}

Body::Body(const char* brand, int door_num, int Len_Wid_Height[]) : Car(brand)
{
	this->door_num = door_num;
	for (int i = 0; i < 3; i++)
		this->Len_Wid_Height[i] = Len_Wid_Height[i];
	cout << "Body created" << endl;
}

Color::Color(const char* brand, const char* color) : Car(brand)
{
	//strcpy_s(this->color, sizeof(color), color);
	int len = strlen(color) + 1;
	this->color = new char[len];
	for (int i = 0; i < len; i++)
		this->color[i] = color[i];
	cout << "Color created" << endl;
}

Shop::Shop(const char* brand, int enum_index, double volume, int power, int door_num, int Len_Wid_Height[], const char* color, const char* mag) : Engine(brand, enum_index, volume, power),
Body(brand, door_num, Len_Wid_Height), Color(brand, color), Car(brand)
{
	//strcpy_s(this->mag, sizeof(mag), mag);
	int len = strlen(mag);
	this->mag = new char[len];
	for (int i = 0; i < len; i++)
		this->mag[i] = mag[i];
	cout << "Shop created" << endl;
}
