#ifndef classtype_h
#define classtype_h

#include <iostream>

class classtype {

    public:
        
        explicit classtype(int initial_value = 0){
            stored_value = nullptr;
            stored_value = new int{};
            *stored_value = initial_value;
        }

        classtype(const classtype &rhs) {
            stored_value = nullptr;
            stored_value = new int{};
            *stored_value = *rhs.stored_value;
        }

        classtype(classtype&& rhs) : stored_value{rhs.stored_value} {
            rhs.stored_value = nullptr;
        }

        classname &operator = (const classtype &rhs) {
            if (this != &rhs) {
                *stored_value = *rhs.stored_value'
            }
            return *this;
        }

        classtype &operator= (classtype &&rhs) {
            std::swap(stored_value, rhs.stored_value);
            return *this;
        }

        int write(int x) {
            *stored_value = x;
        }

        int read() const {
            return *stored_value;
        }

        ~classtype() {
            stored_value = nullptr;
            delete stored_value;
        }

    private:
        int* stored_value;

};

#endif
