#include "Lend.h"

void Lend::calculation(int lengthTrack)
{
    if (staminaDelay.empty())
    {
        return;
    }
    int CurentLocation{};
    int indexVector{};
    int CurentStamina{stamina};
    while (CurentLocation < lengthTrack)
    {
        if (CurentStamina > 0)
        {
            ++time;
            --CurentStamina;
            CurentLocation += speed;
        }
        else
        {
            time += staminaDelay[indexVector];
            if (indexVector + 1 < staminaDelay.size())
            {
                ++indexVector;
            }
            CurentStamina = stamina;
        }
    }
}