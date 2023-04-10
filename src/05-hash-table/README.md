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
