#include <random>
#include <string>
#include "Organiser.h"
#include "ConfigLoader.h"
#include "Ticket.h"
using namespace std;

Organiser::Organiser() : itUnit(technicians) {}

void Organiser::initialise()
{
    string configFileName = ui.askConfigFileName();
    AppConfig config = ConfigLoader(configFileName).load();

    for (int i = 0; i < config.gtCount; i++)
        technicians.pushBack(Technician(i, Technician::Type::GENERAL));
    for (int i = config.gtCount; i < config.stCount + config.gtCount; i++)
        technicians.pushBack(Technician(i, Technician::Type::SPECIALISED));

    locations = std::move(config.locations);
    problems = std::move(config.problems);
    tickets = std::move(config.tickets);
    cancellations = std::move(config.cancellations);

    ui.askOutputMode();

    srand(time(NULL));
}

void Organiser::run()
{
    while (completedTickets.length() + cancelledTickets.length() < tickets.length())
    {
        currentTIme++;
        runTest();

        DynamicArray<Ticket *> emptyArray;

        for (int i = 0; i < tickets.length(); i++)
        {
            if (!completedTickets.contains(&tickets[i]) && !cancelledTickets.contains(&tickets[i]))
            {
                emptyArray.pushBack(&tickets[i]);
            }
        }

        ui.displaySystemStatus({
            .currentTime = currentTIme,
            .schedualedTickets = &emptyArray,
            .completedTickets = &completedTickets,
            .cancelledTickets = &cancelledTickets,
            .technicians = &technicians,
            .problems = &problems,
            .locations = &locations,
        });
    }
}

void Organiser::runTest()
{
    int num = rand() % 100 + 1;

    if (num >= 10 && num < 20)
    {
        for (int i = 0; i < tickets.length(); i++)
        {
            if (tickets[i].type == Ticket::Type::URGENT)
            {
                if (completedTickets.contains(&tickets[i]) || cancelledTickets.contains(&tickets[i]))
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
                if (completedTickets.contains(&tickets[i]) || cancelledTickets.contains(&tickets[i]))
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
                if (completedTickets.contains(&tickets[i]) || cancelledTickets.contains(&tickets[i]))
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
            if (tickets[i].type == Ticket::Type::NORMAL && !completedTickets.contains(&tickets[i]))
            {
                if (cancelledTickets.contains(&tickets[i]))
                {
                    continue;
                }
                cancelledTickets.pushBack(&tickets[i]);
                break;
            }
        }
    }

    else if (num >= 50 && num < 60)
    {
        for (int i = 0; i < technicians.length(); i++)
        {
            if (technicians[i].getType() == Technician::Type::SPECIALISED && !technicians[i].isAssigned())
            {
                technicians[i].assign(&tickets[0]); // to assign the first ticket?? yes!
                break;
            }
        }
    }

    else if (num >= 60 && num < 70)
    {
        for (int i = 0; i < technicians.length(); i++)
        {
            if (technicians[i].getType() == Technician::Type::GENERAL && !technicians[i].isAssigned())
            {
                technicians[i].assign(&tickets[0]);
            }
            break;
        }
    }

    else if (num >= 70 && num < 85)
    {
        for (int i = 0; i < technicians.length(); i++)
        {
            if (technicians[i].isAssigned())
            {
                technicians[i].finishAssignment();
                break;
            }
        }
    }
}