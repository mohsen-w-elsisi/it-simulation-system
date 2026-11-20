#ifndef CANCELLATIONQUEUE_H
#define CANCELLATIONQUEUE_H
#include "Queue.h"

class Cancellation {
private:
    int CT;
    int RID;
public:
    Cancellation(int ct, int rid) {
        CT = ct;
        RID = rid;
    }
    int getCT() const { return CT; }
    int getRID() const { return RID; }
};

class CancellationQueue : public Queue<Cancellation*> {
public:
    void print() const {
        Node<Cancellation*>* cur = front;
        while (cur != NULL) {
            cout << cur->data->getRID();
            if (cur->next != NULL)
                cout << ", ";
            cur = cur->next;
        }
    }
};

#endif
