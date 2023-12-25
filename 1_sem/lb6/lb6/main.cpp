#include <iostream>
#include <iomanip>
#include <string.h>
#include "CarClass.h"
#include "List.h"
#include "files.h"

using namespace std;

int main()
{
    int LWH[]{ 3, 4 ,5 };
    int LWH2[]{ 6, 7 ,8 };
    int LWH3[]{ 2, 5 ,7 };
    int enum_index = 1;
    int enum_index2 = 2;
    int enum_index3 = 3;
    Car Mercedes("Mercedes", enum_index, 255.4, 250, 4, LWH, "Black");
    Car Mercedes2("Mercedes2", enum_index2, 242.4, 150, 3, LWH2, "Green");
    Car Mercedes3("Mercedes3", enum_index3, 178.4, 50, 1, LWH3, "Red");

    /*cout << setw(20) << " Car brand: " << Mercedes.GetBrand() << endl;
    cout << setw(20) << " Engine type: " << Mercedes.GetTextForEnum(enum_index) << endl;
    cout << setw(20) << " Engine volume: " << Mercedes.GetVolume() << endl;
    cout << setw(20) << " Engine power: " << Mercedes.GetPower() << endl;
    cout << setw(20) << " Car doors amount: " << Mercedes.GetDoorNum() << endl;
    cout << setw(20) << " Car length: " << Mercedes.GetLength() << endl
        << setw(20) << "Car Width: " << Mercedes.GetWidth() << endl
        << setw(20) << "Car Height: " << Mercedes.GetHeight() << endl;
    cout << setw(20) << " Car color: " << Mercedes.GetColor() << endl;*/

    List<Car>* listSource = new List<Car>();
    List<Car>* listResulttxt = new List<Car>();

    listSource->push(Mercedes);
    listSource->push(Mercedes2);
    listSource->push(Mercedes3);

    writeToTextFile(listSource, "in.txt");
    readFromTextFile(listResulttxt, "in.txt");

    int size = listResulttxt->size();
    Node<Car>* node = listResulttxt->peek_head();
    std::cout << "TXT file in object output: " << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cout << node->data.GetBrand() << " " << node->data.GetEnum() << " " << node->data.GetVolume() << " " << node->data.GetPower() << " " << node->data.GetDoorNum() << " "
            << node->data.GetLength() << " " << node->data.GetWidth() << " " << node->data.GetHeight() << " " << node->data.GetColor() << "\n";
        node = node->next;
    }

    List<Car>* listResultbin = new List<Car>();

    writeToBin(listSource, "in.bin");
    readFromBinFile(listResultbin, "in.bin");
    size = listResultbin->size();
    node = listResultbin->peek_head();
    std::cout << "BIN file in object output: " << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cout << node->data.GetBrand() << " " << node->data.GetEnum() << " " << node->data.GetVolume() << " " << node->data.GetPower() << " " << node->data.GetDoorNum() << " "
            << node->data.GetLength() << " " << node->data.GetWidth() << " " << node->data.GetHeight() << " " << node->data.GetColor() << "\n";
        node = node->next;
    }

    /*List<int> IntList;
    IntList.push(3);
    IntList.push(5);
    IntList.push(7);
    IntList.push(11);
    IntList.push(13);
    cout << "List with int type: ";
    IntList.print();
    int peek = IntList.peek();
    int peek_back = IntList.peek_back();
    cout << "peek: " << peek << "       peek_back: " << peek_back << endl;
    IntList.pop();
    cout << "List after pop: ";
    IntList.print();
    IntList.pop_back();
    cout << "List after pop_back: ";
    IntList.print();
    cout << endl;

    List<string> StringList;
    StringList.push("tail");
    StringList.push("middle");
    StringList.push("head");
    cout << "List with string type: ";
    StringList.print();
    StringList.pop();
    cout << "List after pop: ";
    StringList.print();
    StringList.pop_back();
    cout << "List after pop_back: ";
    StringList.print();*/

    return 0;
}
