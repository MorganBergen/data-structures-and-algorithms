#include <iostream>
#include <string>
#include "IntCell.h"

int main() {

    
    // IntCell* m;
    // error: member reference type 'IntCell *' is a pointer; did you mean to use '->'?
    // std::cout << m.read() << std::endl; 
    //              ~^
    //              ->
    // std::cout << m->read() << std::endl;
   
    IntCell moragn{0};
    IntCell bergen{};

    

    return(0);
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
 * dynamic memory allocation 
 */
