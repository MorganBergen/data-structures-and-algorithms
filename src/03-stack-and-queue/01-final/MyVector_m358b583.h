#ifndef __MYVECTOR_H__
#define __MYVECTOR_H__

#include <utility>
#include <vector>

template <typename DataType>
class MyVector {
  protected:

  public:

    size_t theSize;                         // the number of data elements the vector is currently holding
    size_t theCapacity;                     // maximum data elements the vector can hold
    DataType *data;                         // address of the data storage

    static const size_t SPARE_CAPACITY = 16;   // initial capacity of the vector

    // default constructor
    explicit MyVector(size_t initSize = 0) : 
        theSize{initSize},
        theCapacity{initSize + SPARE_CAPACITY} {
        data = new DataType[theCapacity];
    }

    // copy constructor
    MyVector(const MyVector & rhs) : 
        theSize{rhs.theSize},
        theCapacity{rhs.theCapacity} {
        data = nullptr;
        data = new DataType[theCapacity];
        for (int i = 0; i < theSize; ++i) {
            data[i] = rhs.data[i];
        }
    }

    // move constructor
    MyVector(MyVector&& rhs):
        theSize{rhs.theSize},
        theCapacity{rhs.theCapacity},
        data{rhs.data} {
        rhs.data = nullptr;
        rhs.theSize = 0;
        rhs.theCapacity = 0;
        
    }

    // copy constructor from STL vector implementation
    MyVector(const std::vector<DataType> & rhs) :
        theSize{rhs.size()},
        theCapacity{rhs.size() + SPARE_CAPACITY} {
        data = nullptr;
        data = new DataType[theCapacity];
        for (int i = 0; i < theSize; ++i) {
            data[i] = rhs[i];
        }
         
    }

    // destructor
    ~MyVector(){
        delete [] data;
    };

    // copy assignment
    MyVector & operator= (const MyVector& rhs){
        MyVector copy = rhs;
        std::swap(*this, copy);
        return (*this);
    }

    // move assignment
    MyVector & operator= (MyVector && rhs) {
        std::swap(theSize, rhs.theSize);
        std::swap(theCapacity, rhs.theCapacity);
        std::swap(data, rhs.data);
        rhs.data = nullptr;
        rhs.theSize = 0;
        rhs.theCapacity = 0;
        return (*this);
    }

    // change the size of the array
    void resize(size_t newSize){
        if (newSize > theCapacity) {
            reserve(newSize * 2);
        }
        theSize = newSize;
    }

    // allocate more memory for the array
    void reserve(size_t newCapacity) {
        if (newCapacity < theSize) {
            return;
        } 
        DataType *newData = new DataType[newCapacity];
        for (int i = 0; i < theSize; ++i) {
            newData[i] = std::move(data[i]);
        }
        theCapacity = newCapacity;
        std::swap(data, newData);
		delete [] newData;
    }

    // data access operator (without bound checking)
    DataType & operator[] (size_t index) {
        return data[index];
    }

    const DataType & operator[](size_t index) const {
        return data[index];
    }

    // check if the vector is empty; return TURE if the vector is empty
    bool empty() const {
        if (theSize == 0) {
            return true;
        } else {
            return false;
        }
    }

    // returns the size of the vector
    size_t size() const {
        return theSize;
    }

    // returns the capacity of the vector
    size_t capacity() const {
        return theCapacity;
    }

    // insert an data element to the end of the vector
    void push_back(const DataType & x) {
        if (theSize == theCapacity) {
            reserve(2 * theCapacity + 1);
        }
        data[theSize++] = x;
    }

    void push_back(DataType && x) {
        if (theSize == theCapacity) {
            reserve(2 * theCapacity + 1);
        } 
        data[theSize++] = std::move(x);
    }

    // append a vector as indicated by the parameter to the current vector
    MyVector<DataType>& append(MyVector<DataType> && rhs) {
        
        if (theSize + rhs.theSize > theCapacity) {
            reserve(theSize + rhs.theSize);
        }
        for (int i = 0; i < rhs.theSize; ++i) {
            data[theSize + i] = std::move(rhs.data[i]);
        }
        theSize += rhs.theSize;
        rhs.theSize = 0;
        return (*this);
    }

    // remove the last data element from the array
    void pop_back() {
        --theSize;
    }

    // returns the last data elemtn from the array
    const DataType& back() const  {
        return data[theSize - 1];
    }

    // iterator implementation

    typedef DataType* iterator;
    typedef const DataType* const_iterator;

    iterator begin() {
        return &data[0];
    }

    const_iterator begin() const {
        return &data[0];
    }

    iterator end() {
        return &data[size()];
    }

    const_iterator end() const {
        return &data[size()];
    }

};


#endif // __MYVECTOR_H__
