#ifndef __MYQUEUE_H__
#define __MYQUEUE_H__

#include <iostream>
#include <algorithm>

#include "MyVector.h"

template <typename DataType>
class MyQueue : private MyVector<DataType> {  
  private:
    size_t dataStart, dataEnd;

    // changes the size of the array to newSize
    void resize(size_t newSize) {
        if (newSize > this -> theCapacity) {
            reserve(newSize * 2);
        }
        this -> theSize = newSize;
    }

    // requests for newCapacity amount of space
    void reserve(size_t newCapacity) {
        if (newCapacity < this->theSize) {
            return;
        }
        DataType *newData = new DataType[newCapacity];
        for (int i = 0; i < this->theSize; ++i) {
            newData[i] = std::move(this->data[i]);
        }
        this->theCapacity = newCapacity;
        std::swap(this->data, newData);
        delete[] newData;
    }

  public:

    // default constructor
    explicit MyQueue(size_t initSize = 0) {
        this->theSize = initSize;
        this->theCapacity = initSize + MyVector<DataType>::SPARE_CAPACITY;
        this->data = new DataType[this->theCapacity];
    }

    // copy constructor
    MyQueue(const MyQueue & rhs) {
        this->theSize = rhs.theSize;
        this->theCapacity = rhs.theCapacity;
        this->dataStart = rhs.dataStart;
        this->dataEnd = rhs.dataEnd;
        this->data = new DataType[this->theCapacity];
        for (size_t i = dataStart; i < dataEnd; ++i) {
            this->data[i] = rhs.data[i];
        }
    }

    // move constructor
    MyQueue(MyQueue && rhs) {
        this->theSize = rhs.theSize;
        this->theCapacity = rhs.theCapacity;
        this->data = rhs.data;
        rhs.data = nullptr;
        rhs.theSize = 0;
        rhs.theCapacity = 0;
    }

    // destructor
    ~MyQueue() {
        delete[] this->data;
    }

    // copy assignment
    MyQueue & operator= (const MyQueue & rhs) {
        MyQueue copy{rhs};
        std::swap(*this, copy);
        return (*this);
    }

    // move assignment
    MyQueue & operator= (MyQueue && rhs) {
        std::swap(this->theSize, rhs.theSize);
        std::swap(this->theCapacity, rhs.theCapacity);
        std::swap(this->dataStart, rhs.dataStart);
        std::swap(this->dataEnd, rhs.dataEnd);
        std::swap(this->data, rhs.data);
        return (*this);
    }

    // insert x into the queue
    void enqueue(const DataType & x) {
        if (this->theSize == this->theCapacity) {
            reserve(this->theCapacity * 2);
        }
        this->data[this->dataEnd++] = x;
    }

    // insert x into the queue
    void enqueue(DataType && x) {
        if (this->theSize == this->theCapacity) {
            reserve(this->theCapacity * 2);
        }
        this->data[this->dataEnd++] = std::move(x);
    }

    // remove the first element from the queue
    void dequeue(void) {
        if (this->theSize == 0) {
            return;
        }
        this->dataStart++;
        this->theSize--;
    }

    // access the first element of the queue
    const DataType & front(void) const {
        return this->data[this->dataStart];
    }

    // check if the queue is empty; return TRUE is empty; FALSE otherwise
    bool empty(void) const {
        if (this->theSize == 0) {
            return true;
        } else {
            return false;
        }
    }

    // access the size of the queue
    size_t size() const {
        return this->theSize;
    }

    // access the capacity of the queue
    size_t capacity(void) const {
        return this->theCapacity;
    }
};

#endif // __MYQUEUE_H__
