# linkedlist

an **abstract data type** is a set of objects together with a set of operations.  abstract data types are mathematical abstractions; nowhere in an adt's definition is there any mention of _how_ the set of operations is implemented.  objects such as lists, sets, and graphs, along with their operations, can be viewed as adts, just as integers, reals, an d booleans are data types.  integers, reals, and booleans have operations associated with them, and so do adts.  for the set adt, we might have such operations as _add_, _remove_, _size_, and _contains_.  alternatively, we might only want the two operations _union_ and _find_, which would define a different adt on the set.

the c++ class allows for the implementation of adts, with appropriate hiding of implementation details.  thus, any other part of the progrm that needs to perform an operation on the adt can also do so by calling the appropriate method.  if for some reason implementation details need ot be chnaged, it should be easy to do so by merely changing the routines that perform the adt operations.  this change, in a perfect world, would be completely transparent to the rest of the program.  there is no rule in telling us which operations must be supported for each adt; this is a design decision.  error handling and tie breaking (where appropriate) are also generally up to the program designer.  the three data structuyres that we will study in this chapter are primary examples of the adts.  we will see how each can be implemented in several ways, but they are done correctly, the program that use them will not necessarily need to know whcih implementation was used.

**contents**

1.  [the list adt](#the-list-adt)
2.  [simple array implementation of lists](#simple-array-implementation-of-lists)
3.  [simple linked lists](#simple-linked-lists)


## the list adt

we will deal with a general list of the form $A_{0}, A_{1}, A_{2}, \cdots, A_{n - 1}$.  we say that the size of the list is $N$.  we will call the special list of size $0$ an **empty list**.  for any list except the empty list, we say that $A_{i}$ follows $A_{i - 1}, (i < N)$  the first element of the list is $A_{0}$ and the last element is $A_{N - 1}$.  we will not define the predecessor of $A_{0}$ or the successor of $A_{N - 1}$.  the **position** of element $A_{i}$ in a list is $i$.  throughout this readme, we will assume to siplify matters that the elemnts in the list are integers, but in general, arbitrarily complex elements are allowed (and easily handled by a class template).

associated with these "definitions" is a set of operations that we would like to perform on the list adt.  some popular operations are as follows, 

-  `printList` prints the list to the screen
-  `makeEmpty` makes the list empty
-  `find` returns the position of the first occurence of an item
-  `insert` inserts an item at a given position
-  `remove` removes an item at a given position
-  `findKth` returns the $k^{th}$ element of the list, specified as an argument

if the list is `34, 12, 52, 16, 12` then,

-  `find(52)` might return `2`
-  `insert(x, 2)` might make the list into `34, 12, x, 52, 16, 12` if we insert into the position given
-  `remove(52)` might turn that list into `34, 12, x, 16, 12`



