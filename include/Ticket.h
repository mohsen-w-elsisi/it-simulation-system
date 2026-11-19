#pragma once
#include <string>
using namespace std;

enum class TicketType
{
    NORMAL,
    SPECIALISED,
    URGENT,
};

struct ProblemType
{
    int code;
    string name;
    int duration;
};

struct Ticket
{
    int id;
    TicketType type;
    const ProblemType &problem;
    const string &location;
    int requestTime, assignmentTime;
    int urgencyLevel;

    Ticket(int id, TicketType type, const ProblemType &problem, const string &location, int requestTime)
        : id(id), type(type), problem(problem), location(location),
          requestTime(requestTime), assignmentTime(-1), urgencyLevel(0) {}

    Ticket(int id, TicketType type, const ProblemType &problem, const string &location, int requestTime,
           int urgencyLevel)
        : id(id), type(type), problem(problem), location(location),
          requestTime(requestTime), assignmentTime(-1), urgencyLevel(urgencyLevel) {}
};