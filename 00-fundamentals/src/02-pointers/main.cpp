#include <iostream>
#include <string>
#include <vector>

#include "IntCell.h"

int main() {

    IntCell* object = nullptr;

    object = new IntCell;

    /*
     * -> accessing members of an object through a pointer
     *  if a pointer variable points at a class type, then a visible member of the object 
     *  being pointed at can be accessed through the -> operator.
     */
    std::cout << "object -> read() is " << object -> read() << std::endl;

    delete object;

    IntCell* green = nullptr;

    green = new IntCell{55};

    std::cout << "green -> read() " << green -> read() << std::endl;

    IntCell red_not_ptr{1000};

    green = &red_not_ptr;

    std::cout << "red_not_ptr -> read() " << red_not_ptr.read() << std::endl;
    std::cout << "green -> read() " << green -> read() << std::endl;

    return(0);
}
