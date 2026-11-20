#include "ITUnit.h"

ITUnit::ITUnit(DynamicArray<Technician> &technicians) : technicians(technicians)
{
}

void ITUnit::queueTicket(Ticket *ticket)
{
    if (ticket->type == Ticket::Type::NORMAL)
        normalTickets.enqueue(ticket);
    else if (ticket->type == Ticket::Type::SPECIALISED)
        specialisedTickets.enqueue(ticket);
    else if (ticket->type == Ticket::Type::URGENT)
        urgentTickets.enqueue(ticket);
}

void ITUnit::cancelTicket(int ticketId)
{
    if (normalTickets.removeByID(ticketId))
        return;
    if (specialisedTickets.removeByID(ticketId))
        return;
    if (urgentTickets.removeByID(ticketId))
        return;
}

void ITUnit::assignTicketsToTechnicians()
{
    // Yousuf's code goes here
}
