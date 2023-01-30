/*
 * @file    main.cpp
 * @author  morgan bergen
 * @date    jan 27 2023
 * @brief   lvalue and rvalue references
 */

#include <iostream>
#include <string>

int main() {

    int a = 5;
    
    int& lvalue_ref = a;

    int&& rvalue_ref = 5;

    lvalue_ref = rvalue_ref;

    // after changing the l value reference you change a
    lvalue_ref = 10;

    std::cout << "lvalue_ref: " << lvalue_ref << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "rvalue_ref: " << rvalue_ref << std::endl;

    return(0);
}
