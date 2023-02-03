#ifndef __MYNUMBER_H__
#define __MYNUMBER_H__

#include <iostream>
#include <string>

template <typename DataType>
class MyNumber {
    public:
        // default constructor
        explicit MyNumber(DataType rhs = 0) {
            num = nullptr;
            num = new DataType{rhs};
            std::cout << "default constructor\n";
            std::cout << "*num " << *num << '\n';
            std::cout << "rhs " << rhs << '\n';
        }
        
        // copy constructor


    private:
        DataType *num;

};

#endif
