#include "Transport.h"

int Transport::getResult(int lengthTrack)
{
    calculation(lengthTrack);
    return time;
}

bool Transport::getActivation()
{
    return activation;
}

void Transport::setActivation()
{
    Transport::activation = 1 - activation;
}

std::string Transport::getName()
{
    return name;
}