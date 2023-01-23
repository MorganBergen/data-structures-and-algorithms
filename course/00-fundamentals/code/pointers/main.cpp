#include <iostream>
#include <string>
#include <vector>

#include "IntCell.h"

int main() {

    IntCell* object = nullptr;

    object = new IntCell;

    std::cout << object -> read() << std::endl;

    delete object;

    std::cout << object -> read() << std::endl;

    return(0);
}
