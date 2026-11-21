#ifndef CANCELLATIONQUEUE_H
#define CANCELLATIONQUEUE_H
#include "Queue.h"
#include "Ticket.h"

class CancellationQueue : public Queue<Cancellation *>
{
public:
    void print() const
    {
        Node<Cancellation *> *cur = front;
        while (cur != NULL)
        {
            cout << cur->data->ticketId;
            if (cur->next != NULL)
                cout << ", ";
            cur = cur->next;
        }
    }
};

#endif
