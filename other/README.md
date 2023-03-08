# midterm

**contents**
1.  [scope](#scope)
2.  [plan](#plan)
3.  [exercises](#exercises)
4.  [questions given](#questions-given)

## scope
the scope of the midterm includes all materials covered by the posted slides, class notes, and textbook chapters 1 - 3 (3.1 - 3.5)

## plan
1.  programming a general overview
2.  algorithm analysis
3.  memorize the implementations of [vectors](../01-vectors) & [lists](../02-linked-list)
4.  module 0 [the fundamentals](../00-fundamentals)
5.  module 1 [vector](../01-vectors) and [list](../02-linked-list)

## exercises

### `printLots`
1.  you are given a linkedlist `L` and another linkedlist `P`, containing integers sorted in ascending order.  the operation `printList(L, P)` will print the elements in `L` that are in positions specified by `P`.  for instance if `P = 1, 3, 4, 6` the elements in positions `1, 3, 4, 6` in `L` are printed.  write th eprocedure `printLots(L, P)`.  you may use only public `stl` container operations.  what is the running time of your procedure?

    ```cpp
    void printLots(LinkedList<int> &L, LinkedList<int> &P) {
        
        LinkedList<int>::iterator L_itr = L.begin();
        LinkedList<int>::iterator P_itr = P.begin();
        int index = 0;
        
        while (L_iter != L.end() && P_itr != P.end()) {
            
            if (P_iter == index) {
                std::cout << *L_itr << " ";
                ++P_itr;
            }   
            ++L_itr;
            ++index;
        }
    }

    /*
     *  time complexity of the algorithm is O(n)
     *  
     *  because the list P is ordered, this means we will never be asked to
     *  print numbers that have been previously visited.  so we can complete
     *  the entire process with a single scan of both lists.
     *
     */
    ```

### `intersect`

2.  given two sorted arrays `L1` and `L1` write a procedure to compute `L1` $\cap$ `L2` using only the basic array operations

    ```cpp
    int i = 0;
    int j = 0;
    
    while (i < l1.size() && j < L2.size()) {
        if (l1[i] == l2[j]) {
            std::cout << l1[i];
            ++i;
            ++j;
        } else if (l1[i] < l2[j] {
            print l1[i];
            ++i;
        } else {
            ++j
        }
    }
    ```

### `union`

3.  given two sorted arrays `L1` and `L2`, write a procedure to compute `L1` $\cup$ `L2` using only the basic array operations

    ```cpp
    int i = 0;
    int j = 0;

    while (i < l1.size() && j < l2.size()) {
        if (l1[i] == l2[j]) {
            std::cout << l1[i];
            ++i;
            ++j;
        } else if (l1[i] < l2[j]) {
            std::cout << l1[i];
            ++i;
        } else {
            std::cout << l2[j];
            ++j;
        }
    }
    ```

### `vector`

```cpp
#ifndef __MYVECTOR_H__
#define __MYVECTOR_H__

#include <utility>
#include <vector>

template <typename T>
class Myvector {
    private:
        size_t theSize;
        size_t theCapacity;
        T *data;
    public:
        static const size_t SPARE_CAPACITY = 16;
        explicit MyVector(size_t initSize = 0) :
            theSize{initSize}, theCapacity{initSize + SPARE_CAPACITY} {
                data = new T[theCapacity];
        }
        MyVector(const MyVector &rhs) :
            theSize{rhs.theSize}, theCapacity{rhs.theCapacity} {
                data = nullptrl
                data = new T[theCapacity];
                for (int i = 0; i < theSize; ++i) {
                    data[i] = rhs.data[i];
                }
        }
        MyVector(MyVector &&rhs) :
            theSize{rhs.theSize}, theCapacity{rhs.theCapacity}, data{rhs.data} {
                rhs.data = nullptr;
                rhs.theSize = 0;
                rhs.theCapacity = 0;
        }
        MyVectoer(const std::vector<T> &rhs) :
            theSize{rhs.size()}, theCapacity{rhs.size() + SPARE_CAPACITY} {
                data = nullptr;
                data = new T[theCapacity];
                for (int i = 0; i < theSize; ++i) {
                    data[i] = rhs[i];
                }
        }
        ~MyVector() {
            delete [] data;
        }
        MyVector & operator = (const MyVector &rhs) {
            MyVector copy = rhs;
            std::swap(*this, copy);
            return(*this)
        }
        MyVector & operator = (MyVector &&rhs) {
            std::swap(theSize, rhs.theSize);
            std::swap(theCapacity, rhs.theCapacity);
            std::swap(data, rhs.data);
            rhs.data = nullptr;
            rhs.theSize = 0;
            rhs.theCapacity = 0;
            return(*this);
        }
        void resize(size_t newSize) {
            if (newSize > theCapacity) {
                reserve(newSize * 2);
            }
            theSize = newSize;
        }
        T& operator [] (size_t index) {
            return(data[index]);
        }
        const T& opeator [] (size_t index) const {
            return(data[index]);
        }
        bool empty() const {
            if (theSize == 0) {
                return(true);
            } else {
                return(false);
            }
        }
        size_t size() const {
            return(theSize);
        }
        size_t capacity() const {
            return(theCapacity);
        }
        void push_back(const T &x) {
            if (theSize == theCapacity) {
                reserve(2 * theCapacity + 1) {
            }
            data[theSize++] = x;
        }
        void push_back(T &&x) {
            if (theSize == theCapacity) {
                reserve(2 * theCapacity + 1);
            }
            data[theSize++] = std::move(x);
        }
        MyVector<T>& append(MyVector<T> &&rhs) {
            if (theSize + rhs.theSize > theCapacity) {
                reserve(theSize + rhs.theSize);
            } 
            for (int i = 0; i < rhs.theSize; ++i) {
                data[theSize + 1] = std::move(rhs.data[i]);
            }
            theSize += rhs.theSize;
            rhs.theSize = 0;
            return(*this);
        }
        void pop_back() {
            --theSize;
        }
        const T& back() const {
            return(data[theSize - 1]);
        }
        typedef T* iterator;
        typedef const T* const_iterator;
        iterator begin() {
            return(&data[0]);
        }
        const_iterator begin() const {
            return(&data[0]);
        }
        iterator end() {
            return(&data[size()]);
        }
        const_iterator end() const {
            return(&data[size()]);
        }
#endif
```

### `linkedlist`

```cpp



```

##  questions given

1.  give a brief description of the big-five in the context of classes in c++
2.  what is the worst-case time complexity of inserting into an unsorted array?
3.  consider a doubly linked list, on a 64 bit system what is the memory complexity of a regular (non head / tail) node containing integer
-  `int = 16 bits`
-  `node* next = 64 bits`
-  `node* prev = 64 bits`

4.  what are the advantages in using rvalue reference in c++ 
5.  implement the `reserve()` 

























