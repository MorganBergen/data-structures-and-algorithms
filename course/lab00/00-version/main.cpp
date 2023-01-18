#include <iostream>

int main(int argc, char* argv[]) {

    if (argc != 2) {
        std::cout << "correct compiler command \ng++ -std=c++11 MainTest.cpp -o Lab1" << std::endl;
        std::cout << "provide the correct test input \n./Lab1 input.txt >results.txt" << std::endl;
    } else {
        std::cout << "argc = " << argc << std::endl;
        std::cout << "argv[0] = " << argv[0] << std::endl;
        std::cout << "argv[1] = " << argv[1] << std::endl;
    }


return (0);
}
