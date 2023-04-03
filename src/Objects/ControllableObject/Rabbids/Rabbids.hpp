#pragma once
#include "../ControllableObject.hpp"

private int Direction;
class Rabbids : public ControllableObject
{
    private: 
    int Direction;
public:
    int getDirection() override;
    void setDirection(int newDirection) override;
};