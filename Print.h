#pragma once

#include <algorithm>
#include <iomanip>
#include <iostream>

#include "GameRules.h"
#include "MacroInput.h"

void updateTransportsActivation(std::vector<StringBoolean>& nameIntTransports, GameRules& gameRules);
bool printInfoTransports(const int& typeGame, const int& lengthTrack, std::vector<StringBoolean>& nameIntTransports,
               const std::vector<std::string>& typeGameStr, GameRules& gameRules);
void printInfoTypeGameStr(std::vector<std::string>& typeGameStr);
void setDefoltTypeGameStr(std::vector<std::string>& typeGameStr);
void printResult(GameRules& gameRules);
void printMain();
bool printRestart();