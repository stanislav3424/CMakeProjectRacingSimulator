#pragma once

#include "Transport.h"

#include <vector>

class Lend : public Transport
{
  private:
    int stamina{};
    std::vector<float> staminaDelay;

  public:
    Lend(std::string name, int speed, int stamina, std::vector<float> staminaDelay)
        : Transport(name, speed), stamina(abs(stamina)), staminaDelay(staminaDelay)
    {
        for (auto& obj : staminaDelay)
        {
            obj = abs(obj);
        }
    }

    ~Lend() = default;

  private:
    void calculation(int lengthTrack) override;
};
