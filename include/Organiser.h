#pragma once
#include "DynamicArray.h"
#include "Ticket.h"
#include "Technician.h"
#include "ITUnit.h"
#include "UserInterface.h"
#include "LinkedList.h"

class Organiser
{
    DynamicArray<Technician> technicians;
    DynamicArray<Ticket> tickets;
    DynamicArray<Cancellation> cancellations;
    DynamicArray<string> locations;
    DynamicArray<ProblemType> problems;

    LinkedList<Ticket *> completedTickets;
    LinkedList<Ticket *> cancelledTickets;

    ITUnit itUnit;
    UserInterface ui;

    int currentTIme = 0;

public:
    Organiser();

    void initialise();
    void run();

    void runTest();

private:
    void updateITUnit();
};