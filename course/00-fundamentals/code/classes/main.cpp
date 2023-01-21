/*
 * @author      morgan bergen
 * @date        fri jan 20 2023
 * @brief       overview of pointer
 */

#include <iostream>
#include <vector>
#include "IntCell.h"

void pointer_review();
void vector_review();
void object_review();

int main() {
    IntCell obj1{};     // calls the default constructor
    IntCell obj2{12};   // calls the parameterized constructor

    IntCell greenbox{};
    IntCell bluebox{5};
    IntCell redbox{999999};

    std::cout << "greenbox: " << greenbox.read() << std::endl;
    std::cout << "bluebox: " << bluebox.read() << std::endl;
    std::cout << "redbox: " << redbox.read() << std::endl;

    // a vector of type IntCell containing IntCell objects
    std::vector<IntCell> colorbox {greenbox, bluebox, redbox};

    // range function in the standard library
    for (int i = 0; i < colorbox.size(); i++) {
        std::cout << "colorbox[" << i << "]: " << colorbox[i].read() << '\n'; 
    }
    
    int i = 0;
    // range based for loop
    for ( auto x : colorbox) {
        std::cout << "colorbox[" << i << "]: " << x.read() << '\n';
        i++;
    }

    /*
     * the range based for loop is appropriate only if every item 
     * that is being accessed sequentially and if the index is not needed
     * it can be used to access the elements of a vector, array, or string
     */

    return(0);
}





void vector_review() {
    std::vector<int> green_vector {5, 4, 3, 2, 1, 0};
    
    for (int i = 0; i < green_vector.size(); i++) {
        std::cout << green_vector[i] << std::endl;
    }
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


