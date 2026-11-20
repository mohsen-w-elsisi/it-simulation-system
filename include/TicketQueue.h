#pragma once
#include "Queue.h"
#include "Ticket.h"

class TicketQueue : public Queue<Ticket *>
{
public:
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
