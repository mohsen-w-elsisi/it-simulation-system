#include <iostream>
#include <fstream>
#include "ConfigLoader.h"
using namespace std;

ostream &operator<<(ostream &out, Token::Type type)
{
    switch (type)
    {
    case Token::Type::LOCATIONS:
        return out << "LOCATIONS";
    case Token::Type::PROBLEM_CATEGORY:
        return out << "PROBLEM_CATEGORY";
    case Token::Type::TECHNICIANS:
        return out << "TECHNICIANS";
    case Token::Type::TICKET:
        return out << "TICKET";
    case Token::Type::CANCELLATION:
        return out << "CANCELLATION";
    }

    return out;
}

ConfigLoader::ConfigLoader(string fileName) : file(ifstream(fileName))
{
    if (!file.is_open())
        throw FILE_NOT_EXISTS;
}

AppConfig ConfigLoader::load()
{
    tokeniseConfig();
    parseTokens();
    return config;
}

void ConfigLoader::tokeniseConfig()
{
    string line;

    getline(file, line); // skip location count

    getline(file, line); // locations list
    tokens.pushBack({Token::Type::LOCATIONS, line});

    getline(file, line); // Problem count
    int problemCount = stoi(line);
    for (int i = 0; i < problemCount; i++)
    {
        getline(file, line); // problem definition
        tokens.pushBack({Token::Type::PROBLEM_CATEGORY, line});
    }

    getline(file, line); // technician defintion
    tokens.pushBack({Token::Type::TECHNICIANS, line});

    getline(file, line); // ticket count
    int ticketCount = stoi(line);
    for (int i = 0; i < ticketCount; i++)
    {
        getline(file, line); // ticket definition
        tokens.pushBack({Token::Type::TICKET, line});
    }

    getline(file, line); // cancellation count
    int cancelationCount = stoi(line);
    for (int i = 0; i < cancelationCount; i++)
    {
        getline(file, line); // cancellation definition
        tokens.pushBack({Token::Type::CANCELLATION, line});
    }
}

void ConfigLoader::parseTokens()
{
    for (int i = 0; i < tokens.length(); i++)
        parseToken(tokens[i]);
}

void ConfigLoader::parseToken(const Token &token)
{
    switch (token.type)
    {
    case Token::Type::LOCATIONS:
        parseLocations(token.content);
        break;

    case Token::Type::PROBLEM_CATEGORY:
        parseProblem(token.content);
        break;

    case Token::Type::TECHNICIANS:
        parseTechnicians(token.content);
        break;

    case Token::Type::TICKET:
        parseTicket(token.content);
        break;

    case Token::Type::CANCELLATION:
        parseCancellation(token.content);
        break;

    default:
        break;
    }
}

DynamicArray<string> splitSpaces(const string &text)
{
    DynamicArray<string> result;
    string currentWord;
    for (const char &c : text)
    {
        if (c == ' ' && !currentWord.empty())
        {
            result.pushBack(currentWord);
            currentWord = "";
        }
        else
        {
            currentWord += c;
        }
    }
    if (!currentWord.empty())
        result.pushBack(currentWord);
    return result;
}

void ConfigLoader::parseLocations(const string &locationsText)
{
    config.locations = std::move(splitSpaces(locationsText));
}

void ConfigLoader::parseProblem(const string &text)
{
    DynamicArray<string> args = splitSpaces(text);
    config.problems.pushBack({
        .code = args[0],
        .duration = stoi(args[1]),
    });
}

void ConfigLoader::parseTechnicians(const string &text)
{
    auto args = splitSpaces(text);
    config.stCount = stoi(args[0]);
    config.gtCount = stoi(args[1]);
}

void ConfigLoader::parseTicket(const string &text)
{
    auto args = splitSpaces(text);

    Ticket::Type type = args[0] == "NR"   ? Ticket::Type::NORMAL
                        : args[0] == "SR" ? Ticket::Type::SPECIALISED
                                          : Ticket::Type::URGENT;
    Ticket ticket = {
        .id = stoi(args[2]),
        .type = type,
        .problemCode = stoi(args[4]),
        .locationId = stoi(args[3]),
        .requestTime = stoi(args[1]),
        .assignmentTime = -1,
        .urgencyLevel = -1,
    };

    if (ticket.type == Ticket::Type::URGENT)
        ticket.urgencyLevel = stoi(args[5]);

    config.tickets.pushBack(ticket);
}

void ConfigLoader::parseCancellation(const string &text)
{
    auto args = splitSpaces(text);
    config.cancellations.pushBack({
        .ticketId = stoi(args[1]),
        .cancellationTime = stoi(args[0]),
    });
}
