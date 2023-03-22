# hash table

**content**

-  [notes](#notes)
-  [intro](#intro)
-  [hash function](#hash-function)

## notes

### intro

hash tables are adts that support fast $O(1)$ time search of an item and retrieves its related information.  for example we have registered all your favorite video games, we will be using a data structure to address the following need given the name of the student.



the general idea hash table data structure is merely an array of some fixed size containing the items.  in general a search is performed on some part as its data member of the item.  this is called the key.  for instance an item could consist of a string that services as the key and additional data members.

1.  **key**  in the context of a hash table the item we use to perform rhe search called **key**.  we asume all keys are _unique_.
2.  **value**  the information we are searching for is called **key**.  duplicated values are allowed.
3.  **key-value pair** each has table record is in fact a **key-value pair**
4.  **fix-sized array**  the records are stored in a **fix-sized array**.  that is, the number of key-value pairs we can store in  each has table is fixed.
5.  **load factor**  it is often of interest t measure how full the hash table is.  if a size M has table contains N elements, where N ≤ M, we say that the load factor of the hash table is N/M.

### hash function

-  instead of directly searching for the key, the has table adt introduces a function, called **hash function** to map each key to the position of its corresponding record in the hash table
-  computing the hash function should only take $O(1)$ time, given a fix-sized key size.  in this case the entire retrieval process will take $O(1)$ time.

