# stacks and queues

**contents**

1.  [objective](#objective)
2.  [specification](#specification)
3.  [testing](#testing)
-  [stacks](#stacks)
-  [queues](#queues) 

## objective

get familiar with the basic operations suppored by stacks and queues as well as their array-based implementations.

## specification

complete the missing code in the following templates

the `mystack` and `myqueue` classes should inherit from the `myvector` class

```c++
#ifndef __MYSTACK_H__
#define __MYSTACK_H__

#include <iostream>
#include <algorithm>

#include <MyVector.h>  // undefined review later

template <typename DataType>
class MyStack : private MyVector<DataType> {
    public :
        explicit MyStack(size_t initSize = 0) {}
        MyStack(const MyStack & rhs) {}
        MyStack(MyStack && rhs) {}
        ~MyStack() {}
        MyStack & operator= (const MyStack & rhs) {}
        MyStack & operator= (MyStack && rhs) {}
        void push(const DataType & x) {}
        void push(DataType && x) {}
        void pop(void) {}
        const DataType & top(void) const {}
        bool empty(void) const {}
        size_t size() const {}
        size_t capacity(void) const {}
};

#endif
```

## testing

you will be tested over the following compiler under **Ubuntu 20.04 LTS using `g++` version 9.3.0 (default) with C++11 standard**


