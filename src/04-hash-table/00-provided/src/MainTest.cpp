#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>

#include "MyInfixCalculator.h"

// using namespace std;

int main(int argc, char* argv[]) {

    if (argc != 2) {
        std::cout << "You have to provide one test";
        std::cout << "instance file and output file name to run the test main!\n";
        return(0);
    }

    std::ifstream inFile;
    inFile.open(argv[1]);
    
    if (inFile.is_open()) {
        std::string str;
        std::getline(inFile, str);

        // instantiate infix_calculator
        MyInfixCalculator infix_calculator;
        double a = infix_calculator.calculate(str);
        std::cout.precision(3);
        std::cout << std::fixed << a << std::endl;
    } else {
        std::cout << "The instance.txt file cannot be opened";
    }
    
    inFile.close();

    return(0);
}
