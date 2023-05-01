#  lab 07 binary heap

###  contents

1.  [objective](#objective)
2.  [specification](#specification)
3.  [testing](#testing)
4.  [deliverables](deliverables)

##  [intro](#intro)

## objective

get familiar with basic binary heap implementation with c++

## specification

1.  implement a binary heap class `MyBinaryHeap<ComparableType>` we assume larger numbers have higher priorities.  the class should be implemented with `MyVector`

2.  implement `bool verifyHeapProperty(void)` to determine whether the heap satisfies heap property.  return `true` if yes and `false` if no.

3.  implement `void increaseKey(const size_t p, const unsigned int d)` to increase the priority of the `p`th element as in the array by `d` and restructure the heap to ensure heap property.  if the priority is lower than `d`, set the priority to `0`

4.  implement `void decreaseKey(const size_t p, const unsigned int d)` to decrease the priority of the `p`th element as in the array by `d`, and restructure the heap eo ensure heap property.  if the priority is lower than `d`, set the priority to `0`.

5.  implement `MyBinaryHeap& merge(MyBinaryHeap<ComparableType> &&rhs)` to merge `rhs` with the current heap.  the merged heap should satisfy heap property.  your implementation should run in linear time w.r.t. total size of the two heaps being merged.

## testing

we will test your implementation using the tester main function.  if your code doesnt compile you will recieve a 0.

##  deliverables

1.  `MyVector_m358b583.h`
2.  `MyBinaryHeap_m358b583.h`

##  intro

**tree**

```
.
├── EECS330_Lab07_BinaryHeap.pdf
├── GradingScript.py
├── Inputs
│   ├── input_0.txt
│   ├── input_1.txt
│   ├── input_2.txt
│   ├── input_3.txt
│   ├── input_4.txt
│   ├── input_5.txt
│   ├── input_6.txt
│   ├── input_7.txt
│   ├── input_8.txt
│   └── input_9.txt
├── MainTest.cpp
├── MyBinaryHeap.h
├── MyVector_m358b583.h
├── Outputs
│   ├── output_0.txt
│   ├── output_1.txt
│   ├── output_2.txt
│   ├── output_3.txt
│   ├── output_4.txt
│   ├── output_5.txt
│   ├── output_6.txt
│   ├── output_7.txt
│   ├── output_8.txt
│   └── output_9.txt
└── README.txt

3 directories, 26 files
```


```
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "binaryheap.h"

int main(int argc, char* argv[]) {

    if (argc !=) {
        std::cout << "please provide input file."
    }

}

```
