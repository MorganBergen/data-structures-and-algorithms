# index and postfix calculation using stacks

**contents**

1.  [objective](#objective)
2.  [specifications](#specifications)
3.  [testing](#testing)
4.  [program flow](#program-flow)
5.  [`maintest.cpp`](#maintest-cpp)

## objective

understand the infix and postfix calculation using stack.

## specifications

1.  only addition `+`, subtraction `-`, multiplication `*`, and division `/` are assumed to be valid operators from the infix input

2.  only parenthesis `((` and `))` are assumed from the infix input

3.  both integers and floating point numbers are assumed to be valid inputs

4.  both positive and negative numbers are assumed to be valid inputs

5.  the input infix string is balanced and valid, fully complied with customary mathematical notation

6.  implement a class name `MyInfixCalaculator` the class is expected to use the `MyStack` and `MyVector` classes you have implemented previously.

7.  implement `void tokenize(const std::string>& infix_tokens, MyVector<std::string>& postfix_tokems)` to decompose the infix string into a set of tokens

8.  implement `void infixToPostfix(MyVector<std::string>& infix_tokens) const, MyVector<std::string>& postfix_tokens)` to convert a set of infix tokens to a set of postfix tokens 

9.  implement `doubel calPostFix(const MyVector<std::string>& postfix_tokens) const` to calculate the result

10. implement a wrapper function `double calculate(const std::string& s)` to directly compute the result from a given infix input.

##  testing

you will be tested over the following compiler under **Ubuntu 20.04 LTS using `g++` version 9.3.0   (default) with C++11 standard**

## program flow

the following shows the directory tree

```
❯ tree
.
├── MainTest.cpp            # 1st entry #include MyInfixCalc.h, driving execution of prog
│                           # 
│  
│  
├── MyInfixCalculator.h     #    
├── MyStack.h
├── MyVector.h
├── README.txt
├── Inputs                  # test case directory
│   ├── input_0.txt
│   ├── ...
│   └── input_9.txt
├── Outputs
│   ├── output_0.txt
│   ├── ...
│   └── output_9.txt
└── GradingScript.py        # grading script testing the corrected based on input output diff

3 directories, 27 files
```

###  `MainTest.cpp`

```cpp
#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>

#include "MyInfixCalculator.h"

int main(int argc, char* argv[]) {
    
    if (argc != 2) {
        std::cerr << "please provide test instance";
        return(0);
    }

    std::ifstream infile;
    infile.open(argv[1]);
    
    if (infile.is_open()) {
        std::string str;
        std::getline(inFile, str);
        MyInfixCalculator infix_calculator(str);
        double a = infix_calculator.calculate(str);
        std::cout.percision(3);
        std::cout << std::fixed << a << std::endl;
    } else {
        std::cout << "the instance.txt file cannot be opened";
    }

    infile.close();
}
```
-  `#include <iostream>`    include the iostream header for input/output operations
-  `#include <iomanip>`     include the iomanipulation deahder for manipulating the format of i/o stream
-  `#include <vector>`      include the vector header for the standard vector container
-  `#include <fstream>`     include the fstream header for file i/o operations
-  `#include <string>`      include the string header for the standard string class

-  `#include "MyInfixCalculator.h`

include the custom `MyInfixCalculator` header file

-  `int main(int argc, char* argv[])`

contains the command line arguments, which first `argc` is the argument count, the `argv[]` is the argument variable.

-  `if (argc != 2) { ... return(0) };`

check if the correct number of command line arguments are provided, otherwise print an error message and return.  the argument will be the test input file, the explain input file will be the following

```txt
(219.528--350.755/((218.266-26.514)--465.256)-312.548+93.975+258.314+-91.66)
```

-  `std::ifstream inFile;`  declare a fstream object called infile which will be the means of getting the contents of the file.

-  `inFile.open(argv[1]);`  open th efile provided as a command-line argument allowing for us to grab it's contents.

-  `std::string str;` `std::getline(infile, str);`

will contain the screen read in from the input file, therefore `str` == (219.528--350.755/((218.266-26.514)--465.256)-312.548+93.975+258.314+-91.66) and will be of type string.

-  `MyInfixCalculator infix_calculator;` 

create an instance of the `MyInfixCalculator` called `infix_calculator` this object will be the driver.




```cpp
#define __MYINFIXCALCULATOR_H__
#include <algorithm>
#include <string>
#include "MyStack.h"
#include "MyVector.h"

class MyInfixCalculator {
    public:
        MyInfixCalculator() { }
        ~MyInfixCalculator() { }
        double calculate(const std::string& s) { }
    private:
        int operatorPrec(const char c) const {
            switch(c) {
                case '*':
                    return(2);
                case '/':
                    return(2);
                case '+':
                    return(3);
                case '-':
                    return(3);
                default:
                    return(-1);
            }
        }

        bool isValidParenthesis(const char c) const {
            switch(c) {
                case '(':
                    return(true);
                case ')':
                    return(true);
                default:
                    return(false);
            }
        }

        bool isDigit(const char c) const {
            if (c >= '0' && c <= '9') {
                return(true);
            } 
            return (false);
        }

        double computeBinaryOperation(const std::string& orand1, const std::string& ornd2, const std::string& opt) const {
            double o1 = std::stod(ornd1);

```














