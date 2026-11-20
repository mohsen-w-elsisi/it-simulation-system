#pragma once
#include "Ticket.h"

struct ArchivedTicket
{
    enum class Status
    {
        COMPLETED,
        CANCELLED,
    };
    const Ticket *ticket;
    Status status;

    ArchivedTicket(const Ticket *ticket, Status status) : ticket(ticket), status(status) {}
};
