#  hashing 

###  contents

-  [intro](#intro)
-  [general idea](#general-idea)
-  [hash function](#hash-function)
    -  [simple hash function](#simple-hash-function)
-  [separate chaining](#separate-chaining)
-  [hash tables without linked lists](#hash-tables-without-linked-lists)
-  [linear probing](#linear-probing)
-  [quadratic probing](#quadratic-probing)
-  [double hashing](#double-hashing)
-  [rehashing](#rehashing)
-  [hash tables in standard library](#hash-tables-in-standard-library)
-  [hash tables with worst-case o(1) access](#hash-tables-with-worst-case-o1-access)
-  [perfect hashing](#perfect-hashing)
-  [cuckoo hashing](#cuckoo-hashing)
-  [hopscotch hashing](#hopscotch-hashing)
-  [universal hashing](#universal-hashing)
-  [extendible hashing](#extendible-hashing)
-  [summary](#summary)

##  intro

the implementation of hash tables is frequently called hashing.  hashing is a technique used for performing insertions, deletions, and finds in constant average time.  tree operations that require any ordering information among the elements are not supported efficiently.  thus, operations such as `findMin`, `findMax`, and the printing of the entire table in sorted order in linear time are not supported.  the central data structure is the **hash table** which will examine the following

-  several methods of implementing the hash table
-  compare these methods analytically
-  show numerous applications of hashing
-  compare hash tables with binary search trees

##  general idea

**the ideal hash table data sturecture is merely an array of some fixed size containing the items.**  a search is performed on some part of the item called a key.  for instance an item could consist of a string that serves as the key and additional data members (for instance, a name that is part of a large emplyee structure).  we will refer to the table size as `tableSize`, with the understanding that this is part of a hash data structure and not merely some variable floating around globally.  the common convention is to have the table run from `0` to `tableSize - 1`.

each key is mapped into some number in the range `0` to `tableSize - 1` and placed in the appropriate cell.  the mapping is called a **hash function**, which ideally should be simple to compute and should ensure that any two distinct keys get different cells.  since there are a finite number of cells and a virtually inexhaustible supply of key, this is clearly impossible and thus we seek a hash function that distributes the keys evenly among the cells.  

the following figure is typical of a perfect situation.  in this example `john` hashes to `3`, `phil` hashes to `4`, `dave` hashes to `6`, and `mary` hashes to `7`.  the only remaining problems deal with choosing a function, and deciding what to do when two keys hash to the same value (this is known as **collision**) and deciding on the table size.

##  hash function

if the input keys are integers, then simply returning `key mod tableSize` is generally a reasonable strategy, unless `key` happens to have some undesirable properties.  in this case, the choice of hash function needs to be carefully considered.  for instance, if the table size is 10 and the keys all end in zero, then the hash function is a bad choice.  for reasons we shall see later, and to avoid situations like the one above, it is often a good ideal that the hash table size is prime.  when the input keys are random integers, then this function is not only very simple to compute but also distributes the keys evenly.  

usually the `keys` are `std::string` in this case the hash function needs to be chosen carefully.  one option is to add up the ascii values of the characters in the string.  the routine in the following figure [simple hash function](#simple-hash-function) 


###  simple hash function

```cpp
#include <iostream>
#include <string>
#include <vector>

int hash (const std::string &key, int tablesize);

int main() {

    std::vector<std::string> keys = {"JON", "MARY", "MORGAN", "DAVID", "ALEX", "ANISHA", "MONA"};    
    std::vector<int> values = {0000, 1111, 2222, 3333, 4444, 5555, 6666, 7777};
    int tablesize = 7;

    for (int i = 0; i < 7; i++) {
        int location = hash(keys[i], tablesize);
        std::cout << std::endl;
        std::cout << "(" << keys[i] << ", " << values[i] << ")";
        std::cout << " hashes to cell location: " 
                  << location << std::endl;
        std::cout << "tablesize = " << tablesize << std::endl;
    } 
    return(0);
}

int hash (const std::string &key, int tablesize) {
    int hashvalue = 0;
    for (char ch : key) {
        hashvalue += ch;
    }
    return (hashvalue % tablesize);
}
```

### outout

```bash
❯ ./main

(JON, 0) hashes to cell location: 0
tablesize = 7

(MARY, 1111) hashes to cell location: 5
tablesize = 7

(MORGAN, 2222) hashes to cell location: 4
tablesize = 7

(DAVID, 3333) hashes to cell location: 3
tablesize = 7

(ALEX, 4444) hashes to cell location: 4
tablesize = 7

(ANISHA, 5555) hashes to cell location: 2
tablesize = 7

(MONA, 6666) hashes to cell location: 5
tablesize = 7
```

collisions can occur in hash tables because the hash function might not produce a unique location (index) for each key.  in this example the hash function computes the sum of the ascii values of the character in the key and then takes the modulus with the table size of 7.  this simple hash function is more likely to produce collisions as different keys can have the same sum of ascii values.

$$\sum_{i = 0}^{\text{ table size } - 1} ch | \text{ for (ch : key) } $$

in this output you can see that `MORGAN` & `ALEX` both hash to the cell location 4 and `MARY` &
`MONA` both hash to the cell location 5.  these are examples of collisions, you can use a more sophisticed hash function that distributes the keys more evenly accross the availabel cell locations.  to handle collisions, various techniques such as chaining (using linked lists to store multiple key-value pairs at the same location) or open addressing (looking for the next available cell location).












