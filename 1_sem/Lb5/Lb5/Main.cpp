#include <iostream>
#include "List.h"

int main()
{
    List<int> IntList;
    char str[255];
    IntList.push(3);
    IntList.push(5);
    IntList.push(7);
    IntList.push(11);
    IntList.push(13);
    std::cout << "List with int type: ";
    IntList.print();
    try {
        if (IntList.isEmpty()) {
            throw EmptyListError();
        }
    std::cout << "peek: " << IntList.peek() << "     peek_back: " << IntList.peek_back() << std::endl;
    }
    catch (const EmptyListError& e)
    {
        e.show();
    }
    /*int peek = IntList.peek();
    int peek_back = IntList.peek_back();
    cout << "peek: " << peek << "       peek_back: " << peek_back << endl;*/
    IntList.pop();
    std::cout << "List after pop: ";
    IntList.print();
    IntList.pop_back();
    std::cout << "List after pop_back: ";
    IntList.print();
    std::cout << std::endl;
    try {
        int number = 0;
        std::cout << "Enter a positive number or zero: ";
        std::cin >> number;

        validateNumberInput(number);

        IntList.push(number);
        IntList.print();
    }
    catch (const exception& e)
    {
        e.show();
    }
    //IntList.print();


    List<std::string> StringList;
    StringList.push("tail");
    StringList.push("middle");
    StringList.push("head");
    std::cout << "List with string type: ";
    StringList.print();
    try {
        if (StringList.isEmpty()) {
            throw EmptyListError();
        }
        std::cout << "peek: " << StringList.peek() << "     peek_back: " << StringList.peek_back() << std::endl;
    }
    catch (const EmptyListError& e)
    {
        e.show();
    }
    StringList.pop();
    std::cout << "List after pop: ";
    StringList.print();
    StringList.pop_back();
    std::cout << "List after pop_back: ";
    StringList.print();
    try {
        std::cout << "Enter any word: ";
        std::cin >> str;

        validateStringInput(str);

        StringList.push(str);
        StringList.print();
    }
    catch (const exception& e)
    {
        e.show();
    }
    catch (...)
    {
        std::cout << "Unknown error" << std::endl;
    }
    //StringList.print();

    return 0;
}
