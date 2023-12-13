#include <iostream>
#include "TSet.h"

int main()
{
    TSet<int> set1;
    set1.add(5);
    set1.add(3);
    set1.add(5);
    set1.add(6);
    std::cout << set1[0] << std::endl;
    std::cout << set1[1] << std::endl;
    std::cout << set1[2] << std::endl;
}
