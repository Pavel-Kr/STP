#include <iostream>
#include "TMemory.h"

int main()
{
    TMemory<int> memory;
    std::cout << "Memory data: " << memory.read() << std::endl;
    std::cout << "Memory state: " << memory.getState() << std::endl;
    memory.write(5);
    std::cout << "Memory data: " << memory.read() << std::endl;
    std::cout << "Memory state: " << memory.getState() << std::endl;
    memory.add(10);
    std::cout << "Memory data: " << memory.read() << std::endl;
    std::cout << "Memory state: " << memory.getState() << std::endl;
    memory.clear();
    std::cout << "Memory data: " << memory.read() << std::endl;
    std::cout << "Memory state: " << memory.getState() << std::endl;
}
