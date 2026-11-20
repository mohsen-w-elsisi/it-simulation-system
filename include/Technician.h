#pragma once
#include "Ticket.h"
#include "DynamicArray.h"

class Technician
{
public:
    enum class Type
    {
        GENERAL,
        SPECIALISED,
    };

private:
    int id;
    Type type;
    const Ticket *currentAssignment;

public:
    Technician();
    Technician(int id, Type type);

    bool isAssigned() const;
    void assign(const Ticket *ticket);
    const Ticket *finishAssignment();
    bool isDone(int currentTime, DynamicArray<ProblemType> problems) const;
};