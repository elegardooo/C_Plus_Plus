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
    cout << "Hello world" << endl;
    return 0;
}
