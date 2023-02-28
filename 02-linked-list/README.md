# linkedlist

an **abstract data type** is a set of objects together with a set of operations.  abstract data types are mathematical abstractions; no where in an adt's definition is there any mention of _how_ the set of operations is implemented.  objects such as lists, sets, and graphs, along with their operations, can be viewed as adts, just as integers, reals, and booleans are data types.  integers, reals, and booleans have operations associated with them, and so do adts.  for the set adt, we might have such operations as _add_, _remove_, _size_, and _contains_.  alternatively, we might only want the two operations _union_ and _find_, which would define a different adt on the set.

the c++ class allows for the implementation of adts, with appropriate hiding of implementation details.  thus, any other part of the progrm that needs to perform an operation on the adt can also do so by calling the appropriate method.  if for some reason implementation details need to be changed, it should be easy to do so by merely changing the routines that perform the adt operations.  this change, in a perfect world, would be completely transparent to the rest of the program.  there is no rule in telling us which operations must be supported for each adt; this is a design decision.  error handling and tie breaking (where appropriate) are also generally up to the program designer.  the three data structures that we will study in this chapter are primary examples of the adts.  we will see how each can be implemented in several ways, when they are done correctly, the program that use them will will not necessarily need to know which implementation was used.

**contents**

0.  [primitive preview](#primitive-preview)
1.  [the list adt](#the-list-adt)
2.  [simple array implementation of lists](#simple-array-implementation-of-lists)
3.  [simple linked lists](#simple-linked-lists)
4.  [`vector` and `list` in the standard template library](#vector-and-list-in-the-standard-template-library)
5.  [iterators](#iterators)

## primitive preview 

```c++
#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include <iostream>
#include <algorithm>

template <typename DataType>

class LinkedList {
    private:
        struct Node {
            DataType data;
            Node *prev;
            Node *next;
            int counter;

            Node(const DataType &d = DataType{}, Node *p = nullptr, Node *n = nullptr) {
                std::cout << "constructor" << std::endl;
                data = d;
                prev = p;
                next = n;
            }
        };
        int theSize;
        Node *head;
        Node *tail;

        void init() {
            theSize = 0;
            head = new Node;
            tail = new Node;
            head -> next = tail;
            tail -> prev = head;
            return;
        }

    public:
        LinkedList() {
            std::cout << "constructor called" << std::endl;
            init();
        }

};

#endif // __LINKEDLIST_H__
```

**private member variables**

-  `Node` is a nested class, which means that it is a class that is defined within another class.  it is a private member of the `LinkedList` class, which means that it can only be accessed by the `LinkedList` class.  it is a struct, which means that all of its members are public by default.  
    -  it has three members:  `data`, `prev`, and `next`.  
    -  `data` is a `DataType` object, which is a template parameter.  
    -  `prev` and `next` are pointers to `Node` objects.  
    -  `counter` is an integer that is used to keep track of the number of times a node has been accessed.  
    -  it is used in the `access` method, which is used to determine which node should be removed from the list when the list is full.  
    -  the `Node` constructor takes three parameters:  `d`, `p`, and `n`.  `d` is a `DataType` object, which is a template parameter.  `p` and `n` are pointers to `Node` objects.  the constructor initializes the `data` member to `d`, the `prev` member to `p`, and the `next` member to `n`.  
    -  the `Node` constructor is called by the `LinkedList` constructor, 
-  `theSize` is an integer that is used to keep track of the number of nodes in the list.  it is initialized to 0 in the `init` method, which is called by the `LinkedList` constructor.
-  `head` is a pointer to a `Node` object.  it is initialized to a new `Node` object in the `init` method, which is called by the `LinkedList` constructor.
-  `tail` is a pointer to a `Node` object.  it is initialized to a new `Node` object in the `init` method, which is called by the `LinkedList` constructor.

**private member functions**

-  `init` is a private member function that is used to initialize the `theSize`, `head`, and `tail` member variables.  it is called by the `LinkedList` constructor.
-  `Node` is a nested class, which means that it is a class that is defi    ned within another class.  it is a private member of the `LinkedList` class, which means

## the list adt

we will deal with a general list of the form $A_{0}, A_{1}, A_{2}, \cdots, A_{n - 1}$.  we say that the size of the list is $N$.  we will call the special list of size $0$ an **empty list**.  for any list except the empty list, we say that $A_{i}$ follows $A_{i - 1}, (i < N)$  the first element of the list is $A_{0}$ and the last element is $A_{N - 1}$.  we will not define the predecessor of $A_{0}$ or the successor of $A_{N - 1}$.  the **position** of element $A_{i}$ in a list is $i$.  throughout this readme, we will assume to simplify matters that the elemnts in the list are integers, but in general, arbitrarily complex elements are allowed (and easily handled by a class template).

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

of course, the interpretation of what is appropriate for a function is entirely up to the programmer, as is the handling of special cases (for example, what does `find(1)` return above? we could also add operations such as `next` and `previous`, which would take a position as argument and return the position of the successor and predecessor, respectively.

## simple array implementation of lists

all these instructions can be implemented just by using an array.  although arrays are created with a fixed capacity, the `vector` call, which internally stores an array, allows the array to drow by doubling its capacity when needed.  this solves the most serious problem with using an array - namely, that historically to use can array an estiate of the maximum size of the list was required.  this estimate is no longer needed.

an array implementation allows `printList` to be carried out in linear time, and the `findKth` operation takes constant time, which is as good as can be expected.  however, insertion and deletion are potentially expensive, depending on where the insertions and deletions occur.  in the worst case, inserting into position `0` (in other words, at the front of the first) element requires pushing the entire array down one spot to make room, and deleting the first element requires shifting all the elemnets in the list up one spot, so the worst case for these operations is $O(N)$.  on average, half of the list needs to be moved for either operation, so linear tine is still required.  on the other hand, if all the operations occur at the high end of the list, then no elements need to be shifted, and then adding and deleting takes $O(1)$ time.

there are many situations where the list is built up by insertions at the high end, and then only array access (i.e. `findKth` operations) occur.  in such a casse, the array is a suitable implementation.  however, if insertions and deletions occur throughout the list and, in particular, at the front of the list, then the array is not a good option.  the next section deals with the alternative:  the _linked list_.

## simple linked lists

in order to avoid the linear cost of insertion and deletion, we need to ensure that the list is not stored contiguously, since otherwise entire parts of the list will need to be moved, the figure below shows a general idea of a `linkedList`.

![linked list](./assets/ll.png)

the linked list consists of a series of nodes, which are not necessarily adjacent in memory.  each node contains the element and a link to a node containing its successor.  we  call this the `next` link.  the last cell's `next` link points to `nullptr`.  to execute `printList()` or `find(x)`, we merely start at the first node in the list and then traverse the list by following the `next` links.  this operation is clearly linear-tine, as in the array implementation; although, the constant is likely to be larger than if an array implementation was used.  the `findKth` operation is no longer quite as efficient as an array implementation, `findKth(i)` take $O(i)$ time and works by traversing down th elist in the obvious manner.  in practice, this bound is pessimistic, because frequently the calls to `findKth` are sorted order (by `i`).  as an example `findKth(2)`, `findKth(3)`, `findKth(4)`, and `findKth(6)` can all be executed in one scan down the list.

the `remove` method can be executed in one `next` pointer change.  the next figure shows the result of deleting the third element in the original list.

![linked list](./assets/lld.png)

the `insert` method requires obtaining a new node from the system by using `new` call then executing two `next` pointer maneuvers.  the general idea is shown below.  the dashed line represents the old pointer.  

![linked list](./assets/lli.png)

as we can see, in principle if we known where a change is to be made, inserting or removing an item from a linked list does not require moving lots of items, and instead involves only a constant number of changes to node links.

the special case of adding to the front or removing the first item is thus a constant time operation, presuming of course that a link to the front of the linked list is maintained.

the special case of adding at the end (i.e. making a new item the last item) can be constant-time, as long as we maintain a link to the last node.  thus, a typical linkedlist keeps links to both ends of the list.  removing the last item is trickier, because we have to find the next-to-last item, change is _next_ link to `nullptr`, and then update the link that maintains the last node.  in the classic linked list, where each node stores a link to it's next node, having a link to the last node provides no informationabout the next-to-last node.

the obvious idea of maintaining a third link to the next-to-last node doesnt work, because it would need to be updated during a remove.  instead we have every node maintain a link to to its previous node in the list.  this is shown in the next figure and is known as a **doubly linked list**.

## `vector` and `list` in the standard template library

the c++ language includes, in its library an implementation of common data structures.  this part of the language is popularly known as the standard template library.  the list adt is one of the data structures implemented in the stl.  these data structures are called **collections** or **containers**.  there are two popular implementations of the list adt.  the `vector` provides a growable array implementation of the list adt.  the `list` provides a doubly linked list implementation of the list adt.  the advantage fo using the `lists` is that insertion of new items and removal of existing items is cheap, provided that the position of the changes is known.  this disadvantage is that the `list` is not easily indexable.  both `vector` and `list` are inefficient for searches.  throughout this readme, `list` refers to the doubly linked list in the stl, whereas list (typeset without the monospace font) refers to the more general list adt.

`list` are class templates that are instantiated with the type of items that they store.  both have several methods in common. the first three methods shown are actually available for all the stl containers.  additionally `list` supports adding and removing from the end of the list in constant time and accessing the front item in the list in constant time.  in terms of `push_front` and `pop_front()` -  a doubly linked list allows efficient changes at the front.  

-  **`int size() const`**  returns the number of elements in the container.
-  **`void clear()`**  removes all elements from the container
-  **`bool empty() const`** returns true if the container contains no elements, and false otherwise
-  **`void push_back(const DataType & x)`**  adds `x` to the end of the list
-  **`void pop_back()`** removes the object at the end of the list
-  **`const DataType & back() const`**  returns the object at the end of the list without removing it, this is non-mutable.  
-  **`DataType & back()`**  returns the object at end of the list without removing it, this is mutable.
-  **`const DataType & front() const`**  returns the object at the front of the list without removing it, this is non-mutable.
-  **`DataType & front()`**  returns the object at the front of the list without removing it, this is mutable.
-  **`void push_front(const DataType & x)`**  adds `x` to the front of the list
-  **`void pop_front()`**  removes the object at the front of the list

## iterators

some operations on lists, most critically those to insert and remove from the middle ofthe list, require the notion of a position.  in the standard template library, a position is represented by a nested type, `iterator`.  in particular, for a `list<std::string>`, the position is represented by the `list<std::string>::iterator`.  in describing these methods, we'll simply use `iterator` as a shorthand, but when writing code, we will use the actual nested class name.  initially there are three main issues to address, namely,

1.  how one gets an iterator
2.  what operations the iterators themselves can perform
3.  which `list` adt methods require iterators as parameters

### getting an iterator

for the first issue, the stl lists (and all other stl containers) define a pair of methods:

-  `iterator begin()`  returns an appropriate iterator representing the first item in the container
-  `iterator end()`  returns an appropriate iterator representing the end marker in the container (i.e. the position after the last item in the container)

the `end` method seems a little unusual because it returns an iterator that is "out-of-bounds"  to see the idea consider the following code typically used to print the items in a `vector v` prior to the introduction of range-based `for` loops in c++11

```c++
for (int i = 0; i != v.size(); ++i) {
    std::cout << v[i] << std::endl;
}
```

if we were to rewrite this code using iterators, we would see a natural correspondence with the `begin` and `end` methods

```c++
for (vector<int>::iterator itr = v.begin(); itr != v.end; itr.????) {
    std::cout << itr.???? << std::endl;
}
```

in the loop termination test, both `i != v.size()` and `itr != v.end()` are intended to test if the loop counter has become out-of-bounds.  the code fragment also brings us to the second issue, which is that the iteratopr must have methods associated with it (these unknwon methods are represented by `????`.

### iterator methods






