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
        MyVector<DataType>::resize(newSize);
    }

    // requests for newCapacity amount of space
    void reserve(size_t newCapacity) {
        MyVector<DataType>::reserve(newCapacity);
    }

  public:

    // default constructor
    explicit MyQueue(size_t initSize = 0) {
        this -> theSize = initSize;
        this -> theCapacity = initSize + this -> SPARE_CAPACITY;
        this -> data = new DataType[this -> theCapacity];
        dataStart = 0;
        dataEnd = ( this->theSize ) - 1;
    }

    // copy constructor
    MyQueue(const MyQueue & rhs) {
        this -> theSize = rhs.theSize;
        this -> theCapacity = rhs.theCapacity;

        this -> data = new DataType[this -> theCapacity];

        for (int i = 0; i < rhs.theSize; i++) {
            this -> data[i] = rhs.data[i];
        }
    }

    // move constructor
    MyQueue(MyQueue && rhs) {
        this -> theSize = rhs.theSize;
        this -> theCapacity = rhs.theCapacity;
        this -> data = rhs.data;
        rhs.data = nullptr;
        rhs.theSize = 0;
        rhs.theCapacity = 0;
	    rhs.dataStart = 0;
	    rhs.dataEnd = 0;
    }

    // destructor
    ~MyQueue() {
        delete[] this -> data;
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
        MyVector<DataType>::push_back(x);
    }

    // insert x into the queue
    void enqueue(DataType && x) {
        MyVector<DataType>::push_back(std::move(x));
    }

    // remove the first element from the queue
    void dequeue(void) {

        for ( int i = 0; i < this->theSize; i++ ) {
            this -> data[i] = std::move(this->data[ i + 1 ]);
        }

        (this -> theSize)--;
    }

    // access the first element of the queue
    const DataType & front(void) const {
        return this -> data[0];
    }

    // check if the queue is empty; return TRUE is empty; FALSE otherwise
    bool empty(void) const {
        return MyVector<DataType>::empty();
    }

    // access the size of the queue
    size_t size() const {
        return MyVector<DataType>::size();
    }

    // access the capacity of the queue
    size_t capacity(void) const {
        return MyVector<DataType>::capacity();
    }
};

#endif // __MYQUEUE_H__
