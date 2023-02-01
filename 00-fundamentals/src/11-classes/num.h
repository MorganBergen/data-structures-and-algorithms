#ifndef __NUM_H__
#define __NUM_H__

#include <iostream>

class num {

    /* public methods, public data memebers
     * the members of the class can be accessed by other classes
     * if you define a public variable, then other classes can assess or even modify it
     */
    public:

        /*
         * constructor
         * how should we start or initial the class
         * constructors are called when an object is created
         * constructors are used to initialize the object's data members
         * constructors do not have any return types
         * simply the name and variables you want
         * we want the initializer to do two things
         * you dont need to use value as a pass by reference
         *
         * 1.  allocate/assign memory for the object's data members
         * 2.  initialize the object's data members
         */
        num(const int value){
            // new allocates memory within the memory block of the object
            data = new int;
            // initialize the data member
            *data = value;
            std::cout << "constructor called" << std::endl;
        };

        /* copy constructor
         * when you pass an object by reference, you are passing the address of the object
         * meaning all of the data members are passed by reference
         * you dont know that the object is a scalar value
         * const is used to prevent the object from being modified
         */
        num(const num &n) {
            data = n.data;
            // *data = *(n.data);
        }

        /* member accessor
         */
        void print(void) {
            std::cout << *data << std::endl;
        }
   
        /*
         * destructor
         * how should we end or destroy the class
         * destructors are called when an object is destroyed
         * destructors are used to free the object's data members
         * destructors do not have any return types
         * simply the name and variables you want
         * we want the destructor to do two things
         *
         * 1.  free the memory allocated for the object's data members
         * 2.  destroy the object's data members
         */
        ~num() {
            std::cout << "destructor called" << std::endl;
            /* 
             * delete frees the memory allocated for the object's data members
             * delete is a keyword
             * delete is a unary operator
             * delete is a unary operator that takes a pointer as an operand
             */
            // delete data;
        }

    /* private methods, private data members
     * only the members of the class can access the private members
     * if you define a private variable, then other classes cannot access it
     */
    private:

        /*
         * data members
         * we define the data in the class as a pointer so we can dynamically allocate memory
         * we want to store this on the heap so as to allow to store more data than the stack
         */
        int *data;

};

#endif

/*
 * each implementation is concerned with
 * data storage - 
 * data management - maintain some properties of data structures
 * data access - print, return, etc.
 */
