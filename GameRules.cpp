#include "GameRules.h"

void GameRules::сreateTransport() {
    if (typeGame == TypeGame::All || typeGame == TypeGame::Air)
    {
        transports.push_back(new Air("Ковёр-самолёт", 10, {{0, 0}, {1000, 3}, {5000, 10}, {10000, 5}}));
        transports.push_back(new Air("Орёл", 8, {{0, 6}}));
        transports.push_back(new Air("Метла", 20, {{1000, -1}}));
    }
    if (typeGame == TypeGame::All || typeGame == TypeGame::Lend)
    {
        transports.push_back(new Lend("Верблюд", 10, 30, {5, 8}));
        transports.push_back(new Lend("Верблюд-быстроход", 40, 10, {5, 6.5, 8}));
        transports.push_back(new Lend("Кентавр", 15, 8, {2}));
        transports.push_back(new Lend("Ботинки-вездеходы", 6, 60, {10, 5}));
    }
}

std::multimap<int, std::string> GameRules::getResult()
{
    return resultMap;
}

void GameRules::startGame()
{
    for (auto* obj : transports)
    {
        if (obj->getActivation())
        {
            resultMap.insert({obj->getResult(lengthTrack), obj->getName()});
        }
    }
}

std::vector<StringBoolean> GameRules::getTransportsName()
{
    std::vector<StringBoolean> stringInt;
    for (auto* obj : transports)
    {
        stringInt.push_back(StringBoolean(obj->getName(), obj->getActivation()));
        //map.insert({obj->getName(), obj->getActivation()});
    }
    return stringInt;
}

bool GameRules::updateTransports(int index)
{
    if (index >= 0 && index < transports.size())
    {
        transports[index]->setActivation();
        return true;
    }
    return false;
}