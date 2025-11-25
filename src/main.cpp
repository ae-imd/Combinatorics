#include <iostream>
#include "../include/combinatorics.h"

int main()
{
    IMD::geometric_progression gp(2, 3);
    gp.next();
    std::cout << gp.current() << std::endl;
    std::cout << "Hello, world!" << std::endl;

    return 0;
}