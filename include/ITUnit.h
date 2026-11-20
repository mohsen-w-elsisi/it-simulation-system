#pragma once

class ITUnit
{
    DynamicArray<Technician> &technicians;
    // all ticket queues here

public:
    ITUnit(DynamicArray<Technician> &technicians);

    void queueTicket(Ticket *ticket);
    void cancelTicket(int ticketId);
    void assignTicketsToTechnicians();
}