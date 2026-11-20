#ifndef TICKETQUEUE_H
#define TICKETQUEUE_H
#include "Queue.h"
#include "Ticket.h"

class TicketQueue : public Queue<Ticket*> {
public:
    bool removeByID(int id) {
        Node<Ticket*>* cur = front;
        while (cur != NULL) {
            if (cur->data->getID() == id)
                return remove(cur->data);
            cur = cur->next;
        }
        return false;
    }

    void print() const {
        Node<Ticket*>* cur = front;
        while (cur != NULL) {
            cout << cur->data->getID();
            if (cur->next != NULL)
                cout << ", ";
            cur = cur->next;
        }
    }
};

#endif
