#include <string>
#include <iostream>
#include "UserInterface.h"
using namespace std;

UserInterface::UserInterface() {}

UserInterface::OutputMode UserInterface::askOutputMode()
{
    string userResponse = "";

    while (userResponse != "0" && userResponse != "1")
    {
        cout << "Select output mode (interactive [0], silent [1]): ";
        cin >> userResponse;
    }

    outputMode = userResponse == "0" ? OutputMode::INTERACTIVE : OutputMode::SILENT;

    return outputMode;
}

string UserInterface::askConfigFileName()
{
    string configFileName;
    cout << "Enter config file name: ";
    cin >> configFileName;
    return configFileName;
}

void UserInterface::displaySystemStatus(const SystemStatusInfo &info)
{
    if (outputMode == OutputMode::SILENT)
        return;

    sysInfo = std::move(info);

    cout << "=============== System Status: =====================" << endl;
    cout << "Current Time: " << sysInfo.currentTime << endl
         << endl;

    displaySchedualedTickets();
    displayTechnicians();
    displayCompletedTickets();
    waitforEnter();

    cout << endl;
}

void UserInterface::waitforEnter()
{
    cin.get();
}

void printTicketInfo(const Ticket &ticket, const DynamicArray<ProblemType> *problems, const DynamicArray<string> *locations);

void UserInterface::displaySchedualedTickets()
{
    cout << "Schedualed Tickets:" << endl;
    for (int i = 0; i < sysInfo.schedualedTickets->length(); i++)
    {
        const Ticket *ticket = (*sysInfo.schedualedTickets)[i];
        printTicketInfo(*ticket, sysInfo.problems, sysInfo.locations);
    }

    cout << endl;
}

void UserInterface::displayTechnicians()
{
    displayFreeTechnicians();
    displayBusyTechnicians();
}

void UserInterface::displayFreeTechnicians()
{
    int freeGTCount = 0, freeSTCount = 0;
    for (int i = 0; i < sysInfo.technicians->length(); i++)
    {
        const Technician &tech = (*sysInfo.technicians)[i];
        if (tech.isAssigned())
            continue;
        if (tech.getType() == Technician::Type::GENERAL)
            freeGTCount++;
        else if (tech.getType() == Technician::Type::SPECIALISED)
            freeSTCount++;
    }
    cout << "Free Technicians: " << endl;
    cout << "    General: " << freeGTCount << endl;
    cout << "    Specialised: " << freeSTCount << endl;
    cout << endl;
}

void UserInterface::displayBusyTechnicians()
{
    cout << "Busy Technicians: " << endl;
    for (int i = 0; i < sysInfo.technicians->length(); i++)
    {
        const Technician &tech = (*sysInfo.technicians)[i];
        if (!tech.isAssigned())
            continue;
        cout << tech << endl;
        cout << "    ";
        printTicketInfo(*tech.getCurrentAssignment(), sysInfo.problems, sysInfo.locations);
    }
    cout << endl;
}

void UserInterface::displayCompletedTickets()
{
    cout << "Completed Tickets: ";
    for (int i = 0; i < sysInfo.completedTickets->length(); i++)
    {
        const Ticket *ticket = (*sysInfo.completedTickets)[i];
        cout << " " << ticket->id << ",";
    }
    cout << endl;

    cout << "Cancelled Tickets: ";
    for (int i = 0; i < sysInfo.cancelledTickets->length(); i++)
    {
        const Ticket *ticket = (*sysInfo.cancelledTickets)[i];
        cout << " " << ticket->id << ",";
    }
    cout << endl;
}

void printTicketInfo(const Ticket &ticket, const DynamicArray<ProblemType> *problems, const DynamicArray<string> *locations)
{
    cout << "Ticket ID: " << ticket.id << endl;
    cout << "    Location: " << (*locations)[ticket.locationId] << endl;
    cout << "    Problem: " << (*problems)[ticket.problemCode].code << endl;
}

std::ostream &operator<<(std::ostream &out, const Technician &technician)
{
    out << "Technician ID: " << technician.id
        << " (Type: "
        << technician.getType()
        << ")";
    return out;
}

ostream &operator<<(ostream &out, Ticket::Type type)
{
    switch (type)
    {
    case Ticket::Type::NORMAL:
        return out << "Normal";
    case Ticket::Type::SPECIALISED:
        return out << "Specialised";
    case Ticket::Type::URGENT:
        return out << "Urgent";
    }
    return out;
}

ostream &operator<<(ostream &out, const Ticket &ticket)
{
    out << "Ticket ID: " << ticket.id << endl;
    out << "    Location: " << ticket.locationId << endl;
    out << "    Problem: " << ticket.problemCode << endl;
    return out;
}

ostream &operator<<(ostream &out, Technician::Type type)
{
    switch (type)
    {
    case Technician::Type::GENERAL:
        return out << "General";
    case Technician::Type::SPECIALISED:
        return out << "Specialised";
    }
    return out;
}
