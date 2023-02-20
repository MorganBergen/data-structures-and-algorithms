#ifndef __MYVECTOR_H__
#define __MYVECTOR_H__

#include <utility>
#include <vector>

template <typename data_type>
class myvector {
    private:
        size_t the_size;
        size_t the_capacity;
        data_type* data;
    public:
        static const size_t SPARE_CAPACITY = 16;

        explicit myvector(size_t init_size = 0) :
            the_size{init_size},
            the_capacity{init_size + SPARE_CAPACITY} {
                data = new data_type[the_capacity];

                std::cout << "default constructor" << std::endl;
        }

        myvector(const myvector & rhs) :
            the_size{rhs.the_size}, 
            the_capacity{rhs.the_capacity},
            data{nullptr} {

                data = new data_type[the_capacity];

                for (int i = 0; i < the_size; ++i) {
                    data[i] = rhs.data[i]; 
                }

                std::cout << "copy constructor" << std::endl;
        }


        bool empty() const {
            if (the_size == 0) {
                return true;
            } else {
                return false;
            }
        }

        size_t size() const {
            return (the_size);
        }

        size_t capacity() const {
            return (the_capacity);
        }
};

#endif
