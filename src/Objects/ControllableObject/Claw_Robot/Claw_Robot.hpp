#pragma once
#include "../ControllableObject.hpp"

class Claw_Robot : public ControllableObject
{
private: int direction;
public:
    int getDirection() override;
    void setDirection(int newDirection) override;

    void Interact() override;
};