#pragma once

#include <string>

class Transport
{
  private:
    std::string name{};
    bool activation{false};

  protected:
    int speed{};
    double time{};

  public:
    Transport(std::string name, int speed) : name(name), speed(abs(speed))
    {
    }

    ~Transport()
    {
    }

    void setActivation();
    bool getActivation();
    int getResult(int lengthTrack);
    std::string getName();

  private:
    virtual void calculation(int lengthTrack) = 0;
};
