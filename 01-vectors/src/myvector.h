#ifndef _MYVECTOR_H_
#define _MYVECTOR_H_
#include <iostream>

template <typename datatype>

class myvector {
    public:
        myvector(const int init_capacity = 16) 
            : the_size{0}, the_capacity{init_capacity} {
                std::cout << "constructor called" << std::endl;
                data = new datatype [init_capacity];
                std::cout << "size = " << the_size << std::endl;
                std::cout << "capacity = " << the_capacity << std::endl;
        }
        
        ~myvector() {
            delete [] data;
        }

        int size(void) {
            return (the_size);
        }

        int capacity(void) {
            return (the_capacity);
        }

        void print(void) {
            std::cout << "printing the vector" << std::endl;
            for (int i = 0; i < the_capacity; ++i) {
                std::cout << "" << data[i] << ", ";
            }
        }

        void insert(const datatype &value, const int index) {
            the_size = index + 1;
            if (index <= the_size && the_size < the_capacity) {
                for (int i = the_size -1; i >= index; --i) {
                    std::cout << "inserting..." << std::endl;
                    data[i + 1] = std::move(data[i]);
                }
                data[index] = value;
                ++the_size;
            } else {
                std::cout << "insert function cannot insert because size conditioanl isnt met\n";
                std::cout << "index = " << index << " <= " << "size = " << the_size << std::endl;
            }
            return;
        }

        void push_back(const datatype &value) {
            insert(value, the_size);
        }

    private:
        datatype *data = nullptr;
        int the_size;
        int the_capacity;
};

#endif
