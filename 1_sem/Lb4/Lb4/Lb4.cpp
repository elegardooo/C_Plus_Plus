#include <iostream>
#include "List.h"

using namespace std;

int main()
{
    List<int> IntList;
    IntList.push(3);
    IntList.push(5);
    IntList.push(7);
    IntList.push(11);
    IntList.push(13);
    cout << "List with int type: ";
    IntList.print();
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
    StringList.print();
    return 0;
}
