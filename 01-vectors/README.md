# vector data structure

`MyVector`

-  `size_t the_size`
-  `size_t the_capacity`
-  `data_type *data`
-  `static const size_t SPARE_CAPACITY = 16`
-  `explicit MyVector(size_t init_size = 0)`
-  `MyVector(const MyVector & rhs)`
-  `MyVector(MyVector && rhs)`
-  `MyVector(const std::vector<data_type> & rhs)`
-  `~MyVector()`
-  `MyVector & operator= (const MyVector & rhs)`
-  `MyVector & operator= (MyVector && rhs)`
-  `void resize(size_t new_size)`
-  `void reserve(size_t new_capacity)`
-  `data_type & operator[] (size_t index)`


```cpp
#ifndef __MYVECTOR_H__
#define __MYVECTOR_H__
#include <utility>
#include <vector>

template <typename T>
class myvector {
    private:
        size_t the_size;
        size_t the_capacity;
        T *data;

    public:
        static const size_t SPARE_CAPACITY = 16;
        
        explicit myvector(size_t init_size = 0) :
            the_size{init_size},
            the_capacity{init_size + SPARE_CAPACITY} {
                data = new T[the_capacity];
        }

        myvector(const myvector & rhs) :
            the_size{rhs.rhs_size},
            the_capacity{rhs.the_capacity} {
                data = nullptr;
                data = new T[the_capacity];
                for (int i = 0, i < init_size; i++) {
                    data[i] = rhs.data[i];
                }
        }
        
        myvector(const std::vector<T> & rhs) :
            the_size{rhs.the_size},
            the_capacity{rhs.the_capacity},
            data{rhs.data} {
                rhs.data = nullptr;
                rhs.the_size = 0;
                rhs.the_capacity = 0;
        }

        myvector(


    




};

#endif
