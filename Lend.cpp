#include "Lend.h"

void Lend::calculation(int lengthTrack)
{
    if (staminaDelay.empty())
    {
        return;
    }
    int CurrentLocation{};
    int indexVector{};
    int CurrentStamina{stamina};
    while (CurrentLocation < lengthTrack)
    {
        if (CurrentStamina > 0)
        {
            ++time;
            --CurrentStamina;
            CurrentLocation += speed;
        }
        else
        {
            time += staminaDelay[indexVector];
            if (indexVector + 1 < staminaDelay.size())
            {
                ++indexVector;
            }
            CurrentStamina = stamina;
        }
    }
}