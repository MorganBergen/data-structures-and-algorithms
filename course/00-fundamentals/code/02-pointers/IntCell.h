#ifndef IntCell_h
#define IntCell_h
#include <iostream>
#include <string>
#include <vector>

class IntCell {
    public:
        explicit IntCell(int initial_value = 0);
        int read();
        void write(int x);

    private:
        int stored_value;
};

#endif // intcell_h
