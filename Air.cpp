#include "Air.h"

void Air::calculation(int lengthTrack)
{
    int CurentLocation{};
    if (factor.empty())
    {
        return;
    }
    if (factor[0].percent < 0)
    {
        lengthTrack = quadratic—alculations(lengthTrack);
    }
    else
    {
        lengthTrack = linearCalculations(lengthTrack);
    }
    while (CurentLocation < lengthTrack)
    {
        CurentLocation += speed;
        ++time;
    }
}

int Air::linearCalculations(int lengthTrack)
{
    int discountPercent = 0;

    if (factor.empty() || lengthTrack < factor[0].distance)
    {
        return lengthTrack;
    }

    for (size_t index = 0; index < factor.size(); ++index)
    {
        if (lengthTrack < factor[index].distance)
        {
            if (index > 0)
            {
                discountPercent = factor[index - 1].percent;
            }
            break;
        }
    }

    if (lengthTrack >= factor.back().distance)
    {
        discountPercent = factor.back().percent;
    }

    return lengthTrack * (100 - discountPercent) / 100;
}

int Air::quadratic—alculations(int lengthTrack)
{
    return lengthTrack * (100 - ((lengthTrack / factor[0].distance) * abs(factor[0].percent))) / 100;
}