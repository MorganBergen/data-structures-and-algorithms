#  hashing 

###  contents

-  [intro](#intro)
-  [general idea](#general-idea)
-  [hash function](#hash-function)
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

the ideal hash table data sturecture is merely an array of some fixed size containing the items.  a search is performed on some part of the item called a key.  for instance an item could consist of a string that serves as the key and additional data members (for instance, a name that is part of a large emplyee structure.  we will refer to the table size as tableSize, with the understanding that this is part of a hash data structure and not merely some variable floating around globally.  the common convention is to have the table run from `0` to `tableSize - 1`.

each key is mapped into some number in the range `0` to `tableSize - 1` and placed in the appropriate cell.  the mapping is called a **hash function**, which ideally should be simple to compute and should ensure that any two distinct keys get different cells.  since there are a finite number of cells and a virtually inexhaustible supply of key, this is clearly impossible and thus we seek a hash function that distributes the keys evenly among the cells.  

the following figure is typical of a perfect situation.  in this example `john` hashes to `3`, `phil` hashes to `4`, `dave` hashes to `6`, and `mary` hashes to `7`.  the only remaining problems deal with choosing a function, and deciding what to do when two keys hash to the same value (this is known as **collision**) and deciding on the table size.

##  hash function

if the input keys are integers, then simply returning `key mod tableSize` is generally a reasonable strategy, unless `key` happens to have some undesirable properties.
