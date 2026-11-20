#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include "Queue.h"

template <class T>
class PriorityQueue : public Queue<T> {
public:
    bool enqueue(T item, int pr) {
        Node<T>* n = new Node<T>(item, pr);

        if (this->front == NULL || this->front->priority < pr) {
            n->next = this->front;
            this->front = n;
            if (this->rear == NULL)
                this->rear = n;
        } else {
            Node<T>* cur = this->front;
            while (cur->next != NULL && cur->next->priority >= pr)
                cur = cur->next;
            n->next = cur->next;
            cur->next = n;
            if (n->next == NULL)
                this->rear = n;
        }
        this->count++;
        return true;
    }
};

#endif
