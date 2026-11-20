#include <random>
#include "Organiser.h"
#include "ConfigLoader.h"
#include "Ticket.h"
#include "ArchivedTicket.h"

Organiser::Organiser(string configFileName) : itUnit(technicians)
{
    AppConfig config = ConfigLoader(configFileName).load();

    for (int i = 0; i < config.gtCount; i++)
        technicians.pushBack(Technician(i, Technician::Type::GENERAL));
    for (int i = config.gtCount; i < config.stCount + config.gtCount; i++)
        technicians.pushBack(Technician(i, Technician::Type::SPECIALISED));

    locations = std::move(config.locations);
    problems = std::move(config.problems);
    tickets = std::move(config.tickets);
    cancellations = std::move(config.cancellations);
}

void Organiser::run()
{
    int num;
    if (num >= 10 && num < 20)
    {
        for (int i = 0; i < tickets.length(); i++)
        {
            if (tickets[i].type == Ticket::Type::URGENT)
            {
                if (completedTickets.contains(&tickets[i]))
                {
                    continue;
                }
                completedTickets.pushBack(&tickets[i]);
                break;
            }
        }
    }
    else if (num >= 20 && num < 30)
    {
        for (int i = 0; i < tickets.length(); i++)
        {
            if (tickets[i].type == Ticket::Type::SPECIALISED)
            {
                if (completedTickets.contains(&tickets[i]))
                {
                    continue;
                }
                completedTickets.pushBack(&tickets[i]);
                break;
            }
        }
    }

    else if (num >= 30 && num < 45)
    {
        for (int i = 0; i < tickets.length(); i++)
        {
            if (tickets[i].type == Ticket::Type::NORMAL)
            {
                if (completedTickets.contains(&tickets[i]))
                {
                    continue;
                }
                completedTickets.pushBack(&tickets[i]);
                break;
            }
        }
    }

    else if (num >= 45 && num < 50)
    {
        for (int i = 0; i < tickets.length(); i++)
        {
            if (tickets[i].type == Ticket::Type::NORMAL)
            {
                if (cancelledTickets.contains(&tickets[i]))
                {
                    continue;
                }
                cancelledTickets.pushBack(&tickets[i]);
            }
        }
    }

    else if (num >= 50 && num < 60)
    {
        }

    else if (num >= 60 && num < 70)
    {
    }

    else if (num >= 70 && num < 85)
    {
    }
}

Ticket *gettype(DynamicArray<Ticket> &tickets, Ticket::Type type)
{
}
