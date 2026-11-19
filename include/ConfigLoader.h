#pragma once
#include <string>
#include <fstream>
#include "DynamicArray.h"
#include "Ticket.h"
using namespace std;

#define FILE_NOT_EXISTS 1

struct AppConfig
{
    int gtCount;
    int stCount;
    DynamicArray<string> locations;
    DynamicArray<string> problemCategories;
    DynamicArray<int> problemDurations;
    DynamicArray<Ticket> tickets;
};

struct Token
{
    enum class Type
    {
        LOCATIONS,
        PROBLEM_CATEGORY,
        TECHNICIANS,
        TICKET,
        CANCELLATION,
    };
    Type type;
    string content;
};

class ConfigLoader
{
    ifstream file;

    DynamicArray<Token> tokens;
    AppConfig config;

public:
    ConfigLoader(string fileName);

    AppConfig load();

private:
    void tokeniseConfig();
    void parseTokens();
    void parseToken(const Token &token);

    void parseLocations(const string &text);
    void parseProblem(const string &text);
    void parseTicket(const string &text);
    void parseTechnicians(const string &text);
    void parseCancellations(const string &text);
};
