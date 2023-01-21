/*
 * @author      morgan bergen
 * @date        fri jan 20 2023
 * @brief       overview of pointer
 */

#include <iostream>
#include "IntCell.h"

void pointer_review();
        

int main() {
    
    // instantiate an IntCell object
    IntCell red_box;
    
    // . is what is called the member selection operator
    // it's used to call a member function of that object
    std::cout << "red_box " << red_box.read() << std::endl;

    IntCell blue_box(1000);
    std::cout << "blue_box " << blue_box.read() << std::endl;

    std::cout << "red_box = blue_box" << std::endl;
    red_box = blue_box;

    std::cout << "red_box " << red_box.read() << std::endl;
    std::cout << "blue_box " << blue_box.read() << std::endl;

    std::cout << "red_box = 9999999" << std::endl;
    red_box = 9999999;
    
    std::cout << "red_box " << red_box.read() << std::endl;
    std::cout << "blue_box " << blue_box.read() << std::endl;


    IntCell green_box = 8;

    std::cout << "green_box " << green_box.read() << std::endl;

    return(0);
}

void pointer_review() {

    int* x;
    int y = 5;
    x = &y;

    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;
    std::cout << "*x = " << *x << std::endl;
    std::cout << "&y = " << &y << std::endl;
    std::cout << "&x = " << &x << std::endl;
    
}
