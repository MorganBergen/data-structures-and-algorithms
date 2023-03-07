# LinkedList

an **abstract data type** is a set of objects together with a set of operations. abstract data types are mathematical abstractions; no where in an adt's definition is there any mention of *how* the set of operations is implemented. objects such as lists, sets, and graphs, along with their operations, can be viewed as adts, just as integers, reals, and booleans are data types. integers, reals, and booleans have operations associated with them, and so do adts. for the set adt, we might have such operations as *add*, *remove*, *size*, and *contains*. alternatively, we might only want the two operations *union* and *find*, which would define a different adt on the set.

the c++ class allows for the implementation of adts, with appropriate hiding of implementation details. thus, any other part of the program that needs to perform an operation on the adt can also do so by calling the appropriate method. if for some reason implementation details need to be changed, it should be easy to do so by merely changing the routines that perform the adt operations. this change, in a perfect world, would be completely transparent to the rest of the program. there is no rule in telling us which operations must be supported for each adt; this is a design decision. error handling and tie breaking (where appropriate) are also generally up to the program designer. the three data structures that we will study in this chapter are primary examples of the adts. we will see how each can be implemented in several ways, when they are done correctly, the program that use them will will not necessarily need to know which implementation was used.

## toggle 

<details>
<summary>see what the html looks like to implement this</summary>
```html
<details>
<summary>string of toggle text</summary>
</details>
```
</details>


**contents**

