#pragma once
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
};

struct Cancellation
{
    int ticketId;
    int cancellationTime;
};