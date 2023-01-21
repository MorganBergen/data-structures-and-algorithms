/*
 * @author      morgan bergen
 * @date        fri jan 20 2023
 * @brief       overview of pointer
 */

#include <iostream>

int main() {
    
    int* x;
    int y = 5;
    x = &y;
    
    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;
    std::cout << "*x = " << *x << std::endl;
    std::cout << "&y = " << &y << std::endl;
    std::cout << "&x = " << &x << std::endl;
    

    return(0);
}
