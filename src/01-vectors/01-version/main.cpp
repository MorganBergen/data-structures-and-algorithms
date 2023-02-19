<<<<<<< HEAD
=======
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "myvector.h"

int main() {

    myvector<int> red{10};

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


>>>>>>> 3457f6b (added new files for the 01 vectors)
