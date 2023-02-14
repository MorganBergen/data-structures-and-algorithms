#  vector

**content**

1.  [objective](#objective)
2.  [specification of the adt](#specification-of-the-adt)
3.  [requirements](#requirements)
4.  [evaluation](#evaluation)

##  objective

vector implementation with c++

## specification of the adt

- implement a vector data structure with the basic interface and methods
- implement an iterator class that supports the traverse of your vector data structure


```c++
#ifndef __MYVECTOR_H_
#define __MYVECTOR_H_

#include <utility>
#include <vector>

template <typename data_type>
class myvector {
    
    private:
        size_t the_size;
        size_t the_capacity;
        DataType* data;
    
    public:
        // initial capacity of the vector
        static const size_t SPARE_CAPACITY = 16;
        
        // default constructor
        explicit myvector(size_t init_size = 0) : the_size{init_size}, the_capacity{init_size + SPARE_CAPACITY} {}
        
        // copy constructor
        myvector(const myvector & rhs) : the_size{rhs.the_size}, the_capacity{rhs.the_capacity} {}
    
        // move constructor
        myvector(myvector && rhs) : the_size{rhs.the_size}, the_capacity{rhs.the_capacity}, data{rhs.data} {}
    
        // copy constructor from stl vector implementation
        myvector(const std::vector<data_type> & rhs) : the_size{rhs.size()}, the_capacity{rhs.size() + SPARE_CAPACITY} {}

        // destructor
        ~myvector() {}

        // copy assignment
        myvector & operator=(const myvector & rhs) {}

        // move assignment
        myvector & operator=(myvector && rhs) {}

        // resize the vector by changing the size of the array
        void resize(size_t new_capacity) {}

        // data access operator without bound checking
        data_type & operator[](size_t index) {}

        // data access operator with bound checking
        const data_type & operator[](size_t index) const {}

        // check if vector is empty; return true if the vector is empty and false otherwise
        bool empty() const {}

        // return the size of the vector        
        size_t size() const {}

        // returrn the capacity of the vector
        size_t capacity() const {}

        // insert a data element to the end of the vector
        void push_back(const data_type & x) {}
        
        // insert a data element to the end of the vector? 
        void push_back(data_type && x) {}

        // append a vector as indicated by the parameter to the current vector
        myvector<data_type>& append(myvector<data_type> && rhs) {}

        // remove the object at the end of the vector
        void pop_back() {}

        // return the last data element from the array
        const data_type* back() const {}

        // iterator implementation
        typedef data_type* iterator;
        
        // iterator implementation
        typedef const data_type* const_iterator;

        // 
        const_iterator begin() const {}

        //
        iterator end() {}

        //
        const_iterator end() const {}

};

#endif
```

## requirements

1.  rename the object into `myvector`, instead of `vector` as indicated in the textbok
2.  your object should contain a copy constructor that supports initialization from an stl vector object.  the constructor should have an interface of

`myvector(const std::vector<object>& rhs)`

3.  implement an "append" method, which appends all data elements in the parameter (as rvalue) to the current object.  the return value should be the current object.  the function has an interface of

`Myvector<object>& append(myvector<object> && rhs)`









