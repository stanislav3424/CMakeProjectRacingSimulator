#pragma once

#include "Transport.h"
#include "IntInt.h"

#include <vector>

class Air : public Transport
{
  private:
    std::vector<DistancePercent> factor;

  public:
    Air(std::string name, int speed, std::vector<DistancePercent> factor) : Transport(name, speed), factor(factor)
    {
    }

    ~Air() = default;

  private:
    void calculation(int lengthTrack) override;
    int linearCalculations(int lengthTrack);
    int quadratic—alculations(int lengthTrack);
};
