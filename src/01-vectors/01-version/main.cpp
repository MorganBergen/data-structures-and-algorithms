#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "myvector.h"

int main() {

    myvector<int> red{3};

    // red[0] = 000;
    // red[1] = 111;
    // red[2] = 222;

    std::cout << "size:  " << red.size() << std::endl;
    std::cout << "capacity:  " << red.capacity() << std::endl;
    std::cout << "spare capacity:  " << red.SPARE_CAPACITY << std::endl;
    std::cout << "empty:  " << red.empty() << std::endl;

    if (red.empty() == true) {
        std::cout << "red vector is empty" << std::endl;
    } else {
        std::cout << "red vector is not empty" << std::endl;
    }


    return(0);
}
