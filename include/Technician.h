#pragma once
#include "Ticket.h"

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
    const Ticket &currentAssignment;

public:
    Technician(int id, Type type);

    bool isAssigned() const;
    void assign();
    const Ticket &finishAssignment();
    bool isDone(int currentTime) const;
};