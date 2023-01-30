# 00 the fundamentals
## data structures and algorithms

friday jan 20 2023

**contents**

1.  [acknowledgement](#acknowledgement)
2.  [some notes about labs](#some-notes-about-labs)
3.  [adt abstract data type](#adt-abstract-data-type)
4.  [fundamentals](#fundamentals)
5.  [c++ features](#c-features)
6.  [pointer](#pointer)
7.  [reference](#reference)
8.  [parameter passing](#parameter-passing)
9.  [object](#object)
10. [the big five](#the-big-five)
11. [template](#template)
12. [function parameter and function object](#function-parameter-and-function-object)
13. [complexity analysis](#complexity-analysis)
14. [lldb debugger](#lldb-debugger)
15. [summary](#summary)
16. [notes](#notes)

## acknowledgement

data structure comprised on [storage] and [operation], then there is the [interface/interaction], [programming algorithm].

```
                      [data structure]
                        /        \
                       /          \
                  [storage] + [operation]
                     /              \
                    /                \
            [interface] + [programming algorithm]

```

## some notes about labs

- each lab assigned on monday, due on friday
- each lab corresponds to the implementation of an adt

- the assignment of each lab will contain
    - the apis of the adt (names, input parameter list, and output type)
    - a tester main function (which will be used to call the implemented adt via the specified api)
    - a set of input instances
    - a set of corresponding output instances
    - a grading script (how we will grade your implementation)

**in the case of the current lab, lab00, the assignment is as follows**

### Lab00-SingleNumber

```
❯ tree
.
├── EECS560_Lab00_SingleNumber.pdf  // the assignment specification
├── GradingScript.py                // grading script
├── Inputs                          // set of input instances
│   ├── input_0.txt                 // input instance 0
│   ├── input_1.txt                 // input instance 1
│   ├── input_2.txt                 // input instance 2
│   ├── input_3.txt                 // input instance 3
│   ├── input_4.txt                 // input instance 4
│   ├── input_5.txt                 // input instance 5
│   ├── input_6.txt                 // input instance 6
│   ├── input_7.txt                 // input instance 7
│   ├── input_8.txt                 // input instance 8
│   └── input_9.txt                 // input instance 9
├── MainTest.cpp                    // tester main function
├── MyNumber_Template.h             // api of the adt
├── Outputs                         // set of output instances
│   ├── output_0.txt                // output instance 0
│   ├── output_1.txt                // output instance 1
│   ├── output_2.txt                // output instance 2
│   ├── output_3.txt                // output instance 3
│   ├── output_4.txt                // output instance 4
│   ├── output_5.txt                // output instance 5
│   ├── output_6.txt                // output instance 6
│   ├── output_7.txt                // output instance 7
│   ├── output_8.txt                // output instance 8
│   └── output_9.txt                // output instance 9
└── README.txt                      // how to compile and run the tester main function

3 directories, 25 files
```

**additional example**

- api:
    - `myVector(int *array) # initialize the object using an integer array`
    - `int myVector::retrieve(const int &i) # returns the ith element of the integer array`
- tester main:
    - `readFile(input_file, array) #reads the integer from the input file and store then into array`
    - `myVector test_vector(array) # initialize the object according to the specified api`
    - `std::cout << test_vector.retrieve(5) << std::endl; # output a number according to the specified api`
- input instance:
    - `5, 3, 2, 4, 76, 12, 34, 9`
- output instance:
    - `12`
- grading script:
    - `if (answer == 12) return 10; else return 0;`
- submission
    - the myVector.h file
    - the myVector.cc file
    - running time vs. input size plots if required

**resubmission courtesy**
- Resubmission courtesy: If you didn’t do well in the lab or were late without a good reason, you can resubmit within 3 days after the release of the grading. You only have one chance.

## adt abstract data type

- adt is a mathematical abstraction of a data structre, it refers to both the data and methods
- example
    - `vector`is an ADT
    - its object primarily contains an array
    - its method may include `retrieve(i)`, which returns the value of its ith element, and `size()`, which returns the number of elements in the vector
- the goal of this course is to gain a deep understanding of the implementational details of many fundamental ADTs (both data and methods)
- the secondary goal is to analyze the efficiency for the methods of different adts
- we will be working on 
    - simple ADTs:  list, queue, stack, and hash table
    - tree-based adts:  search trees, heaps, disjoint sets
    - graph adts 
    - sorting algorithms

## fundamentals 

- one of the largest differences between cpp and python is in terms of memory cpp allows you do interact with stack and heap python will handle your memory automatically ## c++ features
- this module will review over the fundamentals for learning data structure
    - c++ features and general guidelines for implementing data structures
    - basic concepts in time complexity analysis

## pointer

- a pointer is a variable that stores the memory address where another object resides
- assume we have an object named IntCall, we can use $\ast$ to indicate that the variable is an object

```cpp
int main() {
    IntCell *m;     // m is a pointer that points an address that store the IntCell type
    m = new IntCell { 0 };
    m -> write( 5 );
    std::cout << "cell contents: " << m-> read( ) << std::endl;
    delete m;
    return(0);
}
```

```cpp
int main() {
    
    // "the variable stored at memory x is an integer"
    int *x;

    /*
     * int is a data type called integer
     * * is the dereference operator
     * x is the name of the pointer
     */

     // int*        "the address of an integer types"
     // int         "an integer"
     // int* x;     "x is an address of an integer types"
     // int *x;     "the variable stored at address x is an integer

     // functionally equivalent, syntactically different

```

## reference
**lvalues, rvalues, and references**

- in addition to pointer types, c++ defines reference types.  
- an lvalue is an expression that identifies a non-temporary object
- an rvalue is an expression that identifies a temporary object or is a value not associated with an object
- intuitively, if the function call computes an expression whose value does not exist prior to the call and 
- does not exist once the call is finished unless it is compied to a variable, then it is an rvalue

**for example**

```cpp
vector<string> arr(3);
const int x = 2;
int y;
...
int z = x + y;
std::string str = "foo";
std::vector<string> *ptr = &arr;
```

- `arr` is an lvalue, `x` is an lvalue, `y` is an lvalue, `z` is an lvalue, `str` is an lvalue, `ptr` is an lvalue
- `3` is an rvalue, `2` is an rvalue, `"foo"` is an rvalue, `&arr` is an rvalue

- notice the consequence that there are some cases in which the result of a function call or operation call can be an lvalue 
- `*ptr`, `arr[x]`, and `cin >> x >> x` and others where it can be an rvalue, hence the language syntax allows a function call
- or operator overload to specify this in the return type

**lvalue reference**

## parameter passing

- pass by value is the default method for passing parameters to a function
- pass by reference formal parameter is declared as a reference type

1.  parameters and arguments
    - the **formal parameters** for a function are listed in the function declaration and are used in the body of the function definition.  A formal parameter (of any sort) is a kind of blank or place holder that is filled with something when the function is called.
    
    - an **argument** is something that is used to fill in a formal parameter.  When you write down a function call, the arguments are listed in parenthese after the function name.  When the function call is executed, the arguments are "plugged in" for the formal parameters

    - the terms **call-by-value** and **call-by-reference** refer to the mechanism that is used in the "plugged in" process.  In the **call-by-value** method, only the value of the argument is used.  In this call-by-value mechanism, the formal parameter is a local variable that is initialized to the value of the corresponding argument.  In the **call-by-reference** mechanism the argument is a variable and the entire variable is used. In the call-by-reference mechanism, the argument variable is substituted for the formal parameter so that any change that is made to the formal parameter is actually made to the argument variable.

**call by reference**

To make a formal parameter a call-by-reference parameter, append the ampersand sign & to its type name. The corresponding argument in a call to the function should then be a variable, not a constant or other expression. When the function is called, the corresponding variable argument (not its value) will be substituted for the formal parameter. Any change made to the formal parameter in the function body will be made to the argument variable when the function is called. The exact details of the substitution mechanisms are given in the text of this chapter.

EXAMPLE (OF CALL-BY-REFERENCE PARAMETERS IN A FUNCTION DECLARATION):
`void getData(int& firstIn, double& secondIn);`

```cpp
#include <iostream>

// reads two ints from keyboard
void getNumbers(int& input1, int& input2);

// interchange the values of variable1 and variable2
void swapValues(int& variable1, int&variable2);

// shows the values of variable1 and variable2 in that order
void showResults(int output1, int output2);

int main() {

    int firstnum = 0;
    int secondnum = 0;

    getNumbers(firstnum, secondnum);
    swapValues(firstnum, secondnum);
    showResults(firstnum, secondnum);

    return(0);
}

void getNumbers(int& input1, int& input2) {

    std::cout << "enter 2 integers: ";
    std::cin >> input1 >> input2;
    return;

}

void swapValues(int& variable1, int& variable2) {

    int temp = variable1;
    variable1 = variable2;
    variable2 = temp;
    return;

}

void showResults(int output1, int output2) {
    std::cout << "in reverse order the numbers are: " << output1 << " " << output2 << std::endl;
    return;
}
```
- the values of the variables `firstnum` and `secondnum` are set by this function call.
- after that, the follwing function call reverses the values in the two variables

**call by reference in detail**

The function is told to use the memory location of the variable firstNum in place of the formal parameter input1 and the memory location of the secondNum in place of the formal parameter input2. The effect is the same as if the function definition were rewritten to the following (which is not legal C++ code, but does have a clear meaning to us):

```cpp
void getNumbers( int& <the variable at memory location 0x16d00f204>, int& <the variable at memory location 0x16d00f200>) {
    
    std::cout << "Enter two integers: ";
    std::cin >> <the variable at memory location 1010> 
    std::cin >> <the variable at memory location 1012>;
    return;
}

// similar to that of the correct code

void getNumbers(int& input1, int& input2) {

    std::cout << "enter 2 integers: ";
    std::cin >> input1;
    std::cin >> input2;
    return;
}

```
![call-by-ref](https://user-images.githubusercontent.com/65584733/214719370-2adf6945-8d3b-46bb-ad5f-415799de413b.png)

**mixed parameter lists**

`void goodstuff(int& par1, int par2, double& par3);`

- the type specification for the first parameter is a reference type, the second is a value type, and the third is a reference type
- it is perfectly legal to have a function with a mixed list of parameters, some of which are passed by value and some by reference

**passing by reference to const**

- the reference type can be a reference to a const object
- the reference parameter can be used to access the value of the argument, but not to change it

**call-by-rvalue-reference**

- the central concept is that 

**when to use call by reference**

1.  call-by-value is appropriate for small objects that should not be altered by the function
2.  call-by-constant-reference is appropriate for large objects that should not be altered by the function and are expensive to copy
3.  call-by-reference is appropriate for all objects that may be altered by the function

## object

- `Class object{}` is a default constructor
    - every data structure (abstract data type) will be implemented as an object
    - objects are declared like primitive values

- `ClassName::member`
    - in the implementation file which typically ends in `.cpp`, `.cc` or `.c` each member function must identify the class that it's apart of, otherwise it would be assumed that the function is in global scope and zillions of errors would occur.

## the big five

1.  [destructor](#1-destructor)
2.  [copy constructor](#2-copy-constructor)
3.  [move constructor](#3-move-constructor)
4.  [copy assignment `operator=`](#4-copy-assignment-operator)
5.  [move assignment `operator=`](#5-move-assignment-operator)

### 1. destructor

`~IntCell() { stored_value = nullptr; delete stored_value; }`
the destructor is a special member function that is called when an object is destroyed.  The destructor is called automatically when the object goes out of scope or is explicitly destroyed by a call to the `delete` operator.  typically, the only responsibility of the destructor is to free up any resources that were acquired during the use of the object.  this includes calling `delete` for any corresponding `news`, closing any files that were open, and so on.  the default simply applies the destructor on each data member.

### 2.  copy constructor

`IntCell B = C;`
when an object is assigned to another object using the assignment operator (=), the compiler will automatically use an implicit copy constructor behind the scenes in order to create a new object that is a copy of the original object. This copy constructor is known as the **implicit copy constructor**. If the object being assigned is a reference to another object, the implicit copy constructor will still be used to create a copy of the object being referenced. This copy will be a shallow copy, which means that any pointers or references in the original object will also be copied, rather than the objects they point to. This can lead to issues with memory management if the copied object is modified and the original object is still being used.

`IntCell B = &C;`
if the object being assigned is a pointer to another object, the implicit copy constructor will not be used. Instead, the compiler will simply copy the pointer to the new object. This means that the new object will point to the same object as the original object, and any changes made to the new object will also be made to the original object.

```cpp
IntCell(const IntCell& rhs) {
    stored_value = nullptr;
    stored_value = new int{};
    *stored_value = *rhs.stored_value;
}
```

### 3.  move constructor

a move constructor is a special type of constructor that is used to move the resources of one object to another.  the move constructor is defined as `IntCell(IntCell&& rhs)`.  the `&&` syntax is used to indicate that this is a move constructor and the `rhs` parameter is the object whose resources will be moved to the object being constructed.  the move constructor initializes the `stored_value` member of the new object with the value of `stored_value` member of the object being moved `rhs`.  this is done with the statement `stored_value{rhs.stored_value}` and is analagous to `stored_value = rhs.stored_value`

```cpp
IntCell(IntCell&& rhs) : stored_value{rhs.stored_value} {
    rhs.stored_value = nullptr;
}
```
### 4. copy assignment `operator=`

`IntCell& operator= (const IntCell& rhs)`
the assignment operator is called when `=` is applied to two objects that have both been previously constructed.  `lhs = rhs` is intended to copy the state of `rhs` into `lhs`.  if `rhs` is an lvalue, this is done by using the copy assignment operator; if `rhs` is an rvalue (i.e. a temporary that is about to be destroyed anyway), this is done by using the move assignment operator.  by default, the copy assignment operator is implemented by applying the copy assignment operator to each data member in turn.

the return type of `operator=` is a reference to the invoking object, so as to allow chained assignments `a = b = c`.  although it would seem that the return type should be a constant reference, so as to disallow nonsense such as `(a = b) = c`, that expression however is in fact allowed in c++ even for integer types.  therefore the reference return type (rather than constant reference return type) is customarily used byt is not strictly required by the language specification.  the return type is also not a pointer, because the assignment operator is not intended to return a pointer to the object being assigned.

```cpp
IntCell& operator= (const IntCell& rhs) {
    if (this != &rhs) {
        *stored_value = *rhs.stored_value;
    }
    return *this;
}
```

## <p align="center"> or </p>


```cpp
IntCell& operator= (const IntCell& rhs) {
    IntCell copy = rhs;
    std::swap(*this, copy);
    return *this;
}
```

### 5. move assignment `operator=`

UNFINISHED READ CHAPTER 1 PAGE 35

## template

## function parameter and function object

## complexity analysis

## summary

## lldb debugger

## notes

**when defaults do not work**

the most common situation in which the default do not work occurs when a data member is a pointer type and the pointer is allocated by some object member function (such as a constructor).  say for instance we implement the `IntCell` by dynamically allocating an `int`.  

```cpp
class IntCell {
    public 
        explicit IntCell(int initial_value = 0) { stored_value = new int{initial_value}; }
        int read() const { return *stored_value; }
        void write(int x) { *stored_value = x; }

    private:
        int *stored_value;
};
```

**problems**

1.  the default copy assignment operator and copy constructor copy the pointer `stored_value`.  thus `a.stored_value`, `b.stored_value`, and `c.stored_value` all point to the same `int` value.  these copies are therefore shallow; the pointers rather than the pointees are copied.  

2.  there will be a memory leak if the copy constructor is used to create a new object.  the new object will have its own `stored_value` pointer, but the original object will still have its own `stored_value` pointer.  the original object will therefore have a pointer to a `int` that is no longer accessible.  this is a memory leak.


```
❯ make
g++ -std=c++11 -g -Wall -c main.cpp
main.cpp:22:7: error: object of type 'IntCell' cannot be assigned because its copy assignment operator is implicitly deleted
    c = b;
      ^
./IntCell.h:33:9: note: copy assignment operator is implicitly deleted because 'IntCell' has a user-declared move constructor
        IntCell(IntCell&& rhs) : stored_value{rhs.stored_value} {
        ^
1 error generated.
make: *** [main.o] Error 1
```

