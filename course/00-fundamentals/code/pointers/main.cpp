#include <iostream>
#include <string>
#include "IntCell.h"

void example();
void here();

int main() {


    here();

    for (int i = 0; i < 10; i++) {
        example();
    }

    return(0);
}


void example() {

    // datatype* variable_name = new datatype;
    // new returns the address of whatever follows it

    int* num = new int;

    *num = 5;

    std::cout << *num << std::endl;
    
    delete num;

}

void here() {

    // initialize the object to 0x0
    IntCell* m = nullptr;
    /*
     * at this point we have not initialized the object to a true value yet
     * so we cannot use the object yet
     * you always want to ensure that you declare your pointers with an initial value of nullptr
     * this ensures that there is no garbage value in the pointer
     */

    // allocate memory for m by calling the constructor
    m = new IntCell{};
    
    std::cout << "m     : " << m << std::endl;

    //the asterisk is used to dereference the pointer
    //dereferencing is when the pointer is used to access the object
    //referencing is when the pointer is used to access the address of the object
    //the word dereference is used to describe the process of accessing the object
    //the word reference is used to describe the process of accessing the address of the object

    std::cout << "cell contents: " << m->read() << std::endl;

    m -> write(5);

    std::cout << "cell contents " << m -> read() << std::endl;

    delete m;
}



/* a pointer variable is a variable that stores the address where another object resides
 * it is the fundamental mechanism used in many data structures
 * 
 * example
 * an array of items can be used but if you want to insert into the middle of the array
 * then you have to relocate many different items
 *
 * rather than storing the collection into a static array, it is common to store each item 
 * in a separate noncontguous piece of memory, which is allocated as the program runs
 * along with each object is a link to the next object
 * this link is a pointer variable because it stores a memory location of another object
 * classically like a linkedlist
 *
 *
 * dynamic memory allocation 
 *
 * garbage collection and delete
 * in some languages when an object is no longer referenced, it is subject to automatic garbage collection (e.g. python)
 * c++ does not have garbage collection
 * you must explicitly delete the object when you are done with it/jh
 */
