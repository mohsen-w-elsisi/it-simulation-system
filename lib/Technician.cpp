#include "Technician.h"

Technician::Technician() : id(-1), type(Type::GENERAL), currentAssignment(nullptr) {}
Technician::Technician(int id, Type type) : id(id), type(type), currentAssignment(nullptr) {}

bool Technician::isAssigned() const
{
    return currentAssignment != nullptr;
}

void Technician::assign(const Ticket *ticket)
{
    if (isAssigned())
        throw "Assigning task to busy technician";
    currentAssignment = ticket;
}

const Ticket *Technician::finishAssignment()
{
    auto temp = currentAssignment;
    currentAssignment = nullptr;
    return temp;
}

bool Technician::isDone(int currentTime, DynamicArray<ProblemType> problems) const
{
    int timeSinceAssignment = currentTime - currentAssignment->assignmentTime;
    return timeSinceAssignment >= currentAssignment->duration(problems);
}
