#pragma once
#include <ostream>
#include <string>
#include "DynamicArray.h"
using namespace std;

struct ProblemType
{
    string code;
    int duration;
};

struct Ticket
{

    enum class Type
    {
        NORMAL,
        SPECIALISED,
        URGENT,
    };

    int id;
    Type type;
    int problemCode;
    int locationId;
    int requestTime, assignmentTime;
    int urgencyLevel;

    inline int duration(const DynamicArray<ProblemType> problems) const
    {
        return problems[problemCode].duration;
    }

    inline string location(const DynamicArray<string> &locations) const
    {
        return locations[locationId];
    }

    friend ostream &operator<<(ostream &out, const Ticket &ticket);
};

struct Cancellation
{
    int ticketId;
    int cancellationTime;
};

ostream &operator<<(ostream &out, Ticket::Type type);