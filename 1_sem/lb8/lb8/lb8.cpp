#include <iostream>
#include <forward_list>
#include <algorithm>

void doubleNum(int& num) 
{
    num *= 2;
}

bool numHigher(const int a, const int b)
{
    return a > b;
}

template <typename Iterator, typename CompareFunction>
void mySort(Iterator begin, Iterator end, CompareFunction compare) {
    for (Iterator i = begin; i != end; ++i) {
        Iterator min = i;
        for (Iterator j = i; j != end; ++j) {
            if (compare(j, min)) {
                min = j;
            }
        }
        if (min != i) {
            std::iter_swap(i, min);
        }
    }
}

int main()
{
    std::forward_list<int> IntList;
    IntList.push_front(4);
    IntList.push_front(2);
    IntList.push_front(1);
    IntList.push_front(3);

    std::cout << "forward_list elements: ";
    for (int i : IntList)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    /*mySort(IntList.begin(), IntList.end(), [](const auto& a, const auto& b) {
        return a > b;
        });*/
    IntList.sort();

    std::cout << "sorted forward_list elements: ";
    for (int i : IntList)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::for_each(IntList.begin(), IntList.end(), doubleNum);

    std::cout << "sorted and doubled forward_list elements: ";
    for (int i : IntList)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
