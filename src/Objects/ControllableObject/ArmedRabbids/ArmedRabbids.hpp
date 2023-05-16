#pragma once
#include "../ControllableObject.hpp"

class ArmedRabbids : public ControllableObject
{
private: int direction;
public:
    int getDirection() override;
    void setDirection(int newDirection) override;
    void Interact() ;
};