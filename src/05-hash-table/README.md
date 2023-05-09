#  hash table with separate chaining

### contents

-  [objective](#objective)
-  [specifications](#specifications)
-  [hints](#hints)
-  [testing](#testing)

##  objective

-  get familiar with the implementation of hash table with separate chaining in c++
-  dynamic hash table size adjustments and rehashing operations
-  universal hash function calculations and modulo speed up with mersenne prime

##  specifications

-  the hash table should implement the separate chaining approach to handle collisions

1.  what is separate chaining
2.  what is a collision

-  the hash table should be implemented using the `MyVector` class, and the secondary chain for each bucket should be implemented using the `MyLinkedList` class.
-  the hash table should accept either `std::string` or `long long` as the key data type, and it should support any value data type
-  the hash table should be able to dynamically adjust its table size using table doubling and halving
-  the hash table should support data retrieval, insertion, and deletion in constant time on average

##  hints

-  you can make use of the `HashFunc` and `HashObj` classes that have already been implemented
-  you should use sieve of eratosthenes to precompute prime numbers
-  recall the difference between `MyVector::size()` and `MyVector::capacity()`, make the proper use of them 

##  testing

test the implementation using the tester main function.  the posted input and output examples should be used for a testing purpose, while anotehr set of input will be used to evaluation.  code will be compiled under ubuntu 20.04 lts using `g++` version 9.3.0 with c++11 standard.

##  directory

```
❯ tree
.
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
├── MyHashTable_Template.h
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

3 directories, 24 files
```

##  `MainTest.cpp`

```cpp
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "MyVector.h"
#include "MyHashTable.h"

using namespace std;

int main(int argc, char* argv[]) {
    
    //hash_table.preCalPrimes(100);
    //cout << hash_table.nextPrime(83) << endl;
    if (argc != 2) {
        std::cout << "Please provide the input file.\n";
        return 1;
    }
    
    ifstream inFile;
    inFile.open(argv[1]);
    MyHashTable<string, int> hash_table;
    MyVector<string> keys;
    if (inFile.is_open()) {
        string str;
        while(std::getline(inFile, str)) {
            size_t tp = str.find("\t");
            string k = str.substr(0, tp);
            int v = stoi(str.substr(tp + 1));

            HashedObj<string, int> data(k, v);
        
            bool istag = hash_table.insert(data);
            if(istag) {
                cout << "Data inserted: " << k << "\t" << v << endl;
                cout << "Table info: " << hash_table.size() << "\t" << hash_table.capacity() << endl;
            }
            else {
                cout << "Insertion failed: " << k << "\t" << v << endl;
            }
            keys.push_back(k);
        }

        for(auto itr = keys.begin(); itr != keys.end(); ++ itr) {
            int dtag = ((int) rand()) % 10;
            if(dtag) {
                bool dstag = hash_table.remove(*itr);
                if(dstag) {
                    cout << "Data deleted: " << *itr << endl;
                    cout << "Table info: " << hash_table.size() << "\t" << hash_table.capacity() << endl;
                }
                else {
                    cout << "Deletion failed: " << *itr << endl;
                }
            }
            
            HashedObj<string, int> data;
            bool rstag = hash_table.retrieve(*itr, data);
            if(rstag) {
                cout << "Data retrieved: " << data.key << "\t" << data.value << endl;
                cout << "Table info: " << hash_table.size() << "\t" << hash_table.capacity() << endl;
            }
            else {
                cout << "Retrieval failed: " << *itr << endl;
            }
            
        }
    }
    else {
        cout << "The instance.txt file cannot be opened.\n";
        return 1;
    }
    inFile.close();

    return 0;
}


```




