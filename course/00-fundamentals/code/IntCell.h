/*
 * @author      morgan bergen
 * @date        sat jan 21 2023
 * @brief       overview of the class intcell
 */


/*
 * preprocessor directives are placed in the header file
 * source code that requires knowledge of the interface must have an #include <filename.h>
 * #ifndef is checks if the identifier has been defined
 * an identifier is a name that is used to identify a variable, function, class, module, or any other user-defined item
 * #define is used to define an identifier
 * #endif is used to end the #ifndef and tells the compiler that the #ifndef block has ended
 */
#ifndef IntCell_h
#define IntCell_h

#include <iostream>

class IntCell {
    public:
        /*
        IntCell();
        IntCell(int initial_value);
        */
       
        explicit IntCell(int initialvalue = 0): 
            stored_value{initialvalue} {}

        int read();

        void write(int x);

    private:
        int stored_value;
};

#endif // IntCell_h
