#include "IntCell.h"
#include <iostream>
#include <vector>
#include <algorithm>

IntCell::IntCell(int initial_value) : stored_value{initial_value} {
    std::cout << "constructor called!" << std::endl;
}

int IntCell::read() {
    return(stored_value);
}

void IntCell::write(int x){
    stored_value = x;
}

