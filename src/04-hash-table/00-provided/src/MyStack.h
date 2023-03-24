#ifndef __MYSTACK_H__
#define __MYSTACK_H__

#include <iostream>
#include <algorithm>

#include "MyVector.h"

template <typename DataType>
class MyStack : private MyVector<DataType> {
  public:

    // default constructor
    explicit MyStack(size_t initSize = 0) {
        MyVector<DataType>::resize(initSize);
    }

    // copy constructor
    MyStack(const MyStack & rhs) {
		this->resize(rhs.size()); // resize to the same size as rhs
		std::copy(rhs.data, rhs.data + rhs.size(), this->data); // copy elements
    }

    // move constructor
    MyStack(MyStack && rhs) {
		this->theSize = rhs.theSize;
		this->theCapacity = rhs.theCapacity;
		this->data = rhs.data;
		rhs.theSize = 0;
		rhs.theCapacity = 0;
		rhs.data = nullptr;
    }

    // destructor
	~MyStack() {
		//
	}

    // copy assignment
    MyStack & operator= (const MyStack & rhs) {
        // code begins
		MyStack temp(rhs);
		std::swap(*this, temp);
		return *this;
        // code ends
    }

    // move assignment
    MyStack & operator= (MyStack && rhs) {
        // code begins
		std::swap(this->theSize, rhs.theSize);
		std::swap(this->theCapacity, rhs.theCapacity);
		std::swap(this->data, rhs.data);
		return *this;
        // code ends
    }

    // insert x to the stack
    void push(const DataType & x) {
        this -> push_back(x);
    }

    // insert x to the stack
    void push(DataType && x) {
        this -> push_back(std::move(x));
    }

    // remove the last element from the stack
    void pop(void) {
        MyVector<DataType>::pop_back();
    }

    // access the last element of the stack
    const DataType & top(void) const {
        return this -> data[this -> theSize - 1];
    }

    // check if the stack is empty; return TRUE is empty; FALSE otherwise
    bool empty(void) const {
        return MyVector<DataType>::empty();
    }

    // access the size of the stack
    size_t size() const {
        return MyVector<DataType>::size();
    }

    // access the capacity of the stack
    size_t capacity(void) const {
        return MyVector<DataType>::capacity();
    }

};


#endif // __MYSTACK_H__
