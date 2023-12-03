#include <iostream>
#include <iomanip>
#include <string.h>
#include "CarClass.h"
//#include "Exceptions.h"

int main()
{
	int LWH[]{ 3, 4 ,5 };
	int enum_index = 1;
	Car Mercedes("Mercedes", enum_index, 255.4, 250, 4, LWH, "Black");
	/*Mercedes.SetBrand("Mitsubishi");
	Mercedes.SetEnumIndex(2);
	Mercedes.SetVolume(264.55);
	Mercedes.SetPower(270);
	Mercedes.SetDoor_Num(5);
	int LWH2[]{ 6, 7, 8 };
	Mercedes.SetLen_Wid_Height(LWH2);
	Mercedes.SetColor("White");*/
	std::cout << std::setw(20) << " Car brand: " << Mercedes.GetBrand() << std::endl;
	std::cout << std::setw(20) << " Engine type: " << Mercedes.GetTextForEnum(enum_index) << std::endl;
	std::cout << std::setw(20) << " Engine volume: " << Mercedes.GetVolume() << std::endl;
	std::cout << std::setw(20) << " Engine power: " << Mercedes.GetPower() << std::endl;
	std::cout << std::setw(20) << " Car doors amount: " << Mercedes.GetDoorNum() << std::endl;
	std::cout << std::setw(20) << " Car length: " << Mercedes.GetLength() << std::endl
		<< std::setw(20) << "Car Width: " << Mercedes.GetWidth() << std::endl
		<< std::setw(20) << "Car Height: " << Mercedes.GetHeight() << std::endl;
	std::cout << std::setw(20) << " Car color: " << Mercedes.GetColor() << std::endl;
	//Color Red("Merce", "Red");
	//Car Merce("Mercedes");
	/*const char* Name = "Mercedes";
	Car Merc(Name);*/
	return 0;
}