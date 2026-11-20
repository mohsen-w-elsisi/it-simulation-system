#include <cassert>

#include "ITUnit.h"

int main()
{
    DynamicArray<Technician> technicians;
    technicians.pushBack(Technician(1, Technician::Type::GENERAL));
    technicians.pushBack(Technician(2, Technician::Type::SPECIALISED));

    ITUnit unit(technicians);

    Ticket normal{101, Ticket::Type::NORMAL, 0, 1, 0, 0, 1};
    Ticket specialised{202, Ticket::Type::SPECIALISED, 1, 2, 0, 0, 2};
    Ticket urgent{303, Ticket::Type::URGENT, 2, 3, 0, 0, 5};

    unit.queueTicket(&normal);
    unit.queueTicket(&specialised);
    unit.queueTicket(&urgent);

    unit.cancelTicket(normal.id);
    unit.cancelTicket(specialised.id);
    unit.cancelTicket(urgent.id);

    // Cancelling an unknown ticket and cancelling a ticket twice must be safe.
    unit.cancelTicket(-1);
    unit.cancelTicket(normal.id);

    // unit.assignTicketsToTechnicians();
    // assert(!technicians[0].isAssigned());
    // assert(!technicians[1].isAssigned());
}