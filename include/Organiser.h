#pragma once
#include "DynamicArray.h"
#include "Ticket.h"
#include "Technician.h"
#include "ITUnit.h"

class Organiser
{
    DynamicArray<Technician> technicians;
    DynamicArray<Ticket> tickets;
    DynamicArray<Cancellation> cancellations;
    DynamicArray<string> locations;
    DynamicArray<ProblemType> problems;

    LinkedList<Ticket *> archive;

    ITUnit itUnit;
    UserInterface ui;

    int currentTIme = 0;

public:
    Organiser(string configFileName);

    void run();

private:
    void updateITUnit();
}