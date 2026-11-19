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

    default:
        break;
    }
}

void ConfigLoader::parseLocations(const string &locationsText)
{
    string currentLocation;
    for (const char &c : locationsText)
    {
        if (c == ' ' || c == '\n')
        {
            config.locations.pushBack(currentLocation);
            currentLocation = "";
        }
        else
        {
            currentLocation += c;
        }
    }
}
