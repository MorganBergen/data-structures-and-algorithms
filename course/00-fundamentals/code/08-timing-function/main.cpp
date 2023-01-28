/*
 * @file    main.cpp
 * @author  morgan bergen
 * @date    jan 27 2023
 * @brief   lvalue and rvalue references
 */

#include <iostream>
#include <string>

void print_byval(std::string s) {
    std::cout << "print by value " << s << std::endl;
    return;
}

void print_byref(std::string& s) {
    std::cout << "print by string " << s << std::endl;
    return;
}

int main() {

    std::string x = "x";

    for (size_t i = 0; i < 1000; ++i) {
    
       print_byref(x);
       print_byval(x);
    }

    // time the difference between pass by value and pass by reference
    // terminal command to time the function is time ./main
    // ./a  0.00s user 0.01s system 4% cpu 0.196 total

    



    return(0);
}
