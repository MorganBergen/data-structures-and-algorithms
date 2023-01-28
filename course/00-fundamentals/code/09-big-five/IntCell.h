/*
 * @author      morgan bergen
 * @date        sat jan 23
 * @brief       overview of the class intcell
 */

#ifndef IntCell_h
#define IntCell_h

#include <iostream>

class IntCell {
    public:
      
        // default constructor
        explicit IntCell(int initialvalue = 0) {
            stored_value = nullptr;
            stored_value = &initialvalue;
            stored_value = new int{};
            *stored_value = initialvalue;
            std::cout << "default constructor has been called with " << initialvalue << std::endl;
        }

        // copy constructor
        IntCell(const IntCell& rhs) {
            stored_value = nullptr;
            stored_value = new int{};
            *stored_value = *rhs.stored_value;
            std::cout << "copy constructor has been called with " << *rhs.stored_value << std::endl;
        }

        // move constructor
        IntCell(IntCell&& rhs) : stored_value{rhs.stored_value} {
            rhs.stored_value = nullptr;
            std::cout << "move constructor has been called with " << *stored_value << std::endl;
        }

        /*
         * the move constructor is a special type of constructor that is used to move 
         * resources from one object to another
         * the move constructor is defined as IntCell(IntCell&& rhs) : stored_value{rhs.stored_value}
         * && syntax is used to indicate that this is a move constructor
         * rhs is a parameter that is passed by reference and is a rvalue reference 
         * meaning it is a temporary object
         * for example std::string h = "hello"; the "hello" is a rvalue
         * && symbol is used to denoted a "rvalue reference"
         *
         * 
         */

        int read() {
            return *stored_value;
        }

        void write(int x) {
            stored_value = &x;
        }
 
        ~IntCell() {
            stored_value = nullptr;
            delete stored_value;
        }
    
    private:
        int* stored_value;
};

#endif
