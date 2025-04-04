#pragma once

#include "Transport.h"
#include "Air.h"
#include "Lend.h"
#include "TypeGame.h"
#include "StringInt.h"

#include <string>
#include <vector>
#include <map>

class GameRules
{
  private:
    TypeGame typeGame{};
    int lengthTrack{};
    std::vector<Transport*> transports;
    std::multimap<int, std::string> resultMap;

  public:
    GameRules(TypeGame typeGame, int lengthTrack) : typeGame(typeGame), lengthTrack(lengthTrack)
    {
        ñreateTransport();
    }

    ~GameRules()
    {
        for (auto* obj : transports)
        {
            delete obj;
        }
    }

    std::vector<StringBool> getTransportsName();
    void startGame();
    std::multimap<int, std::string> getResult();
    bool updateTransports(int index);

  private:
    void ñreateTransport();
};