0.  [primitive preview](#primitive-preview)
1.  [the list adt](#the-list-adt)
2.  [simple array implementation of lists](#simple-array-implementation-of-lists)
3.  [simple linked lists](#simple-linked-lists)
4.  [`vector` and `list` in the standard template library](#vector-and-list-in-the-standard-template-library)
5.  [iterators](#iterators)
6.  [getting an iterator](#getting-an-iterator)
7.  [iterator methods](#iterator-methods)
8.  [container operations that require iterators](#container-operations-that-require-iterators)
9.  [example using `erase` on a list](#example-using-erase-on-a-list)
10. [`const_iterators`](#const-iterators)
11. [implementation of `list`](#implementation-of-list)

## primitive preview

``` cpp
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

            Node(const DataType &d = DataType{}, Node *p = nullptr, Node *n = nullptr) :
                data{d}, prev{p}, next{n} { }

            Node(const DataType &&d, Node *p = nullprt, Node *n = nullptr) :
                data{std::move(d)}, prev{p}, next{n} { }
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

-   `Node(const DataType &d = DataType("100"), Node *p = nullptr, Node *n = nullptr)`
-   `const DataType &d = DataType("100");`

### template instantiation

-   `DataType()`

`DataType()` is a default constructor call, when a type `DataType` is specified as a template parameter, it means that any valud data type can be used to instantiate the template.

the `template <typename DataType>` line at the beginning of the definition of the `linkedList` class indicates that `DataType` is a type parameter for the `LinkedList` class, allowing it to work with different types of data.

if we create a `LinkedList` object using `LinkedList<int> myList` then `int` is substituted for `DataType` throughout the class definition. this allows us to use `DataType` as a type throughout the class definition without knowing ahead of time what `DataType` will be.

when we call `head = new Node;` in the `init` function...

``` cpp
void init() {
    theSize = 0;
    head = new Node;
    tail = new Node;
    head -> next = tail;
    tail -> prev = head;
}
```

the `DataType` constructor is called to initialize the `data` member of the `Node` object. since we havent specified the type of `DataType` it will be determined at compile time. when you use the `linkedList` class with a particular data type, say for instance in main.cpp `LinkedList<int> green;` then `head -> data` will be initalized with the default constructor for `int`. if we instead instantiate `LinkedList<double> myList`, the `head -> data` will be initialized with the default constructor for `double`.

**private member variables**

-   `Node` is a nested class, which means that it is a class that is defined within another class. it is a private member of the `LinkedList` class, which means that it can only be accessed by the `LinkedList` class. it is a struct, which means that all of its members are public by default.
    -   it has three members: `data`, `prev`, and `next`.\
    -   `data` is a `DataType` object, which is a template parameter.\
    -   `prev` and `next` are pointers to `Node` objects.\
    -   `counter` is an integer that is used to keep track of the number of times a node has been accessed.\
    -   it is used in the `access` method, which is used to determine which node should be removed from the list when the list is full.\
    -   the `Node` constructor takes three parameters: `d`, `p`, and `n`. `d` is a `DataType` object, which is a template parameter. `p` and `n` are pointers to `Node` objects. the constructor initializes the `data` member to `d`, the `prev` member to `p`, and the `next` member to `n`.\
    -   the `Node` constructor is called by the `LinkedList` constructor,
-   `theSize` is an integer that is used to keep track of the number of nodes in the list. it is initialized to 0 in the `init` method, which is called by the `LinkedList` constructor.
-   `head` is a pointer to a `Node` object. it is initialized to a new `Node` object in the `init` method, which is called by the `LinkedList` constructor.
-   `tail` is a pointer to a `Node` object. it is initialized to a new `Node` object in the `init` method, which is called by the `LinkedList` constructor.

**private member functions**

-   `init` is a private member function that is used to initialize the `theSize`, `head`, and `tail` member variables. it is called by the `LinkedList` constructor.
-   `Node` is a nested class, which means that it is a class that is defi ned within another class. it is a private member of the `LinkedList` class.

1.  `Node(const DataType &&d, Node *p, Node *n);` move constructor

```cpp
Node(const DataType &&d, Node *p, Node *n) :
    data{std::move(d)}, prev{p}, next{n};
}
```
this ia a move constructor it takes an rvalue reference to a `DataType` object `d` and moves it into the data member `data` using `std::move`.  the move constructor is used when creating a new `Node` object from an existing one, but transferring ownership of the data from the existing object to the new one.  this can be more efficient than copying the data itself.

`Node` in general is a `struct` that holds a piece of data of type `DataType` as well as pointers to the previous and next nodes in the list.  the constructor takes an rvalue reference to a `DataType` object `DataType &&d` as well as two other nodes `Node *p = nullptr` and `Node *n = nullptr`.

`std::move` is being used to cast `d` to an rvalue reference, which essentially "moves" the data rather than copying and assigning it.  this is a way to optimize the code and avoid unnecessary copying of the data.  the `std::move` function is part of the c++ standard library adn is used to convert an lvalue (an object that has a name and is stored in memory) to an rvalue (a temporary object that can be moved or destroyed).

this `Node` move constructor is delcared with an rvalue reference parameter for `d`, because it is expected that `d` will be a temporary object (an rvalue) that will be moved into the `Node` object, specifically it's member variable `data`.  this can help to avoid unnecessary copying of the `DataType()` object and improve the performance of the program.  the `prev` and `next` pointers are declared as regular pointers because they are not expected to be temporary object.  they are simply pointer to other nodes in the linked list.  the `Node` move constructor initializes these pointer to `nullptr` by default if no arguments are provided.


## the list adt

we will deal with a general list of the form $A_{0}, A_{1}, A_{2}, \cdots, A_{n - 1}$. we say that the size of the list is $N$. we will call the special list of size $0$ an **empty list**. for any list except the empty list, we say that $A_{i}$ follows $A_{i - 1}, (i < N)$ the first element of the list is $A_{0}$ and the last element is $A_{N - 1}$. we will not define the predecessor of $A_{0}$ or the successor of $A_{N - 1}$. the **position** of element $A_{i}$ in a list is $i$. throughout this readme, we will assume to simplify matters that the elemnts in the list are integers, but in general, arbitrarily complex elements are allowed (and easily handled by a class template).

associated with these "definitions" is a set of operations that we would like to perform on the list adt. some popular operations are as follows,

-   `printList` prints the list to the screen
-   `makeEmpty` makes the list empty
-   `find` returns the position of the first occurence of an item
-   `insert` inserts an item at a given position
-   `remove` removes an item at a given position
-   `findKth` returns the $k^{th}$ element of the list, specified as an argument

if the list is `34, 12, 52, 16, 12` then,

-   `find(52)` might return `2`
-   `insert(x, 2)` might make the list into `34, 12, x, 52, 16, 12` if we insert into the position given
-   `remove(52)` might turn that list into `34, 12, x, 16, 12`

of course, the interpretation of what is appropriate for a function is entirely up to the programmer, as is the handling of special cases (for example, what does `find(1)` return above? we could also add operations such as `next` and `previous`, which would take a position as argument and return the position of the successor and predecessor, respectively.

## simple array implementation of lists

all these instructions can be implemented just by using an array. although arrays are created with a fixed capacity, the `vector` call, which internally stores an array, allows the array to drow by doubling its capacity when needed. this solves the most serious problem with using an array - namely, that historically to use can array an estiate of the maximum size of the list was required. this estimate is no longer needed.

an array implementation allows `printList` to be carried out in linear time, and the `findKth` operation takes constant time, which is as good as can be expected. however, insertion and deletion are potentially expensive, depending on where the insertions and deletions occur. in the worst case, inserting into position `0` (in other words, at the front of the first) element requires pushing the entire array down one spot to make room, and deleting the first element requires shifting all the elemnets in the list up one spot, so the worst case for these operations is $O(N)$. on average, half of the list needs to be moved for either operation, so linear tine is still required. on the other hand, if all the operations occur at the high end of the list, then no elements need to be shifted, and then adding and deleting takes $O(1)$ time.

there are many situations where the list is built up by insertions at the high end, and then only array access (i.e. `findKth` operations) occur. in such a casse, the array is a suitable implementation. however, if insertions and deletions occur throughout the list and, in particular, at the front of the list, then the array is not a good option. the next section deals with the alternative: the *linked list*.

## simple linked lists

in order to avoid the linear cost of insertion and deletion, we need to ensure that the list is not stored contiguously, since otherwise entire parts of the list will need to be moved, the figure below shows a general idea of a `linkedList`.

![linked list](./assets/ll.png)

the linked list consists of a series of nodes, which are not necessarily adjacent in memory. each node contains the element and a link to a node containing its successor. we call this the `next` link. the last cell's `next` link points to `nullptr`. to execute `printList()` or `find(x)`, we merely start at the first node in the list and then traverse the list by following the `next` links. this operation is clearly linear-tine, as in the array implementation; although, the constant is likely to be larger than if an array implementation was used. the `findKth` operation is no longer quite as efficient as an array implementation, `findKth(i)` take $O(i)$ time and works by traversing down th elist in the obvious manner. in practice, this bound is pessimistic, because frequently the calls to `findKth` are sorted order (by `i`). as an example `findKth(2)`, `findKth(3)`, `findKth(4)`, and `findKth(6)` can all be executed in one scan down the list.

the `remove` method can be executed in one `next` pointer change. the next figure shows the result of deleting the third element in the original list.

![linked list](./assets/lld.png)

the `insert` method requires obtaining a new node from the system by using `new` call then executing two `next` pointer maneuvers. the general idea is shown below. the dashed line represents the old pointer.

![linked list](./assets/lli.png)

as we can see, in principle if we known where a change is to be made, inserting or removing an item from a linked list does not require moving lots of items, and instead involves only a constant number of changes to node links.

the special case of adding to the front or removing the first item is thus a constant time operation, presuming of course that a link to the front of the linked list is maintained.

the special case of adding at the end (i.e. making a new item the last item) can be constant-time, as long as we maintain a link to the last node. thus, a typical linkedlist keeps links to both ends of the list. removing the last item is trickier, because we have to find the next-to-last item, change is *next* link to `nullptr`, and then update the link that maintains the last node. in the classic linked list, where each node stores a link to it's next node, having a link to the last node provides no informationabout the next-to-last node.

the obvious idea of maintaining a third link to the next-to-last node doesnt work, because it would need to be updated during a remove. instead we have every node maintain a link to to its previous node in the list. this is shown in the next figure and is known as a **doubly linked list**.

## `vector` and `list` in the standard template library {#vector-and-list-in-the-standard-template-library}

the c++ language includes, in its library an implementation of common data structures. this part of the language is popularly known as the standard template library. the list adt is one of the data structures implemented in the stl. these data structures are called **collections** or **containers**. there are two popular implementations of the list adt. the `vector` provides a growable array implementation of the list adt. the `list` provides a doubly linked list implementation of the list adt. the advantage fo using the `lists` is that insertion of new items and removal of existing items is cheap, provided that the position of the changes is known. this disadvantage is that the `list` is not easily indexable. both `vector` and `list` are inefficient for searches. throughout this readme, `list` refers to the doubly linked list in the stl, whereas list (typeset without the monospace font) refers to the more general list adt.

`list` are class templates that are instantiated with the type of items that they store. both have several methods in common. the first three methods shown are actually available for all the stl containers. additionally `list` supports adding and removing from the end of the list in constant time and accessing the front item in the list in constant time. in terms of `push_front` and `pop_front()` - a doubly linked list allows efficient changes at the front.

-   **`int size() const`** returns the number of elements in the container.
-   **`void clear()`** removes all elements from the container
-   **`bool empty() const`** returns true if the container contains no elements, and false otherwise
-   **`void push_back(const DataType & x)`** adds `x` to the end of the list
-   **`void pop_back()`** removes the object at the end of the list
-   **`const DataType & back() const`** returns the object at the end of the list without removing it, this is non-mutable.\
-   **`DataType & back()`** returns the object at end of the list without removing it, this is mutable.
-   **`const DataType & front() const`** returns the object at the front of the list without removing it, this is non-mutable.
-   **`DataType & front()`** returns the object at the front of the list without removing it, this is mutable.
-   **`void push_front(const DataType & x)`** adds `x` to the front of the list
-   **`void pop_front()`** removes the object at the front of the list

## iterators

some operations on lists, most critically those to insert and remove from the middle ofthe list, require the notion of a position. in the standard template library, a position is represented by a nested type, `iterator`. in particular, for a `list<std::string>`, the position is represented by the `list<std::string>::iterator`. in describing these methods, we'll simply use `iterator` as a shorthand, but when writing code, we will use the actual nested class name. initially there are three main issues to address, namely,

1.  how one gets an iterator
2.  what operations the iterators themselves can perform
3.  which `list` adt methods require iterators as parameters

### getting an iterator 

for the first issue, the stl lists (and all other stl containers) define a pair of methods:

-   `iterator begin()` returns an appropriate iterator representing the first item in the container
-   `iterator end()` returns an appropriate iterator representing the end marker in the container (i.e. the position after the last item in the container)

the `end` method seems a little unusual because it returns an iterator that is "out-of-bounds" to see the idea consider the following code typically used to print the items in a `vector v` prior to the introduction of range-based `for` loops in c++11

``` cpp
for (int i = 0; i != v.size(); ++i) {
    std::cout << v[i] << std::endl;
}
```

if we were to rewrite this code using iterators, we would see a natural correspondence with the `begin` and `end` methods

``` cpp
for (vector<int>::iterator itr = v.begin(); itr != v.end; itr.????) {
    std::cout << itr.???? << std::endl;
}
```

in the loop termination test, both `i != v.size()` and `itr != v.end()` are intended to test if the loop counter has become out-of-bounds. the code fragment also brings us to the second issue, which is that the iteratopr must have methods associated with it (these unknwon methods are represented by `????`.

### iterator methods 

based on the code fragment above it's obvious that iterators can be compared with `!=` and `==`, and likely have copy constructors and `operators=` defined. thus iterators have methods and many of the methods use operator overloading. besides copying the most commonly used operations on iterators include the following

-   `itr++` and `++itr`, advances the iterator `itr` to the next location. both the prefix and postfix forms are allowable.

-   `*itr` returns a reference to the object stored at iterator `itr` location. the reference returned may or may not be modifiable (we discess these details shortly)

-   `itr1 == itr2` returns true if iterators `itr1` and `itr2` refer to the same location and false otherwise

-   `itr1 != itr2` returns true if iterators `itr1` anf `itr2` refer to a different location and false otherwise.

with these operators, the code to print would be as follows

``` cpp
for (linkedlist<int>::iterator itr = redList.begin(); itr != redList.end(); ++itr) {
    std::cout << *itr << std::endl;
}
```

the use of operator overloading allows one to access the current item, then advance to the next item using `*itr++`. thus an alterantive to the fragment above is...

``` cpp
linkedlist<int>::iterator = itr = redList.begin();
while (itr != redList.end()) {
    std::cout << *itr++ << std::endl;
}
```

### container operations that require iterators

for the last issue, the tree most popular methods that require iterators are those that add or remove from the list at a specified position

1.  `iterator insert(iterator itr, const T &x);`  adds `x` into the list, prior to the position given by the iterator `itr`.  this is a constant-time operation for `list`

2.  `iterator erase(iterator itr);`  removes the object at the position given by the iterator.
3.  `iterator erase(iterator from, iterator to)`

## implementation of `list`

in this section we will provide an implementation of a usable `list` class template. the `list` class will be implemented as a doubly linkedlist and that we will need to maintain pointers to both ends of the list. doing so allows us to maintain constant time cost per operation, so long as the operation occurs at a known position. the known position can be at either end or at a position specified by an iterator.

1.  `list`

contains links to both ends of the list, the size of the list, and a host of methods

2.  `Node`

the node class which is likely to be a private nest class, a node contains the data an dpointers to the previous and next nodes, along with appropriate constructors.

3.  `const_iterators` class which abstracts the notion of a position, and is a public nest class. the `const_iterator` stores a pointer to the current node, and provides implementation of the basic iterator operations, all in the form of overloaded operators such as `=`, `==`, `!=`, `++`

4.  `iterator`

class which abstracts the notion of a position, and is a public nested class. the `iterator` has the same functionality as `const_iterator` except that `operator*` returns a reference to the item being viewed, rather than a constant reference to the item itself. an important technical issue is that an `iterator` can be used in any routine that requires a `const_iterator`, but not vice versa. in other words, `iterator` is a `const_iterator`.

because the iterator classes store a pointer to the current node, and the end marker is a valid position, it makes sense to create an extra node at the end of the list to represent the end marker. further we can create an extra node at the front of the list, logically representing a the beginning marker. these extra nodes are sometimes known as **sentinel nodes**, specifically the node at the front is sometimes known as a **header node**, and the node at the end is sometimes called the **tail node**.

the advantage of using these extra nodes is that they greatly simplify the coding by removing a host of special cases. for instance, if we don't use a header node, then removing the first node becomes a special case. because we must reset the list's link to the first node during the remove and because the remove algorithm in general needs to access the node prior to the node being removed (and without a header node, the first node does not have a node prior to it).

we can see that at the beginning of the declaration of the private nested `Node` class rather than using `class` keyword we use `struct`, in c++ the `struct` is a relic from the c programming language. a `struct` in c++ is essentially a `class` in which the members default to public. reccall that in a class the members default to private. clearly the keyword `struct` is not needed, but you will often see it and it is commonly used by programmers to signify a type that contains mostly data that are accessed directly, rather than through methods. in our case, making the members public in the `node` class will not be a problem since the `node` class itself is private and inaccessible outside of the `list` class.

## `LinkedList` boiler plate

```cpp
#ifndef __LINKEDLIST__
#define __LINKEDLIST__

#include <algorithm> 
#include <iostream>

template <typename T>
class LinkedList {
    private:
        int theSize;
        Node *head;
        Node *tail;

        struct Node {
            T data;
            Node *next;
            Node *prev;
            Node(const T &d = T{}, Node *p = nullptr, Node *n = nullptr) :
                next{n}, prev{p}, data{d};
        };

        void init() {}
    
    public:

        LinkedList();
        LinkedList(LinkedList &rhs);
        LinkedList(LinkedList &&rhs) :
            theSize(rhs.theSize), head (rhs.head), tail(rhs.tail);
        ~LinkedList();
        LinkedList &operator = (const LinkedList &rhs);
        LinkedList &operator = (LinkedList &&rhs);

        class const_iterator {
            protected:
                Node *current;
                T &retrieve() const;
                const_iterator(Node *p);
                friend class LinkedList<T>;
            
            public: 
                const_iterator() : current{nullptr};
                const T &operator * () const;
                const_iterator &operator ++ ();
                const_iterator operator ++ (int);
                const_iterator &operator -- ();
                const_iterator operator -- (int);
                bool operator == (const const_iterator &rhs) const;
                bool operator != (const const_iterator &rhs) const;
        };

        class iterator : public const_iterator {
            protected:
                iterator(Node *p);
                const_iterator{p};
                friend class LinkedList<T>;

            public:
                iterator();
                T& operator * ();
                const T& operator * () const;
                iterator& operator ++ ();
                iterator operator ++ (int);
                iterator operator -- ();
                iterator operator -- (int);
        };
        
        iterator begin();
        const_iterator begin() const;
        iterator end();
        const_iterator end() const;
        int size() const;
        bool empty() const;
        void clear();
        T & front();
        const T & front() const;
        T & back();
        iterator insert(iterator itr, const T &x);
        iterator insert(iterator itr, T &&x);
        iterator erase(iterator itr);
        iterator erase(iterator from, iterator to);
        void push_front(const T& x); 
        void push_front(T &&x);
        void push_back(const T &x); 
        void push_back(T &&x);
        void pop_front();
        void pop_back();
        void reverseList();
        LinkedList<T> & appendList(LinkedList<T> &&rlist);
        bool swapAdjElements(iterator &itr); 

};

#endif 
```

##  classes of `LinkedList` 

1.  `class LinkedList` is a templated class that implements a doubly linked list data structure

2.  `private` section contains `theSize` of the list, `Node *head` a pointer to the head of the list, and `Node *tail` a pointer to the tail of the list.

3.  `struct Node` is a private nested class that contains the data `T data`, a pointer to the next node `Node *next`, and a pointer to the previous node `Node *prev`

4.  `init` is a private methods that initailizes the list, it's constructor `LinkedList()` calls it.

5.  `public` section contains 

-  the default constructor `LinkedList()`
-  copy constructor `LinkedList(LinkedList &rhs);`
-  move constructor `LinkedList(LinkedList &&rhs)`
-  destructor `~LinkedList()`
-  copy assignment operator `LinkedList &operator = (const Linked List &rhs);`
-  move assignment operator `LinkedList &operator = (LinkedList &&rhs);`
-  nested classes `const_iterator`, and `iterator`

6.  `class const_iterator` is a public nested class that is used to iterate through the list/  it keeps a pointer to the `Node` objects which represents the current position in the linkedlist.  the `const_iterator` class provides methods to access and modify the data stored in the linkedlist.

7.  the `const_iterator() : current{nullptr}` constructor creates a new `const_iterator` object that points to `nullptr`

## `const_iterator` class

```cpp
// ...
    public:
        class const_iterator {
            protected:
                Node *current;
                T& retrieve () const;
                const_iterator(Node *p) : current{p} {}
                friend class LinkedList<T>;
            public:
                const_iterator() : current{nullptr};
                const T &operator * () const;
                const_iterator &operator ++ ();
                const_iterator operator ++ ();
                const_iterator &operator -- ();
                const_iterator operator -- (int);
                bool operator == (const const_iterator &rhs) const;
                bool operator != (const consT-iterator &rhs) const; 
        };
```
```cpp
//...
    public:
        class const_iterator {
            protected:
                Node *current;
                
                T& retrieve () const {
                    return (current -> data);
                }
                const_iterator(Node *p) : current{p} { }
                friend class LinkedList<T>;
            public:
                const_iterator() : current{nullptr} { }
                const T& operator * () const {
                    return (retrieve());
                }
                const_iterator& operator ++ () {
                    current = current -> next;
                    return (*this);
                }
                const_iterator& operator ++ (int) {
                    const_iterator old = *this;
                    ++(*this);
                    return(old);
                }
                const_iterator& operator -- () {
                    current = current -> prev;
                    return (*this);
                }
                const_iterator operator -- (int) {
                    const_iterator old = *this;
                    --(*this);
                    return (*this);
                }
                bool operator == (const const_iterator &rhs) const {
                    return (current == rhs.current);
                }
                bool operator != (const consT-iterator &rhs) const {
                    return (!(*this == rhs));
                }
        };
//...
```

the `const_iterator` class is a nested class within the `LinkedList` class, it is used to provide a read only interface to the elements of the `LinkedList`.  `const_iterator` is used when you want to iterate over the `LinkedList` without modifying its elements.  it's similar to the regular `iterator` class, but it prevents you from modifying the elements it points to.  this is useful in situations where you want to ensure that the linkedlist remains unchange while it's being iterated over.

### `class const_iterator { protected:` member variables & methods
<details>
<summary>1.  <code>const_iterator</code> summary</summary>
<code>const_iterator</code> is an embedded class of the linkedlist class, it is an iterator that can be used to traverse through the linkedlist in a read-only manner.
</details>

<details>
<summary>2.  <code>retrieve()</code> summary</summary>
<code>retrieve</code> returns a reference to the data stored in the node that the iterator is currently pointing to.  <code>T&</code> represents a reference to the object of type <code>T</code>. the <code>&</code> symbol denotes a reference type, which means that the value returned by <code>retrieve()</code> is not a copy but a reference to the object stored in the <code>current -> data</code> member variable.  so the value actually being returned is being stored in memory and is not a copy.  

the reference is returned is using the `&` symbol in the function signature, and this allows the calling function to directly modify the value stored in the linked list.  this means that if the calling function modifies the value returned by <code>retrieve()</code>, the value stored in the linkedlist will also be modified.

**refresher on references**
a reference is an alias, or alterantive name for an existing variable.  it is essentially a way to access and modify the original variable through a different name.  when a reference is created, it must be initialized to refer to an existing object.  once initialized, the reference behaves like the object itself.  any changes made to the reference are actually made to the original object, and any operations performe on the reference are actually performed on the original object.

one key difference between a reference and a pointer is that a reference cannot be null and must always refer to an existing object, while a pointer can be null and can point to any object of its assigned type.  additionally, once a reference is initialized, it cannot be re-assigned to refer to a different object, while a pointer can be reassigned to point to a different object.
</details>

<details>
<summary>3.  <code>const_iterator(Node `*`p) : current{p} { }</code></summary>
the parameterized constructor for the subclass <code>const_iterator</code> takes a pointer to a <code>Node</code> object as a parameter and initializes the <code>current</code> member variable with it.
the <code>const_iterator</code> is a type of iterator used to iterate over a collection of objects while enforcing const correctness.  it ensures that the collection is not modified during iteration.  this is achieved by defining a separate type of iterator that can be used only to read the collection and not modify it.

the reason why <code>const_iterator</code> exists is to allow iterating over a collection in a read-only manner.  when a collection is marked <code>const</code> it's member functions cannot modify the collection.  in this case <code>const_iterator</code> allows us to iterate over the collection without accidentally modifying it.
</details>

<details>
<summary>4.  <code>friend class LinkedList < T >;</code></summary>
the line <code>friend class LinkedList < T >;</code> within the <code>const_iterator</code> class declares <code>LinkedList</code> class as a friend of the <code>const_iterator</code> class.  this allows <code>LinkedList</code> to access the private and protected members of the <code>const_iterator</code> class.

the <code>friend</code> keyword is used to declare a non-member function or class that is allowed access to private and protected members of a class.  in this case <code>LinkedList</code> is a friend of the <code>const_iteratro</code> class, which means it can access the private and protected members of the <code>const_iterator</code> class.  this is useful when we have two classes that need to work closely together and need access to each other's private members
</details>

<details>
<summary>5.  <code>const_iterator() : current{nullptr} { }</code></summary>
this constructor initializes the <code>current</code> pointer to <code>nullptr</code>, in c++ a point that is set to <code>nullptr</code> means that it does not point to any valid memory location.  the purpose of this constructor is to create a default <code>const_iterator</code> object that doesnt point to any valid memory location.  this is useful when initializing an object before assigning a valid memory location to its <code>current</code> pointer.  

the constructor is declared with an empty parameter list <code>()</code> because it doesnt take any arguments.  this constructor body initializes the <code>current</code> pointer using the member initializer list syntax <code>{}</code>, which initializes the <code>current</code> to <code>nullptr</code>.

overall this constructor provides a way to initialize a <code>const_iterator</code> object with a null pointer which can be used as a starting point for later assignment of valid memory location. 
</details>

<br><br><br>

6. `const T& operator * () const;` 

```cpp
const T& operator * () const {
    return (retrieve());
}
```

is a dereference operator overloaded for a class template.  it returns a reference to the value stored at the current position of the iterator.  in simpler terms when a object of the class template (in this case `const_iteror` is dereferenced using the `*` operator, this overloaded operator will be called, and it will return the value stored at the current position of the iterator.

for example if you have a list of integers and you create a `const_iterator` to iterate over the list, you can access the value of the element pointed to by the `const_iterator` using the `*` operator.  the `*` operator is used to retrieve the value stored at the current position of the `const_iterator`, in this case the output would be "first element of the list is 1".

```cpp
LinkedList<int> mylist{1, 2, 3, 4};
LinkedList<int>::const_iterator itr = myList.begin();
std::cout << "first element of the list is " << *itr << std::endl;
```

7.  `const_iterator& operator ++ ();`  prefix operator overloader

operator overloading is a feature of c++ that allows operators such as `++` to be overloaded or redefined for use with user-defined data types or objects.  this means that you can create a custom definition of what should happen when an operator is used on an object of a certain class.

we are overloading the pre-increment operator `++x` for the `const_iterator` class.  the `const_iterator` class is likely used to iterate through a linked list or other container classes.  the name of the function is `operator ++`  it's a member of `const_iterator` and can be accessed publically.  the `&` in the function declaration means that this function returns a reference to a `const_iterator` object which allows us to chain multiple increment operations together like `++x; ++y; ++z;` the empty parameter list means that the function obviously wont take any arguments.  `current = current -> next` increments the iterator to the next element in the linked list by setting the `current` pointer to the address of the `next` node on the list.  finally the `retrun(*this);`  returns a reference to the `const_iterator` object itself, which allows us to chain multiple increment operations together.  the `*this` notation refers to the current object that the function is being called upon.  in this case it is the same as returning a reference to `current` member variable of the `const_iterator` object.

8.  `const_iterator operator ++ (int);` postfix operator overloader

```cpp
const_iterator operator ++ (int) {
    const_iterator old = *this;
    ++(*this);
    return (old);
}
```

the function signature has `(int)` as an argument, which is a dummy parameter used to distinguish it from the preincrement operator, this in contrast ensures that the operands `++` must come after the object.  we first create a copy of the current `const_iterator` object which is `*this` and it stores it in a new `const_iterator` object called `old`, this is done so that the old (pre-increment) value can be returned later on.

the `++(*this);` increments the current `const_iterator` object `*this` using the preincrement operator, which moves the iterator forward to the next element, we have prefix already declared so it will move `current = current -> next`, the `return(old)` preincrement value of the `const_iterator` object that was stored in `old` allows for the post increment operation to be performed which returns the old value while still moving the iterator forward to the next node.

9.  `const_iterator& operator -- ()` prefix decrement operator overloader

```cpp
const_iterator& operator -- () {
    current = current -> prev;
    return(*this);
}
```

this operator decrements the `current` pointer to point to the previous node and returns the updated `const_iterator` object.  the `const_iterator&` specifies that the return type of the function is a reference (which is an alias to the existing variable) and accesses its current memory location, refering to the original object in memory so any changes will effect that object itself.

`current = current -> prev` decrements the `current` pointer to point to the previous node in the `LinkedList`, `return(*this)` will return the `const_iterator` object itself, which is now pointing to the previous node.

10.  `const_iterator operator -- (int)` postfix decrement operator overloader

```cpp
const_iterator operator -- (int) {
    const_iterator old = *this;
    --(*this);
    return(old);
}
```

11.  `bool operator == (const const_iterator &rhs) const;`

```cpp
bool operator == (const const_iterator &rhs) const {
    return (current == rhs.current);
}
```

12.  `bool operator != (const const_iterator &rhs) const;`

```cpp
bool operator != (const const_iterator &rhs) const {
    return !(*this == rhs);
}
```

## `iterator` class

```cpp
class iterator : public const_iterator {
    protected:
        iterator(Node *p) : const_iterator{p} { }
        friend class LinkedList<T>;
    public:
        iterator() { }
        T& operator * ();
        const T& operator * () const;
        iterator& operator ++ ();
        iterator operator ++ (int);
        iterator& operator -- ();
        iterator operator -- (int);
};
```

### `iterator` implementation

```cpp
class iterator : public const_iterator {
    private:
        iterator(Node *p) : const_iterator{p} { }
        friend class LinkedList<T>
    public:
        iterator() { }
        T& operator * () {
            return (const_iterator::retrieve());
        }
        const T& operator * () {
            return (const_iterator::operator * ());
        }
        iterator& operator ++ (){
            this -> current = this -> current -> next;
            return (*this)
        }
        iterator operator ++ (int) {
            iterator old = *this;
            ++(*this);
            return (old);
        }
        iterator& operator -- () {
            this -> current = this -> current -> prev;
            return(*this);
        }
        iterator operator -- (int)
            iterator old = *this;
            --(*this);
            return (old);
        }
};
```

### `iterator` components
<br>

1.  `iterator : public const_iterator`
2.  `iterator(Node *p) : const_iterator{p} {}`
3.  `friend class LinkedList<T>`
4.  `iterator()`
5.  `T& operator * ()`

    ```cpp
    T& operator * () {
        return (const_iterator::retrieve());
    }
    ```

    -  this is a operator overloaded member method of the iterator class, it returns a reference to the element pointed by the current iterator.  
    -  for a reminder the `::` is the scope resolution operator, it's used to access the function that is not a member of a class, but defined in the scope of the class.  
    - `const_iterator::retrieve()` is calling the retrieve method, which is used to retrieve the value pointed by the current iterator.  the function `retrieve()` is marked as `const` because it does not modify the iterator or the container.
    -  any method that has `DataType function() const` after the `()` means that the function is not allowed to modify the state of the object on which it is called.  it's a way of telling the compiler that this function is read-only and it won't change anything in the object itself.
    -  if the return type of this function is mutable, it means that the function can modify the data associated with the function call.  in this case, the function `operator *()` return a reference to a non-constant value of type `T` through the returned reference.  the constness of `retrieve()` only guarantees that the value of `T` itself will not be modified through that reference.

5.  `const T& operator *() const`

    ```cpp
    const T& operator *() const {
        return (const_iterator::operator*);
    }
    ```

    -  `const` member functyion `operator*()` which returns a constant reference to an object of type `t`.
    -  the function also has the `const` keyword after the closing parenthesis which specifies that the function is a `const` member function and it does not modify the data members of the class.
    -  in the function body we have the `return` statement which returns the result of the calling `operator*` function of the `const_iterator` class.  since the `const_iterator` class has a `const` member function `operator*` which returns a constant reference to an object of type `T`, calling it will return a constant reference to the object it points to.    
    -  the reason why we call the `operator*` function of the `const_iterator` class is that we are using the implementation of `operator*` of `const_iterator` in this function.  this is becasue `const_iterator` is a friend class of the class where this function is defined and it has access to the private members of the class.  specifically the `Node *current` member which is what we want to have access to in order to access it's data element.

6.  `iterator& operator ++ ()`

    ```cpp
    iterator& operator ++ () {
        this -> current = this -> current -> next;
        return (*this);
    }
    ```

    -  in the given code `operator ++` is an overloaded function that returns an iterator object reference.
    -  the `this` pointer which is the object itself refers to the object on which this function is called.
    -  `this -> current` refers to the current `Node` object being pointed to by the iterator
    -  the `current` is a private member of the `const_iterator`, but since `iterator` is **derived** from `const_iterator` it can access the private members of `const_iterator` through inheritance.  therefore, `iterator` has access to `current` and can modify it through the `operator ++ ()` function.
    -  `this -> current -> next` refers to the next node in the linked list

**difference between `const_iterator` and `iterator`**

```cpp
const_iterator& operator ++ () {
    current = current -> next;
    return(*this); 
}

iterator& operator ++ () {
    this -> current = this -> current -> next;
    return(*this);
}
```

- the difference between `current = current -> next` and `this -> current = this -> current -> next` is due to the fact that `iterator` is a child of `const_iterator` and therefore although it has access to `current` it isnt `current` so we need to access it through `this -> current`

-  it has access to `current` member of `const_iterator` so we need to use the `this` pointer to specify that were accessing the `current` member of the `const_iterator`

7.  `iterator operator ++ (int)`

    ```cpp
    iterator operator ++ (int) {
        iterator old = *this;
        ++(*this);
        return(old);
    }
    ```

8.  `iterator& operator -- ()`

    ```cpp
    iterator& operator -- () {
        this -> current = this -> current -> prev;
        return(*this);
    }
    ```
    - `this -> current` must be access because `iterator` is a child of `const_iterator` and again therefore isnt actually `current` but rather is the child of the `const_iterator` object whose member is `current`
    -  `this -> current = this -> current -> prev` behaves where the `prev` is pointed at from the `current`

9.  `iterator operator -- (int)` 

    ```cpp
    iterator operator -- (int) {
        iterator old = *this;
        --(*this);
        return(old);
    }
    ```

    -  `old` is kept as the previous node, then we move that node `--(*this)` and return the previously pointed to `Node` the reason for this is because say `int x = 10;` `std::cout << x-- << '\n';` will return `10` even though the value of the variable `x` is actually `10` this is becasue we accessed the value before the operation of decrementation was performed. 































