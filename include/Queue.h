#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;

template <class T>
class Node {
public:
    T data;
    int priority;
    Node<T>* next;
    Node(T d, int p) {
        data = d;
        priority = p;
        next = NULL;
    }
};

template <class T>
class Queue {
protected:
    Node<T>* front;
    Node<T>* rear;
    int count;

private:
    Queue(const Queue& q);
    Queue& operator=(const Queue& q);

public:
    Queue() {
        front = NULL;
        rear = NULL;
        count = 0;
    }

    virtual ~Queue() {
        T temp;
        while (dequeue(temp)) { }
    }

    bool enqueue(T item) {
        Node<T>* n = new Node<T>(item, 0);
        if (rear == NULL) {
            front = n;
            rear = n;
        } else {
            rear->next = n;
            rear = n;
        }
        count++;
        return true;
    }

    bool dequeue(T& item) {
        if (front == NULL)
            return false;
        Node<T>* n = front;
        item = n->data;
        front = front->next;
        if (front == NULL)
            rear = NULL;
        delete n;
        count--;
        return true;
    }

    bool peek(T& item) const {
        if (front == NULL)
            return false;
        item = front->data;
        return true;
    }

    bool getAt(int index, T& item) const {
        if (index < 0 || index >= count)
            return false;
        Node<T>* cur = front;
        for (int i = 0; i < index; i++)
            cur = cur->next;
        item = cur->data;
        return true;
    }

    bool remove(T item) {
        Node<T>* prev = NULL;
        Node<T>* cur = front;
        while (cur != NULL && !(cur->data == item)) {
            prev = cur;
            cur = cur->next;
        }
        if (cur == NULL)
            return false;
        if (prev == NULL)
            front = cur->next;
        else
            prev->next = cur->next;
        if (cur == rear)
            rear = prev;
        delete cur;
        count--;
        return true;
    }

    bool isEmpty() const { return count == 0; }
    int getCount() const { return count; }

    void print() const {
        Node<T>* cur = front;
        while (cur != NULL) {
            cout << cur->data;
            if (cur->next != NULL)
                cout << ", ";
            cur = cur->next;
        }
    }
};

#endif
