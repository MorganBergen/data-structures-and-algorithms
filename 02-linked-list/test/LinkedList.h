#ifndef __LINKEDLIST__ 
#define __LINKEDLIST__

#include <iostream>
#include <string>
#include <algorithm>

template <typename DataType>
class LinkedList {
    private:
        struct Node {
            DataType data;
            Node* prev;
            Node* next
            int counter;

            Node(const DataType& d = DataType{}, Node* p = nullptr, Node* n = nullptr) {
                
                data = d;
                prev = p;
                next = n;

            }

        };

        int theSize;
        Node* head;
        Node* tail;

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
            init();
            std::cout << "data = " << head.data << std::endl;
        }

};

#endif // __LINKEDLIST__

