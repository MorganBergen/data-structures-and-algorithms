/*
 * @author      morgan bergen
 * @date        sat jan 21 2023
 * @brief       implementation file for IntCell class
 */

#include "IntCell.h"
#include <iostream>

/*
// The IntCell class defines two constructors. 
// The first is called if no parameter is specified.
IntCell::IntCell() {
    stored_value = 0;
    std::cout << "this constructor is called!" << std::endl;
}

// The second is called if an int parameter is provided, and uses that int to initialize the storedValue member.
IntCell::IntCell(int initial_value) {
    stored_value = initial_value;
}
*/

// constructor with initializor list
// this is the same as the above two constructors
// but it is more efficient
// : is an operator that tells the compiler to initialize the member variables
// function body is empty because well there's nothing more to do
explicit IntCell::IntCell(int initial_value) : stored_value{initial_value} {
    // empty
}


/* read()
 * a constant member function examines but does not change the state
 * of its object is an accessor function
 */
int IntCell::read() {
    return stored_value;
}

/* write()
 * a non-constant member function can change the state of its object
 * is a mutator function
 */
void IntCell::write(int x) {
    stored_value = x;
}

