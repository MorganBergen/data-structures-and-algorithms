#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include <iostream>
#include <algorithm>

template <typename T>
class LinkedList {
    private:
        struct Node {
            T data;
            Node *prev;
            Node *next;
            int counter;

            Node(const T &d = T(), Node *p = nullptr, Node *n = nullptr) :
                data{d},
                prev{p},
                next{n}
                { }
            
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

        class const_iterator {
            protected:
                Node *current;
                T& retrieve() const {
                    return (current -> data);
                }
                const_iterator(Node *p) : current{p} {}
                friend class LinkedList<T>;

            public:
                const_iterator() : current{nullptr} {}
                
                const T& operator * () const {
                    return(retrieve());
                }
                
                const_iterator& operator ++ () {
                    current = current -> next;
                    return (*this);
                }

                const_iterator operator ++ (int) {
                    const_iterator old = *this;
                    ++(*this);
                    return (old);
                }
                
                const_iterator& operator -- () {
                    const_iterator old = *this;
                    --(*this);
                    return(old);
                }

                bool operator == (const const_iterator &rhs) const {
                    return (current == rhs.current);
                }

                bool operator != (const const_iterator &rhs) const {
                    return !(*this == rhs);
                }
        };


    public:
        LinkedList() {
            init();
        }

};

#endif 























