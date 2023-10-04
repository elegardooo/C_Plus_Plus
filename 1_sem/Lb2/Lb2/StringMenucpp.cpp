#include "StringMenu.h"

//int input_check(int limit_left, int limit_right)
//{
//	int input = 0;
//	cin >> input;
//	while (true)
//	{
//		if (!(cin) || input > limit_right || input < limit_left)
//		{
//			cout << "Wrong input, try again: " << endl;
//			cin.clear();
//			cin.ignore(numeric_limits<streamsize>::max(), '\n');
//			cin >> input;
//		}
//		else
//			break;
//	}
//	return input;
//}

void print_string_menu()
{
	cout << endl
		<< "1. '=' " << endl
		<< "2. '+' " << endl
		<< "3. '+=' " << endl
		<< "4. '==' " << endl
		<< "5. '!=' " << endl
		<< "6. '[]' " << endl
		<< "7. '()' " << endl
		<< "8. Print strings " << endl
		<< "9. Exit" << endl
		<< "Choose option: " ;
}

int string_menu()
{
	MyString Str1;
	MyString Str2;
	cout << "Input 1st string: " << endl;
	cin >> Str1;
	cout << "Input 2nd string: " << endl;
	cin >> Str2;
	int choose = 0;
	int index = 0;
	int left_ind = 0;
	int right_ind = 0;
	while (choose != 9)
	{
		print_string_menu();
		choose = input_check(1, 9);

		switch (choose)
		{
		case 1:
		{
			Str1 = Str2;
			cout << "Result of string equal ( = ) :" << Str1 << endl;
			break;
		}
		case 2:
		{
			MyString Str3 = Str1 + Str2;
			cout << "Str sum ( + ): " << Str3 << endl;
			break;
		}
		case 3:
		{
			MyString Str4 = Str1;
			Str4 += Str2;
			cout << "Str sum ( += ): " << Str4 << endl;
			break;
		}
		case 4:
		{
			if (Str1 == Str2)
				cout << "Strings are equal for == condition" << endl;
			else
				cout << "Strings are not equal for == condition" << endl;
			break;
		}
		case 5:
		{
			if (Str1 != Str2)
				cout << "Strings are not equal for != condition" << endl;
			else
				cout << "Strings are equal for != condition" << endl;
			break;
		}
		case 6:
		{
			cout << "Input index: ";
			index = input_check(0, numeric_limits<int>::max());
			cout << Str1[index] << endl;
			break;
		}
		case 7:
		{
			cout << "Input left_ind: ";
			//left_ind = input_check(0, numeric_limits<int>::max());
			cin >> left_ind;
			cout << "Input right_ind: ";
			//right_ind = input_check(right_ind, numeric_limits<int>::max());
			cin >> right_ind;
			cout << "1st string in given range: " << Str1(left_ind, right_ind) << endl;
			break;
		}
		case 8:
		{
			cout << "1st string: " << Str1 << endl << "2nd string: " << Str2 << endl;
			break;
		}
		case 9:
		{
			break;
		}
		default:
		{
			return 0;
		}
		}
	}
}