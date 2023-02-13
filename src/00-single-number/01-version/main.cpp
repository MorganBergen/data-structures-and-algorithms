/*
 * @author      morgan bergen
 * @file        main.cpp
 * @date        jan 18 2023
 * @brief       main is responsible for for file io, and streaming
 */

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "MyNumber.h"

int main(int argc, char* argv[]) {

    if (argc != 2) {
    
        std::cout << "please provide test input!" << std::endl;

    } else {
        std::cout << "argc = " << argc << std::endl;
        std::cout << "argv[0] = " << argv[0] << std::endl;
        std::cout << "argv[1] = " << argv[1] << std::endl;
    }

    MyNumber a(5);

    return (0);
}









