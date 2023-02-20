#  vectors

**content**

1.  [objective](#objective)
3.  [requirements](#requirements)
4.  [evaluation](#evaluation)
5.  [final submission](#final-submission)
6.  [about vectors](#about-vectors)
6.  [specification of the adt](#specification-of-the-adt)
7.  [vector implementation](#vector-implementation)
8.  [`private` member variables](###private-member-variables)

-  [1.  `size_t the size`](####1-size_t-the-size)

-  [2.  `size_t the capacity`](####2.-`size-t-the-capacity`)

-  [3.  `DataType * data`](####3.-`DataType-*-data`)

9.  [`public` member variables](###public-member-variables)

-  [1.  `static const size_t SPARE_CAPACITY = 16`](####1.-`static-const-size_t-SPARE_CAPACITY-=-16`)

10. [`private` member functions](###private-member-functions)

-  [1.  `explicit myvector(size_t init_capacity = 0)`](####1.-explicit-myvector(size_t-init_capacity-=-0))

-  [2.  `myvector (const myvector & rhs)`](####2.-myvector-(const-myvector-&-rhs))

##  objective

vector implementation with c++, refer to Data Structures and Algorithm Analysis in C++ by Mark Weiss, 4th Edition

## requirements

1.  rename the object into `myvector`, instead of `vector` as indicated in the textbok
2.  your object should contain a copy constructor that supports initialization from an stl vector object.  the constructor should have an interface of  `myvector(const std::vector<object>& rhs)`

3.  implement an "append" method, which appends all data elements in the parameter (as rvalue) to the current object.  the return value should be the current object.  the function has an interface of `Myvector<object>& append(myvector<object> && rhs)`

## evaluation

we will test your implementation using the tester main function posted online.  the posted input and output examples should be used for a testing purpose, while we will ue another set of inputs for grading.  your code will be complied under ubuntu 20.04 lts using g++ version 9.3.0 (default) with c++11 standard.  your final score will be the determined by the success percentage of your program when fed with many random inputs.  note that if your code does not compile (together with our tester main function), you will recieve a 0.  

## final submission

submit your implementation as a single `.h` file, with file name `MyVector_m358b583.h` submission that do not comply with the naming specification will not be graded.  the deadline is sunday feb 19 2023 11:59 pm

verification process

```
g++ -std=c++11 MainTest.cpp -o Lab1

./Lab1 input.txt >result.txt

python3 GradingScript.py result.txt output.txt
```

script for all test cases

```
g++ -std=c++1 MainTest.cpp -o Lab2

./Lab2 Inputs/input_0.txt >result.txt
python3 GradeScript.py result.txt Outputs/output_0.txt

./Lab2 Inputs/input_1.txt >result.txt
python3 GradeScript.py result.txt Outputs/output_1.txt

./Lab2 Inputs/input_2.txt >result.txt
python3 GradeScript.py result.txt Outputs/output_2.txt

./Lab2 Inputs/input_3.txt >result.txt
python3 GradeScript.py result.txt Outputs/output_3.txt

./Lab2 Inputs/input_4.txt >result.txt
python3 GradeScript.py result.txt Outputs/output_4.txt

./Lab2 Inputs/input_5.txt >result.txt
python3 GradeScript.py result.txt Outputs/output_5.txt

./Lab2 Inputs/input_6.txt >result.txt
python3 GradeScript.py result.txt Outputs/output_6.txt  

./Lab2 Inputs/input_7.txt >result.txt
python3 GradeScript.py result.txt Outputs/output_7.txt  

./Lab2 Inputs/input_8.txt >result.txt
python3 GradeScript.py result.txt Outputs/output_8.txt

./Lab2 Inputs/input_9.txt >result.txt
python3 GradeScript.py result.txt Outputs/output_9.txt
```

##  about vectors

a programmer-defined vector is a custom implementation of the vector data structure in c++. the standard library of c++ already provides a vector class, but a programmer can create their own implementation with custom functionalities and properties specific to their use case. this can be done by defining a class that contains an array and implementing methods to manipulate it, similar to the implementation of the standard vector class.

the advantage advantage of using a `vector` is that it's indexable in constant time.  indexable in constant time for a vector means thet being able to access an element in the vector by its index or position take $O(1)$ time, the `operator[]` method specifically named `const data_type & operator[] (size_t index)`, so in c++ the `operator[]` methods is used to access the element in a vector by it's index position, for example `myvector[3]` would access the element at index 3 in the `myvector` vector.

the disadvantage is that insertion of new items and removal of existing items is expensive, unless the changes are made at the end of the vector.  we will go over adding and removing elements and it's time complexity later on.

the `vector` class template is instantiated with the type of items that it stores.  this means that when a vector class template is instantiated with the type of items that it stores, it means that a specific version of the vector class is created for that specific type.  the code for the vector class template is written in a generic way so that it can work with any data type, but it is not actually compiled until a specific data type is provided.  for example if we want to create a vector of integers, we would instantiate the vector class template with teh `int` data type:  `myvector<int> red{}`, and a specific version of the vector class would be generated for `int`.  this specific version of the vector class would contain code that is optimized for the `int` data type, and it would only allow `int` values to be stored in the vector.

remember that instantiated refers to the process of creating a specific instance of a class, when a class is instantiated, memory is allocated for an object of that class and its constructor is called to initialize its data members.  this object is then used to perform operations defined in the class.

1.  the first three methods are available for all stl containers.

-  `int size() const`:  returns the number of elements in the container

-  `void clear()`:  removes all elements from the container

-  `bool empty() const`:  returns true if the container contains no elements, and false otherwise

2.  `vector` supports adding and removing from the end of the list in constant time.  

-  `void push_back(const Object & x`:  adds `x` to the end of the vector

-  `void pop_back()`:  removes the object at the end of the vector

3.  `vector` supports accessing the front item in the list in constant time.

-  `const Object & back() const`:  returns the object at the end of the vector (a mutator that returns a reference is also provided)

-  `const Object & front() const`:  returns the object at the front of the list (a mutator that returns a reference is also provided)

4.  `vector` has two methods that allow for efficient indexing. and the other two methods allow the programmer to view and change the internal capacity

-  `Object & operator[] (int index)`:  returns the object at index `index` in the `vector`, with no bounds-checking (an accessor that returns a constant reference is also provided).

-  `Object & at(int index)`:  returns the object at index `index` in the `vector`, with bounds checking (an accessor that returns a constant reference is also provided) 

-  `int capacity() const`:  returns the internal capacity of the `vector`

-  `void reserve(int new_capacity)`:  sets the new capacity.  fi a good estimate is available, it can be used to avoid expansion of the `vector`

## specification of adt

- implement a vector data structure with the basic interface and methods
- implement an iterator class that supports the traverse of your vector data structure

-----------------------------------------------------------------------------------------------------

## `private` member variables

### 1.  `size_t the_size;`
### 2.  `size_t the_capacity;`
### 3.  `DataType* data;`

-----------------------------------------------------------------------------------------------------

## `public` member variables

### 1.  `static const size_t SPARE_CAPACITY = 16;`

-----------------------------------------------------------------------------------------------------

## `public` member methods

### 1.  `explicit myvector(size_t init_capacity = 0)`

**default constructor**

```cpp
explicit myvector(size_t init_size = 0) : 
    the_size{init_size}, 
    the_capacity{init_size + SPARE_CAPACITY} { 
        data = new DataType[the_capacity]; 
}
```

- the `explicit` keywork in c++ is used to prevent implicit conversions of types.  in this context, it means that the `myvector` constructor can only be called explicitly with an argument, and implicity through type conversion.   the default constructor `myvector` class initializes the size and capacity of the vector to a given `the_size = 0` if there is no size specified. meaning if we construct an object like this `myvector<int> red_vector{};` or like this `myvector<int> red_vector;`. 

- `the_size` and `the_capacity` are initialized, `the_capacty = init_size + SPARE_CAPACITY` and the data pointer will have allocated with the size of the capacity.  the constructor is defined with an initalization list which is a way of initializing member variables before the body of the constructor is executed.  in this case the initialization list sets the size and capacity member varibales to the given arguments, and allocates memory for the data pointer.

- `data = new data_type[the_capacity];`  in the context of the `myvector` class, the `data` pointer is used to dynamically allocate memory for the vector.  the `new` keywork is used to request the memory allocation from the operating system at runtime.  `data_type[the_capacity]` is used to allocate an array of `data_type` objects with a size of `the_capacity`.  the `new` operator returns a pointer to the first element of the allocated memory block, which is then assigned to `data`.  this means that `data` now pointers to a block of memory that can hold `the_capacity` number of `data_type` objects.  the constructor is responsible for initializing the objects in the allocated memory block.

-  it's important to note that the memory allocated using `new` must be manually deallocated using the `delete` operator when it is no longer needed, otherwise, it can lead to memory leaks in the program.

### 2.  `myvector (const myvector & rhs` 

**copy constructor**

-  the following is the implementation of a copy constructor for a template class myvector.  it allocates memory for the new vector and copies the data from the old vector into the new one

```
myvector (const myvector & rhs) : 
    the_size{rhs.the_size},
    the_capacity{rhs.the_capacity},
    data{nullptr} {

        data = data_type[the_capacity];

        for (int i = 0; i < the_size; ++i) {
            data[i] = rhs.data[i];
        }
    }
```

**line by line explaination**

-  overall this copy constructor creates a new `myvector` object that is a copy of the passed object rhs.  it initializes its member variables with the same values as `rhs`, allocates memory for its `data` member variable, and copies the elements of `rhs`'s `data` member variable to the new object's `data` member variables

-  `myvector (const myvector & rhs)` this is a constructor definition, which takes a reference to another `myvector` object as its parameter, this is the initial signature of the copy constructor that will create a copy of the passed object `rhs`.  remember that a reference is an alias to an existing variable.  when you define a reference, you are essentially creating another name for an existing vairable.  so any changes made to the reference will also affect the original variable it is referencing.  `rhs` stands for "right hand side", it is called this way because it is convention in c++ to use this naming convention for function parameters that are used as input or sources of data.  in this case, `rhs` is a reference to an object being passed as an argument to the copy constructor.  recall that this `&` is the address of operator, so it is a pointer to another vairbale and returns the memory address where the variable is stored in memory.

-  `: the_size{rhs.the_size},`  initializes the `the_size` member variable of the newly created object to the same value as the `the_size` member variable of the passed object `rhs`

-  `the_capacity{rhs.the_capacity},`  initializes the `the_capacity` member variable of the newly created object to the same value as that of `the_capacity` member variable of the passed object `rhs`

-  `data{nullptr} {`  this initializes `data` member variable of the newly created object to `nullptr`.  it's important to prevent undefined behavior, since the newly created object has no memory allocated to it yet.

-  `data = data_type[the_capacity];`  this allocates memory on the heap for teh `data` member variable of the newly created object.  the size of the memory block is `the_capacity` which was copied from the `rhs` object.  the `new` operator returns a pointer to the first element of the allocated block, which is assigned to the `data` member variable.  we know that `the_capacity` of the newly created object is the same as `rhs`'s `capacity` because it was assigned within the initializer list.

-  `for (int i = 0; i < the_size; ++i) {`  this is a loop that will iterate over each element in the `data` member variable of the newly created object, copying the corresponding element from the `data` member variable of the passed object `rhs` untill it reaches the end which is `the_size - 1`

-  `data[i] = rhs.data[i]`  this copies the `i`th element of the `data` member variable of the passed object `rhs` to the `i`th element of the `data` member variable of the newly created object.

**basics of copy constructors**

-  a copy constructor is a special constructor that creates a new object by initializing it with an existing object of the same class.  the copy constructor is used to create a copy of an object when a new object is created and and initialized to an existing object.

-  `classname (const classname & object)` 

-  `myvector (const myvector & rhs)`

-  `myvector` is `classname` which is the name of the class that the copy constructor is defined for

-  `rhs` is `object` which is the name of the object that is being copied, `rhs` stands for `right hand side`

-  when a copy constructor is called, a new object is created and initialized with the values of the existing object.  the copy constructor can be defined by the programmer or the compiler will generate a default copy constructor if one is not provided

-  it is important to note that the copy constructor is only used to create a copy of an object, not to create a new object with the same values as the existing object.  in order to create a new object with the same values as the existing object a constructor or method would be used.



































<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>
-----------------------------------------------------------------------------------------------------












#. `data_type & operator[] (size_t index) { return data[index]; }`

example use case:  `green_vector[3]` would access the element at index 3 in the `green_vector` vector.

operator overloading is the process of giving new meaning to existing operators in c++.  when an operator is overloaded it gains the ability to operator on user-defined data types, in addition to its original functionality.

in the case of `data_type & operator[] (size_t index)` the `[]` operator is being overloaded to allow for index-based access to elements of the `myvector` class.  so when ths operator is used on an object of the `myvector` class, it will `return` a reference to the element at the specified index in the `data` array.  the operator overloading process works by creating a function that has the same name as the operator being overloaded.

operator overload for the `[]` operator, this method should return a reference to the element at the specified index position.  in programming the term "overloading" refers to the ability to define operators with the same name but different parameters or argument types.  this allows the same operator to be used with different data type or in different situations, depending on the arguments passed in.  the name "overloading" is used because the function or operator name is effectively "loaded" with different meanings, depending on the context in which it is used.

the `&` symbol indicates that the function returns a reference to the data type.  this means that when we access an element in the vector using the `[]` operator, the function will return a reference to the actual element, NOT A COPY OF IT.  this is useful when we want to modify the element in place, as it allows us to avoid creating unneccessary copies of the data. 

```
myvector<int> green_vector = {1, 2, 3};
v[1] = 5;
```
## vector implementation

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
        explicit myvector(size_t init_size = 0) : 

            the_size{init_size}, 

            the_capacity{init_size + SPARE_CAPACITY} {

                data = new DataType[the_capacity];

            }

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
