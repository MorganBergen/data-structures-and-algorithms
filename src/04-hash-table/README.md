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
├── MainTest.cpp            # 1st entry #include MyInfixCalc.h
├── MyInfixCalculator.h
├── MyStack.h
├── MyVector.h
├── README.txt
├── Inputs
│   ├── input_0.txt
│   ├── ...
│   └── input_9.txt
├── Outputs
│   ├── output_0.txt
│   ├── ...
│   └── output_9.txt
└── GradingScript.py

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



```

















