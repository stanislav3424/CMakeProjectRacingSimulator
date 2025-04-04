#pragma once

#include "Transport.h"
#include "IntInt.h"

#include <vector>

class Air : public Transport
{
  private:
    std::vector<IntInt> factor;

  public:
    Air(std::string name, int speed, std::vector<IntInt> factor) : Transport(name, speed), factor(factor)
    {
    }

    ~Air()
    {
    }

  private:
    void calculation(int lengthTrack) override;
    int linear—alculations(int lengthTrack);
    int quadraticc—lculations(int lengthTrack);
};
