#include <cassert>
#include "ConfigLoader.h"

int main()
{
    ConfigLoader loader("test_input.txt");
    AppConfig config = loader.load();

    assert(config.locations.length() == 3);
    assert(config.locations[0] == "CSAI");
    assert(config.locations[1] == "LAB1");
    assert(config.locations[2] == "ADMIN");

    assert(config.problems.length() == 3);
    assert(config.problems[0].code == "B");
    assert(config.problems[0].duration == 3);
    assert(config.problems[1].code == "B");
    assert(config.problems[1].duration == 4);
    assert(config.problems[2].code == "H");
    assert(config.problems[2].duration == 5);

    assert(config.gtCount == 2);
    assert(config.stCount == 1);

    assert(config.tickets.length() == 4);

    assert(config.tickets[0].type == Ticket::Type::NORMAL);
    assert(config.tickets[0].requestTime == 1);
    assert(config.tickets[0].id == 1);
    assert(config.tickets[0].locationId == 1);
    assert(config.tickets[0].problemCode == 1);

    assert(config.tickets[1].type == Ticket::Type::SPECIALISED);
    assert(config.tickets[1].requestTime == 1);
    assert(config.tickets[1].id == 2);
    assert(config.tickets[1].locationId == 2);
    assert(config.tickets[1].problemCode == 3);

    assert(config.tickets[2].type == Ticket::Type::URGENT);
    assert(config.tickets[2].requestTime == 1);
    assert(config.tickets[2].id == 3);
    assert(config.tickets[2].locationId == 3);
    assert(config.tickets[2].problemCode == 1);
    assert(config.tickets[2].urgencyLevel == 9);

    assert(config.tickets[3].type == Ticket::Type::NORMAL);
    assert(config.tickets[3].requestTime == 2);
    assert(config.tickets[3].id == 4);
    assert(config.tickets[3].locationId == 2);
    assert(config.tickets[3].problemCode == 1);

    assert(config.cancellations.length() == 1);
    assert(config.cancellations[0].ticketId == 4);
    assert(config.cancellations[0].cancellationTime == 3);
}