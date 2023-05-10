#i;;fndef __VECTOR_H__
#define __VECTOR_H__

#include <utility>
#include <vector>

template <typename T>

class Vector {

    private:
        size_t size;
        size_t capacity;
        T *data;
    
    public:
        static const size_t SPARE_CAPACITY = 16;

        explicit Vector(size_t init_size = 0) :
            size{init_size}, capacity{init_size + SPARE_CAPACITY} {
                data = new T[capacity];
                std::cout << "size:\t\t" << size << std::endl;
                std::cout << "capacity:\t" << capacity << std::endl;
                std::cout << "spare capacity:\t" << SPARE_CAPACITY << std::endl;
        }

        Vector(const Vector & rhs) :
            size{rhs.size}, capacity{rhs.capacity}, data{rhs.data} {
                rhs.data = nullptr;
                rhs.size = 0;
                rhs.capacity = 0;
        }

        Vector(const std::vector<T> & rhs) :
            size{rhs.size()}, capacity{rhs.size() + SPARE_CAPACITY} {
                data = nullptr;
                data = new T[capacity];
                for (int i = 0; i < size; i++) {
                    data[i] = rhs[i];
                }
        }
        
        ~Vector() {
            delete [] data;
        }

        Vector & operator =(const std::vector & rhs) {
            Vector copy = rhs;
            std::swap(*this, copy);
            return(*this);
        }

        Vector & operator =(Vector && rhs) {
            std::swap(size, rhs.size);
            std::swap(capacity, rhs.capacity);
            std::swap(data, rhs.data);
            rhs.data = nullptr;
            rhs.capacity = 0;
            return(*this);
        }
        
        void resize(size_t new_size) {
            if (new_size > capacity) {
                reserve(new_size * 2);
            }
            size = new_size;
        }
        
        void reserve(size_t new_capacity) {
            if (new_capacity < the_size) {
                return;
            }
            T *new_data = new T[new_capacity];
        }
        

        
};

#endif



































