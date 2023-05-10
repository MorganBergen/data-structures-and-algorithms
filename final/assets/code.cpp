#include <cstddef>
#include <iostream>

struct NodeType {
    int data;           // assuming only store integer type
    NodeType *next;     // pointer to the next element
};

class QueueList {
    public:
        QueueList() {
            head = tail = nullptr
            queue_size = 0;
        }
        ~QueueList();
        NodeType& top (void);
        void enqueue(const NodeType &d);
        void dequeue(void);
    private:
        NodeType *head;
        NodeType *tail;
        int queue_size;
};

NodeType& QueueList::top(void) {
    if (head == nullptr) {
        printf("queue is empty");
    } else {
        return *head;
    }
}

void QueueList::enqueue(const NodeType& d) {
    struct NodeType* nt = new NodeType;
    nt -> data = d.data;
    if (head == nullptr && tail == nullptr) {
        head = tail = nt;
        queue_size++;
        return;
    } 
    tail -> next = nt;
    tail = nt;
    queue_size++;
}

void Queue::dequeue(void) {
    if (head == nullptr) {
        printf("queue is empty")
        return;
    }
    NodeType* temp = head;
    head = head -> next;

    if (head == nullptr) {
        tail = nullptr;
    }
    queue_size--;
    delete(temp);
}

QueueList::~QueueList() {
    while (head != nullptr) {
        NodeType* temp = head;
        head = head -> next;
        delete temp;
    }
    tail = nullptr;
    queue_size = 0;
}
