#ifndef URGENTREQUESTSQUEUE_H
#define URGENTREQUESTSQUEUE_H
#include "PriorityQueue.h"
#include "Ticket.h"

class UrgentRequestsQueue : public PriorityQueue<Ticket *>
{
public:
    bool enqueue(Ticket *t)
    {
        return PriorityQueue<Ticket *>::enqueue(t, t->urgencyLevel);
    }

    bool removeByID(int id)
    {
        Node<Ticket *> *cur = front;
        while (cur != NULL)
        {
            if (cur->data->id == id)
                return remove(cur->data);
            cur = cur->next;
        }
        return false;
    }

    void print() const
    {
        Node<Ticket *> *cur = front;
        while (cur != NULL)
        {
            cout << cur->data->id;
            if (cur->next != NULL)
                cout << ", ";
            cur = cur->next;
        }
    }
};

#endif
