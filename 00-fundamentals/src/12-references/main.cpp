#include <iostream>

int main() {
    
    /*
     * lvalue               an expression that refers to a memory location and can be refer to after initialization 
     *                      variables
     *                      function names
     *                      references to variables
     *
     * rvalue               an expression that does not refer to a memory location and cannot appear on the left hand side of the = operator
     *                      literals
     *                      temporary variables
     *                      results of expressions
     *
     * lvalue reference     a reference type that can bind to an lvalue expression, declared with &, an lvalue reference extends it's
     *                      lifetime of the objct it is referencing and allows for modifications of that object
     *                      int y = 10;     
     *                      int &x = y;
     *
     * rvalue reference     a reference type that can bind to an rvalue expression. an rvalue reference is declared with &&
     *                      it is used to move ownership of an object or to enable perfect forwarding of an argument
     *                      int &&x = 5;
     */

    int x = 10; // x is an lvalue
                // 10 is an rvalue
    int &y = x; // y is an lvalue reference
                // x is an lvalue
    
    int &&z = 55;   // z is a rvalue reference and can only bind to rvalues


    std::cout << "int x = 10; --> " << x << std::endl;
    std::cout << "int &y = x; --> " << y << std::endl;
    std::cout << "memory addresses" << std::endl;
    std::cout << "&x --> " << &x << std::endl;
    std::cout << "&y --> " << &y << std::endl;

    x = 999;
    std::cout << "\nx = 999;" << std::endl;
    std::cout << "any changes made to x will also change y" << std::endl;
    std::cout << "because the x and y identifiers are the same pieces in memory\n" << std::endl;

    std::cout << "x --> " << x << std::endl;
    std::cout << "y --> " << y << std::endl;
    std::cout << "memory addresses" << std::endl;
    std::cout << "&x --> " << &x << std::endl;
    std::cout << "&y --> " << &y << std::endl;

    std::cout << &z << std::endl;
    std::cout << "int &&z = 55; --> " << z << std::endl;

    z = 7;

    std::cout << "z = 7; --> " << z << std::endl;

    return(0);
}









