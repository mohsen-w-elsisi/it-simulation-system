#pragma once
#include "DynamicArray.h"
#include "Technician.h"
#include "Ticket.h"
#include "TicketQueue.h"
#include "UrgentRequestsQueue.h"

class ITUnit
{
    DynamicArray<Technician> &technicians;
    TicketQueue normalTickets;
    TicketQueue specialisedTickets;
    UrgentRequestsQueue urgentTickets;

public:
    ITUnit(DynamicArray<Technician> &technicians);

    void queueTicket(Ticket *ticket);
    void cancelTicket(int ticketId);
    void assignTicketsToTechnicians();
};