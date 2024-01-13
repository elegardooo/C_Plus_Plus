#include <iostream>
#include "List.h"

bool condition_128(const int num) 
{
    return num == 128;
}

bool compare_higher(const int a, const int b) 
{
    return a > b;
}

int main(void) 
{

    List<int> IntList;

    IntList.push(64);
    IntList.push(128);
    IntList.push(256);

    std::cout << "List: ";

    for (auto& it : IntList)
    {
        std::cout << it << " ";
    }

    std::cout << std::endl;

    //оператор +
    List<int>::Iterator iter = IntList.begin();
    //*iter = *(iter + 2);

    //вывод и изменения
    IntList.sort(IntList.begin(), IntList.end(), compare_higher);

    std::cout << "Sorted List: ";

    for (auto it = IntList.begin(); it != IntList.end(); ++it) 
    {
        std::cout << *it << " ";
    }
    //for (auto it = IntList.begin(); it != IntList.end(); ++it) {
    //	*it = 777;
    //}

    std::cout << std::endl;

    /*for (auto& it : IntList) 
    {
        std::cout << it << " ";
    }

    std::cout << std::endl;*/

    //проверка поиска
    /*List<int>::Iterator*/ iter = IntList.search(IntList.begin(), IntList.end(), condition_128);

    if (iter != IntList.end()) 
    {
        std::cout << "Found: " << *iter << std::endl;
    }
    else 
    {
        std::cout << "Not found" << std::endl;
    }

    return 0;

}