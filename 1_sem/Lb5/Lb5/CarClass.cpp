#include "CarClass.h"
#include "Exceptions.h"

Engine::Engine(int enum_index, double volume, int power)
{
	this->enum_index = enum_index;
	this->volume = volume;
	this->power = power;
	std::cout << "Engine created" << std::endl;
}

Body::Body(int door_num, int Len_Wid_Height[])
{
	this->door_num = door_num;
	for (int i = 0; i < 3; i++)
		this->Len_Wid_Height[i] = Len_Wid_Height[i];
	std::cout << "Body created" << std::endl;
}

Color::Color(const char* Colour)
{
	//strcpy_s(this->color, sizeof(color), color);
	strcpy_s(color, 20, Colour);
	std::cout << "Color created" << std::endl;
}

Car::Car(const char* Brand, int enum_index, double volume, int power, int door_num, int Len_Wid_Height[], const char* Color) : Engine(enum_index, volume, power), Body(door_num, Len_Wid_Height), Color(Color)
{
	/*brand = new char[strlen(Brand) + 1];
	strcpy_s(this->brand, sizeof(brand), Brand);*/
	strcpy_s(brand, 20, Brand);
	std::cout << "Car created" << std::endl;
}

//Shop::Shop(const char* brand, int enum_index, double volume, int power, int door_num, int Len_Wid_Height[], const char* color, const char* mag) : Engine(brand, enum_index, volume, power),
//Body(brand, door_num, Len_Wid_Height), Color(brand, color), Car(brand)
//{
//	//strcpy_s(this->mag, sizeof(mag), mag);
//	int len = strlen(mag);
//	this->mag = new char[len];
//	for (int i = 0; i < len; i++)
//		this->mag[i] = mag[i];
//	cout << "Shop created" << endl;
//}
