﻿#include <algorithm>
#include <iomanip>
#include <iostream>

#include "GameRules.h"

#define INPUT_INT(x)                                                                                                   \
    while (true)                                                                                                       \
    {                                                                                                                  \
        if (std::cin >> x)                                                                                             \
            break;                                                                                                     \
        else                                                                                                           \
        {                                                                                                              \
            std::cout << "Ошибка! Введите число: ";                                                                    \
            std::cin.clear();                                                                                          \
            std::cin.ignore(10000, '\n');                                                                              \
        }                                                                                                              \
    }

void updateMapTransports(std::vector<StringBool>& nameIntTransports, GameRules& gameRules)
{
    nameIntTransports = gameRules.getTransportsName();
}

bool printInfo(const int& typeGame, const int& lengthTrack, std::vector<StringBool>& nameIntTransports,
               const std::vector<std::string>& typeGameStr, GameRules& gameRules)
{
    system("cls");
    updateMapTransports(nameIntTransports, gameRules);
        
    int input{};
    int index{};
    int members{};

    std::cout << typeGameStr[typeGame - 1] << std::endl;
    std::cout << "Длина трассы: " << lengthTrack << std::endl;

    for (const auto& obj : nameIntTransports)
    {
        int padding{};
        padding = (35 - obj.string.length());
        padding = std::max(padding, 0);
        ++index;
        std::cout << index << ". ";
        std::cout << obj.string << ":" << std::setw(padding);
        if (obj.boolean)
        {
            ++members;
            std::cout << "участвует";
        }
        else
        {
            std::cout << "не участвует";
        }
        std::cout << std::endl;
    }

    std::cout << "добавить/удалить или 0 для старта гонки: " << std::endl;
    INPUT_INT(input);

    

    if (input == 0)
    {
        if (members < 2)
        {
            std::cout << "нужно зарегистрировать минимум 2 участников для старта гонки" << std::endl;
            return false;
        }
        return true;
    }

    if (gameRules.updateTransports(input - 1))
    {
        return false;
    }

    std::cout << "Ошибка! Введите корректное число: ";
    return false;
}

void printInfoTypeGameStr(std::vector<std::string>& typeGameStr)
{
    int index{0};
    for (const auto& obj : typeGameStr)
    {
        ++index;
        std::cout << index << ". " << obj << std::endl;
    }
}

void setDefoltTypeGameStr(std::vector<std::string>& typeGameStr)
{
    typeGameStr.push_back("Гонка для наземного транспорта");
    typeGameStr.push_back("Гонка для воздушного транспорта");
    typeGameStr.push_back("Гонка для всех");
}

void printResult(GameRules& gameRules)
{
    int index{};
    std::multimap<int, std::string> resultMap = gameRules.getResult();
    std::cout << std::endl << std::endl << "Результат Гонки:" << std::endl;
    for (const auto& obj : resultMap)
    {
        int padding{};
        padding = (35 - obj.second.length());
        padding = std::max(padding, 0);
        ++index;
        std::cout << index << ". ";
        std::cout << obj.second << std::setw(padding) << obj.first << std::endl;
    }
}

void printMain()
{
    int typeGame{};
    int lengthTrack{};
    std::vector<std::string> typeGameStr;
    std::vector<StringBool> nameIntTransports;

    setDefoltTypeGameStr(typeGameStr);

    std::cout << "Добро пожаловать в гоночный симулятор!" << std::endl << std::endl;
    printInfoTypeGameStr(typeGameStr);
    std::cout << std::endl << "Выберите тип гонки: ";
    //std::cin >> typeGame;
    INPUT_INT(typeGame);
    typeGame = std::clamp(typeGame, 1, 3);

    std::cout << "Укажите длину дистанции: ";
    //std::cin >> lengthTrack;
    INPUT_INT(lengthTrack);
    lengthTrack = std::max(lengthTrack, 0);

    //std::cout << "";

    GameRules gameRules(static_cast<TypeGame>(typeGame), lengthTrack);

    while (!printInfo(typeGame, lengthTrack, nameIntTransports, typeGameStr, gameRules))
    {
    }
    gameRules.startGame();
    printResult(gameRules);

    return;
}

bool printRestart()
{
    int input{};
    std::cout << std::endl << "Выберите действие 0 рестарт 1 выйти: ";
    INPUT_INT(input);
    input = std::clamp(input, 0, 1);
    std::cout << std::endl; 
    if (input == 0)
    {
        return true;
    }
    return false;
}

int main()
{
    setlocale(LC_ALL, "");

    do
    {
        system("cls");
        printMain();
    } while (printRestart());
    return 0;
}
