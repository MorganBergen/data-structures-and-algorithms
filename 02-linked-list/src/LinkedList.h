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
