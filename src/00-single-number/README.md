# lab 00 single number readme notes
### data structures and algorithms

**submission**

Turn in `MyNumber_[3073682].h`
deadline is Friday January 27th, 2023

**contents**

1.  [starter code contents](#starter-code-contents)
2.  [readme](#readme)
3.  [objective](#objective)
4.  [specification of data structure](#specification-of-data-structure)
5.  [physical requirements](#physical-requirements)
6.  [physical requirements](#physical-requirements)
7.  [testing and grading](#testing-and-grading)
8.  [submission](#submission)
9.  [`MainTest.cpp`](#maintestcpp)
10. [`MyNumber_Template.h`](#mynumber_templateh)

## starter code contents

**`Lab00_SingleNumber-1.zip`**

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

## readme

**`README.txt`**

1.  compile MainTest to test data files

`g++ -std=c++11 MainTest.cpp -o Lab1`

2.  running the testing program

`./Lab1 Inputs/input_#.txt >results.txt`

3.  comparing your results with expected output

`python3 GradingScript.py result.txt Outputs/output_#.txt`

if you see `yes`, the your program is correct
if you see `no`, then your program is incorrect

## objective

- get familiar with coding with c++
- recap c++ fundamentals such as object, constructor, destructor, template, and overloading
- get familiar with adt implementation with c++ and the lab setup for this course

## specification of data structure

- define your data structure as `template <typename DataType> class MyNumber`

- constructor functions
   
    `// rhs is the right hand side of the assignment operator`
    - `explicit MyNumber(DataType rhs = 0) // default constructor` 
    - `MyNumber(const MyNumber<DataType> & rhs) // copy constructor`
    - `MyNumber(MyNumber<DataType&& rhs) // move constructor`

- destructor functions

    - `~MyNumber(void) // collects allocated memory before the destruction of the object`

- data access

    - `DataType read(void) const // returns the number being stored`

- data update

    - `void write(DataType rhs) // record the parameter`
    - `MyNumber & operator= (const MyNumber<DataType> &rhs // copy assignment`
    - `MyNumber & operator= (MyNumber<DataType> &&rhs) // move assignment`

## physical requirements

1.  install [valgrind](https://valgrind.org) to ubuntu linux system `sudo apt install valgrind`

2.  you should use `new` to allocate memory space to the variable that stores the data (a number with DataType)

3.  you should use `delete` to collect the allocated memory space upon the destruction of the object instance.

## testing and grading

- we will test your implementation using the tester main function posted online
- the posted input and output example should be used for a testing purpose, while we will use another set of inputs for grading
- **your code will be compiled under Ubunti 20.04 LTS using g++ version 9.3.0 (default) with C++11 standard**
- **your final score will be determined by the success percentage of your program when fed with many random inputs**
- <p style="color:red">**if your program does not compile, you will get 0 points**</p>

## submission

submit your implementation as a single `.h` file named `MyNumber_m358b583.h`

## `MainTest.cpp`

```cpp
#include <iostream>
#include <fstream>
#include <string>
#include <iosmanip>

#include "MyNumber.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "please provide the test input" << std::endl;
        return(0);
    } else {

        ifstream f_input;
        f_input.open(argv[1]);
        // if f_input.is_open() is false, so if it fails to open then this conditional will be executed 

        if (0 == f_input.is_open()) {

            std::cout << "error for opening the test input" << std::endl;

            return (0);

        } else {

            std::string line;
            
            // getline will return a boolean value
            // getline() functions return the number of characters written, excluding the terminating NULL character
            // the value -1 is returned if an error occurs, of if end-of-file is reaches
            // thus while the file still has lines lets read the file and store it into variables, num, a, b, and c
            while(getline(f_input, line)) {
                
                // the stof() function converts a string (in this case, the variable "line" with a data type of float
                // float is a decimal number with single precision
                // the value num is the set to the result of the `stof()` function
                // the stof() function converts a string in this case "line" which is of type string to a float
                float num = stof(line)

                // `a` is an instance of the class MyNumber aka a new object
                // `a` is of type MyNumber and the data type is float
                // the template parameter is the data type of the object type
                // the <float> indicates that the MyNumber class is a template class and it is instantiated with type float
                // the curly braces {} after the object name `a` is used to initialize the object with the value of the variable `num`
                // tldr; the object `a` an object of class MyNumber and assigns the value of the variable "num" to it
                MyNumber<float> a {num};
                MyNumber<float> b = a;
                MyNumber <float> c;

                // you will need to write the this function
                /*
                 * void write(DataType rhs) {} // record the parameter
                 */

                c.write(a.read() / 2);

                std::cout.setf(ios::fixed);

                std::cout << setprecision(3) << a.read() << "\t" << b.read() << "\t" << c.read() << std::endl;
             }

```

## `MyNumber_Template.h`

```cpp
#ifndef __MYNUMBER_H__
#define __MYNUMBER_H__
#include <algorithm>
#include <iostream>

// using namespace essentially means that you not need to type std:: before every function
using namespace std;

template <typename DataType>

class MyNumber {
    public:
        explicit MyNumber(DataType rhs = 0) 
```

```cpp
#include "MyNumber.h"
#include <iostream>
#include <string>

/*
    default constructor:
    
    `(DataType rhs = 0)`
    this function is called when an object is created without any parameters, 
    however having one parameter is not a problem, any parameter of any type 
    will work and hold a default value of 0 if no value is passed in
    
    `explicit` 
    is a keyword is used before the constructor function, it indicates that the 
    constructor should not be used for implicit type conversions and copy-initialization.
*/

MyNumber::Mynumber(DataType rhs = 0) {

}
```

- In C++, constructors can be defined with an initialization list, which is a list of initializations for the data members of the class that is used to set their initial values. The initializer list is placed after the constructor's parameter list, separated by a colon (:) from the constructor's body.

- It's important to note that the initialization list is executed before the constructor's body, so any code that you put inside the constructor's body will be executed after the member variables have been initialized.

