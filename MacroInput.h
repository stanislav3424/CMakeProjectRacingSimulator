#pragma once

#define INPUT_INT(input)                                                                                               \
    while (true)                                                                                                       \
    {                                                                                                                  \
        if (std::cin >> input)                                                                                         \
            break;                                                                                                     \
        else                                                                                                           \
        {                                                                                                              \
            std::cout << "������! ������� �����: ";                                                                    \
            std::cin.clear();                                                                                          \
            std::cin.ignore(10000, '\n');                                                                              \
        }                                                                                                              \
    }