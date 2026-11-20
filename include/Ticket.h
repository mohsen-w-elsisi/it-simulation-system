#pragma once
#include <string>
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
};

struct Cancellation
{
    int ticketId;
    int cancellationTime;
};