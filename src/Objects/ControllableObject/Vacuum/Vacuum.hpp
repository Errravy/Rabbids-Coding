#pragma once
#include "../ControllableObject.hpp"

class Vacuum : public ControllableObject
{
private: int direction;
public:
    int getDirection() override;
    void setDirection(int newDirection) override;
};