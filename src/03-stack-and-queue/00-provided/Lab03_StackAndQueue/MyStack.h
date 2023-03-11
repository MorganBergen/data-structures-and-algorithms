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
        // code begins
        MyVector<DataType>::resize(initSize);
        // code ends
    }

    // copy constructor
    MyStack(const MyStack & rhs) {
        // code begins
		this->resize(rhs.size()); // resize to the same size as rhs
		std::copy(rhs.data, rhs.data + rhs.size(), this->data); // copy elements
        // code ends
    }

    // move constructor
    MyStack(MyStack && rhs) {
        // code begins
		this->theSize = rhs.theSize;
		this->theCapacity = rhs.theCapacity;
		this->data = rhs.data;
		rhs.theSize = 0;
		rhs.theCapacity = 0;
		rhs.data = nullptr;
        // code ends
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
        // code begins
		this->resize(this->size() + 1); // increase size by 1
		this->data[this->size() - 1] = x; // insert element at the end
        // code ends
    }

    // insert x to the stack
    void push(DataType && x) {
        // code begins
		this->resize(this->size() + 1); // increase size by 1
		this->data[this->size() - 1] = std::move(x); // insert element at the end
		// code ends
    }

    // remove the last element from the stack
    void pop(void) {
        // code begins
		if (!this->empty()) {
			this->resize(this->size() - 1); // decrease size by 1
		}
        // code ends
    }

    // access the last element of the stack
    const DataType & top(void) const {
        // code begins
		if (!this->empty()) {
			return this->data[this->size() - 1];
		}
		throw std::out_of_range("stack is empty");
        // code ends
    }

    // check if the stack is empty; return TRUE is empty; FALSE otherwise
    bool empty(void) const {
        // code begins
		return this->size() == 0;
        // code ends
    }

    // access the size of the stack
    size_t size() const {
        // code begins
		return this->theSize;
        // code ends
    }

    // access the capacity of the stack
    size_t capacity(void) const {
        // code begins
		return this->theCapacity;
        // code ends
    }

};


#endif // __MYSTACK_H__
