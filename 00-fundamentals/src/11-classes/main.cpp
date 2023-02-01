/*
 * @author      morgan bergen
 * @date        fri jan 20 2023
 * @brief       overview of pointer
 */

#include <iostream>
#include <vector>
#include <string>
/*
 * "./num.h" is in the same directory as this file
 * "include/num.h" is in the include directory
 * "../num.h" is in the parent directory
 */
#include "num.h"

int main() {
    
    /*
     * num is a class name and can be interpreted as a programmer defined data type
     */
    num a{55};

    num b{a};
    a.print();


    return(0);
}

