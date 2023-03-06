# midterm

**contents**

1.  [scope](#scope)
2.  [plan](#plan)
3.  [lists and vectors](#lists-and-vectors)
4.  []()
5.  []()


## scope

the scope of the midterm includes all materials covered by the posted slides, class notes, and textbook chapters 1 - 3 (3.1 - 3.5)

## plan

1.  programming a general overview
2.  algorithm analysis
3.  lists, stacks, and queues

-  [vectors](../01-vectors)
-  [lists](../02-linked-list)
-  [stacks](../03-stacks)

4.  [module 0 the fundamentals](../00-fundamentals)
5.  module 1 vector and list
6.  module 2 queue and stack

## lists and vectors

you are given a linkedlist `L` and another linkedlist `P`, containing integers sorted in ascending order.  the operation `printList(L, P)` will print the elements in `L` that are in positions specified by `P`.  

for instance if `P = 1, 3, 4, 6` the elements in positions `1, 3, 4, 6` in `L` are printed.  write th eprocedure `printLots(L, P)`.  you may use only public `stl` container operations.  what is the running time of your procedure?


```cpp
void printLots(LinkedList<int>& L, LinkedList<int>& P) {
    int index = 0;
    for (auto it = L.begin(), it != L.end(); ++it) {
        if (P.find(index) != P.end()) {
            std::cout << *it << " ";
        }
        ++index;
    }
    std::cout << std::endl;
}
```

the `printLots` function takes two linked lists `L` and `P` as input.  the first linked list `L` is the list of elements to be printed, while the second linked list `P` contains the indices of the elements to be printed.  the function iterates through the elements of `L` and checks if the current index is in `P`.  if it is the element is printed.

the `find` function is used to check if the current index is in `P`.  the `find` function returns an iterator to the element in the list with the given index.  if the index is not in the list, the `end` iterator is returned.

`auto` is a keyword used to automatically deduce the data tyoe of the variable based on the data type of the elements in the collection being iterated over. for example
`

```cpp
std::vector<int> v = {1, 2, 3, 4, 5};

// iterate over the vector using auto
for (auto i : v) {
    std::cout << i << " ";
}

// output 1 2 3 4 5
```
