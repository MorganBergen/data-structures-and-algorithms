#include <iostream>
#include <string>
#include "myvector.h"

int main() {
    
    myvector<int> a{};
    
    std::cout << "size of vector " << a.size() << std::endl;

    std::cout << "capacity of vector " << a.capacity() << std::endl;

    a.insert(15, 2);
    a.insert(-88, 7);
    a.print();

    return(0);
}
