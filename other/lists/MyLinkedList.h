#ifndef _MY_LINKEDLIST_H_
#define _MY_LINKEDLIST_H_

#include <algorithm>
#include <iostream>

template <typename T>
class MyLinkedList {
  private:
    
    struct Node {
        T  data;
        Node   *prev;
        Node   *next;
        
        Node(const T &d = T{ }, Node *p = nullptr, Node *n = nullptr) : 
        data{d}, 
        prev{p}, 
        next{n} 
        { }

        Node(T&& d, Node* p = nullptr, Node* n = nullptr) : 
        data{std::move(d)}, 
        prev{p}, 
        next{n} 
        { }
    };

    int theSize;
    Node *head;
    Node *tail;

    void init( ) {
        theSize = 0;
        head = new Node;
        tail = new Node;
        head -> next = tail;
        tail -> prev = head;
        return;
    }

  public:

    class const_iterator { 
      protected:
        Node *current;
        T& retrieve() const { 
            return current -> data; 
        }
        const_iterator(Node *p) : current{p} { }
        
        friend class MyLinkedList<T>;

      public:
        const_iterator() : current{nullptr} { }

        const T& operator* () const {
            return retrieve();
        }
        
        const_iterator& operator++ () {
            current = current -> next;
            return (*this);
        }
	
        const_iterator operator++ ( int ) {
            const_iterator old = *this;
            ++(*this);
            return (old);
        }

        const_iterator& operator-- () {
            current = current -> prev;
            return (*this);
        }

        const_iterator operator-- (int) {
            const_iterator old = *this;
            --(*this);
            return (old);
        }

        bool operator== (const const_iterator& rhs) const {
            return current == rhs.current;
        }
        
        bool operator!= (const const_iterator & rhs) const {
            return !(*this == rhs);
        }
    };

    class iterator : public const_iterator {
      protected:
        iterator(Node *p) : 
        const_iterator{p} { }
        
        friend class MyLinkedList<T>;
      
      public:

        iterator() { }

        T& operator* () {
            return const_iterator::retrieve();
        }
        
        const T& operator* () const {
            return const_iterator::operator*();
        }

        iterator & operator++ () {
            this -> current = this -> current -> next;
            return *this;
        }

        iterator operator++ (int) {
            iterator old = *this;
            ++(*this);
            return (old);
        }

        iterator operator-- () {
            this -> current = this -> current -> prev;
            return *this;
        }
        
        iterator operator-- (int) {
            iterator old = *this;
            --(*this);
            return (old);
        }
    };

  public:
    MyLinkedList() { 
        init(); 
    }
  
    MyLinkedList(const MyLinkedList& rhs) {
        init();
        for (auto & x : rhs) {
            push_back(x);
        }
    }

    MyLinkedList (MyLinkedList&& rhs) :
    theSize(rhs.theSize),
    head(rhs.head),
    tail(rhs.tail) {
        rhs.theSize = 0;
        rhs.head = nullptr;
        rhs.tail = nullptr;
    }

    ~MyLinkedList() {
        clear();
        delete head;
        delete tail;
    }

    MyLinkedList & operator= (const MyLinkedList& rhs) {
        MyLinkedList copy = rhs;
        std::swap (*this, copy);
        return (*this);
    }

    MyLinkedList & operator= (MyLinkedList && rhs) {
        std::swap(theSize, rhs.theSize);
        std::swap(head, rhs.head);
        std::swap(tail, rhs.tail);
        return (*this);
    }

    iterator begin() {
        return {head -> next};
    }

    const_iterator begin() const {
        return {head -> next};
    }
  
    iterator end() {
        return {tail};
    }

    const_iterator end() const {
        return {tail};
    }
  
    int size() const {
        return theSize;
    }

    bool empty( ) const { 
        return (size() == 0);
    }
	
    void clear( ) {
        while (!empty()) {
            pop_front();
        }
    }

    T& front() {
        return *begin();
    }
	
    const T& front() const {
        return *begin();
    }

    T& back() {
        return *--end();
    }

    const T& back() const {
        return *--end();
    }

    iterator insert(iterator itr, const T& x) {
        Node *p = itr.current;
        theSize++;
        return {p->prev = p->prev->next = new Node{x, p->prev, p}};
    }

    iterator insert(iterator itr, T&& x) {
        Node *p = itr.current;
        theSize++;
        return {p->prev = p->prev->next = new Node{std::move(x), p->prev, p}};
    }

    iterator erase(iterator itr) {
        Node *p = itr.current;
        iterator retVal{p -> next};
        p -> prev -> next = p -> next;
        p -> next -> prev = p -> prev;
        delete p;
        theSize--;
        return retVal;
    }

    iterator erase(iterator from, iterator to) {
        for (iterator itr = from; itr != to;)
            itr = erase(itr);
        return to;
    }

    void push_front(const T& x) {
        insert(begin(), x);
    }
  
    void push_front(T&& x) {
        insert(begin(), std::move(x));
    }
    
    void push_back(const T& x) {
        insert(end(), x);
    }
    
    void push_back(T&& x) {
        insert(end(), std::move(x));
    }
    
    void pop_front() {
        erase(begin());
    }
    
    void pop_back( ) {
		erase(--end());
    }
    
    void reverseList() {
        Node *current = head;
        MyLinkedList temp;
        for (auto i = begin(); i != end(); ++i) {
            temp.push_front(*i);
        }
        std::swap(head, temp.head);
        std::swap(tail, temp.tail);
        std::swap(theSize, temp.theSize);
    }
    
    MyLinkedList<T>& appendList(MyLinkedList<T>&& rlist) {
        
        for (iterator itr = rlist.begin(); itr != rlist.end(); itr++) {
            push_back(itr.current -> data);
        }
        return (*this);
         
    }
	
    bool swapAdjElements(iterator& itr) {
        
        if ((itr == end()) || (itr == --end()))
            return (false);
        std::swap (itr.current -> data, itr.current -> next -> data);
            return (true);

    }
};

#endif // __MYLIST_H__