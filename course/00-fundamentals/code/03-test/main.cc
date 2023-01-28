#include <iostream>
#include <string>

int main() {

    int* a = nullptr;

    a = new int;

    *a = 5;

    int* b = nullptr;

    int c = 10;

    // this doesnt need a &a because a is a pointer
    b = a;

    b = &c;

    std::cout << "a" << std::endl;
    std::cout << "dereferencing " << *a << std::endl;
    std::cout << "value of pointer is the address " << a << std::endl;
    std::cout << "the memory address is " << &a << std::endl;

    std::cout << "b" << std::endl;
    std::cout << "dereferencing " << *b << std::endl;
    std::cout << "value of pointer is the address " << b << std::endl;
    std::cout << "the memory address is " << &b << std::endl;

    std::cout << "c" << std::endl;
    std::cout << "dereferencing " << "*c" << std::endl;
    std::cout << "value of pointer is the address " << c << std::endl;
    std::cout << "the memory address is " << &c << std::endl;

    return(0);

}

/*
 * segmentation fault
 * the program segments the memory space and it faults
 */
