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
        std::cout << "correct compiler command \ng++ -std=c++11 MainTest.cpp -o Lab1\n";
        std::cout << "provide the correct test input \n./Lab1 input.txt >results.txt\n";
    } else {
        std::cout << "argc = " << argc << std::endl;
        std::cout << "argv[0] = " << argv[0] << std::endl;
        std::cout << "argv[1] = " << argv[1] << std::endl;
    }
    
    MyNumber a(5);


return (0);
}









