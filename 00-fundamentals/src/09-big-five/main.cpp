/*
 * @author      morgan bergen
 * @date        fri jan 20 2023
 * @brief       overview of the big five
 */

#include <iostream>
#include <vector>
#include "IntCell.h"

void pointers();
void newpointers();

int main() {

    int num = 10;

    IntCell a{num};
    IntCell b = a; 

    IntCell c;
    c = b;

    a.write(9999);

    std::cout << "a: " << a.read() << std::endl;
    std::cout << "b: " << b.read() << std::endl;
    std::cout << "c: " << c.read() << std::endl;


    return(0);
}

void newpointers() {

    int* storage = nullptr;

    storage = new int;

    int x = 10;

    storage = &x;

    std::cout << *storage << std::endl;

    storage = nullptr;

    delete storage;

}

void pointers() {

    int* x;
    int y = 5;
    x = &y;

    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;
    std::cout << "*x = " << *x << std::endl;
    std::cout << "&y = " << &y << std::endl;
    std::cout << "&x = " << &x << std::endl;
    
}


