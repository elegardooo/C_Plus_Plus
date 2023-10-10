#include <iostream>
#include <string.h>

using namespace std;
class Car
{
private:
	char brand[20];
	int brand_len;
public:
	Car(const char*);
	~Car() { cout << "Brand destructor" << endl; }
	const char* GetBrand() const
	{
		return brand;
	}
};

Car::Car(const char* brand_str)
{
	strcpy_s(this->brand, sizeof(brand_str), brand_str);
	cout << "Car created" << endl;
}

//Car::Car(const char* brand_str)
//{
//	this->brand_len = strlen(brand_str) + 1;
//	this->brand = new char[brand_len];
//	for (int i = 0; i < brand_len; i++)
//	{
//		this->brand[i] = brand_str[i];
//	}
//	cout << "Car created" << endl;
//}

class Otdel : public Firma
{
protected:
	long tn; // табельный номер
	int nom; // номер подразделения

public:
	Otdel(char*, long, int);
	~Otdel() { cout << "деструктор класса В1" << endl; }
	void Otdel_prnt();
};
class Bank
{
protected:
	char naz[30]; // название банка
	double schet; // сумма денег
public:
	Bank(char*, double);
	~Bank() { cout << "деструктор класса В2" << endl; }
	void Bank_prnt();
};
class Work : public Otdel, public Bank
{
	char* fam;
public:
	Work(char*, char*, long, int, char*, double);
	~Work() { cout << "деструктор класса С" << endl; }
	void Work_prnt();
};
Firma::Firma(char* NAZ) { strcpy(naz, NAZ); }
Otdel::Otdel(char* NAZ, long TN, int NOM) : Firma(NAZ), tn(TN), nom(NOM) {}
Bank::Bank(char* NAZ, double SCHET) : schet(SCHET) { strcpy(naz, NAZ); }
Work::Work(char* FAM, char* NAZ1, long TN, int NOM, char* NAZ2, double ZP) :
	Otdel(NAZ1, TN, NOM), Bank(NAZ2, ZP)
{
	fam = new char[strlen(FAM) + 1];
	strcpy(fam, FAM);
}
void Firma::Firma_prnt() { cout << naz << endl; }
void Otdel::Otdel_prnt()
{
	Firma::Firma_prnt();
	cout << " таб. N " << tn << " подразделение = " << nom << endl;
}
void Bank::Bank_prnt()
{
	cout << " банк : " << naz << endl;
	cout << " счет = " << schet << endl;
}
void Work::Work_prnt()
{
	Otdel::Otdel_prnt();
	Bank::Bank_prnt();
	cout << " фамилия " << fam << endl;
}

int main()
{
	Work rb("Иванов", "предприятие", 1234, 2, "банк", 555.6);
	Work* pt = &rb; // указатель на созданный объект. Далее можно
	// использовать для вызова методов либо
	// сам объект car, либо
	// указатель на него pt
	setlocale(LC_ALL, "Russian");
	rb.Otdel_prnt(); // вызов метода Otdel_prnt, используя объект
	pt->Otdel_prnt(); // вызов метода Otdel_prnt, используя
	//указатель на объект
	rb.Bank_prnt();
	pt->Bank_prnt();
	rb.Work_prnt();
	pt->Work_prnt();
	return 0;
}

Car::Car(char&)
{
}
