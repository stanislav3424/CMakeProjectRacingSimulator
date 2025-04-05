#include "Print.h"

void updateTransportsActivation(std::vector<StringBoolean>& nameIntTransports, GameRules& gameRules)
{
    nameIntTransports = gameRules.getTransportsName();
}

bool printInfoTransports(const int& typeGame, const int& lengthTrack, std::vector<StringBoolean>& nameIntTransports,
               const std::vector<std::string>& typeGameStr, GameRules& gameRules)
{
    system("cls");
    updateTransportsActivation(nameIntTransports, gameRules);

    int input{};
    int index{};
    int members{};

    std::cout << typeGameStr[typeGame - 1] << std::endl;
    std::cout << "����� ������: " << lengthTrack << std::endl;

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
            std::cout << "���������";
        }
        else
        {
            std::cout << "�� ���������";
        }
        std::cout << std::endl;
    }

    std::cout << "��������/������� ��� 0 ��� ������ �����: " << std::endl;
    INPUT_INT(input);

    if (input == 0)
    {
        if (members < 2)
        {
            std::cout << "����� ���������������� ������� 2 ���������� ��� ������ �����" << std::endl;
            return false;
        }
        return true;
    }

    if (gameRules.updateTransports(input - 1))
    {
        return false;
    }

    std::cout << "������! ������� ���������� �����: ";
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
    typeGameStr.push_back("����� ��� ��������� ����������");
    typeGameStr.push_back("����� ��� ���������� ����������");
    typeGameStr.push_back("����� ��� ����");
}

void printResult(GameRules& gameRules)
{
    system("cls");
    int index{};
    std::multimap<int, std::string> resultMap = gameRules.getResult();
    std::cout << std::endl << std::endl << "��������� �����:" << std::endl;
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
    std::vector<StringBoolean> nameIntTransports;

    setDefoltTypeGameStr(typeGameStr);

    std::cout << "����� ���������� � �������� ���������!" << std::endl << std::endl;
    printInfoTypeGameStr(typeGameStr);
    std::cout << std::endl << "�������� ��� �����: ";
    INPUT_INT(typeGame);
    typeGame = std::clamp(typeGame, 1, 3);

    std::cout << "������� ����� ���������: ";
    INPUT_INT(lengthTrack);
    lengthTrack = std::max(lengthTrack, 0);

    GameRules gameRules(static_cast<TypeGame>(typeGame), lengthTrack);

    while (!printInfoTransports(typeGame, lengthTrack, nameIntTransports, typeGameStr, gameRules))
    {
    }
    gameRules.startGame();
    printResult(gameRules);

    return;
}

bool printRestart()
{
    int input{};
    std::cout << std::endl << "�������� �������� 0 ������� 1 �����: ";
    INPUT_INT(input);
    input = std::clamp(input, 0, 1);
    std::cout << std::endl;
    if (input == 0)
    {
        return true;
    }
    return false;
}