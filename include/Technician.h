#pragma once
#include <ostream>
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

    int getId() const;
    Type getType() const;
    const Ticket *getCurrentAssignment() const;

    bool isAssigned() const;
    void assign(const Ticket *ticket);
    const Ticket *finishAssignment();
    bool isDone(int currentTime, DynamicArray<ProblemType> problems) const;

    friend std::ostream &operator<<(std::ostream &out, const Technician &technician);
};

std::ostream &operator<<(std::ostream &out, Technician::Type type);