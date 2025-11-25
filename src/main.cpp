#include <iostream>
#include "../include/combinatorics.h"

int main()
{
    IMD::Fibonacci_numbers fn(5);

    for (int i = 0; i < 10; ++i)
    {
        std::cout << fn.current() << std::endl;
        fn.next();
    }
    std::cout << "Hello, world!" << std::endl;

    return 0;
}