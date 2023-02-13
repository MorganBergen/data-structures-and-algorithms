#ifndef __INTCELL_H__
#define __INTCELL_H__

#include <algorithm>
#include <iostream>

using namespace std;

class IntCell {
    public:
        
        explicit IntCell(int initialValue = 0) {
            storedValue = new int{initialValue};
        }

        ~IntCell() {
            delete storedValue;
        }

        IntCell(const IntCell &rhs) {
            storedValue = new int{*rhs.storedValue};
        }

        IntCell(IntCell &&rhs) : storedValue{rhs.storedValue} {
            rhs.storedValue = nullptr;
        }

        IntCell & operator=(const IntCell & rhs) {
            if (this != &rhs) {
                *storedValue = *rhs.storedValue;
            }
            return *this;
        }

        IntCell & operator= (IntCell && rhs) {
            swap(storedValue, rhs.storedValue);
            return *this;
        }

        int read() const {
            return *storedValue;
        }

        void write(int x) {
            *storedValue = x;
        }

    private:
        int *storedValue;
};

#endif
