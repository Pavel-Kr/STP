#include <iostream>
#include <locale>
#include "metrics.h"

int main()
{
    setlocale(LC_ALL, "rus");
    one();
    std::cout << std::endl;
    two();
    std::cout << std::endl;
    three();
    std::cout << std::endl;
    four();
    std::cout << std::endl;
    five();
    std::cout << std::endl;
    six();
    std::cout << std::endl;
    seven();
}
