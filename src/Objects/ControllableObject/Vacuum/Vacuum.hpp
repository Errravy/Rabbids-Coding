#pragma once
#include "../ControllableObject.hpp"

class Vacuum : public ControllableObject
{
public:
    void getDirection() override;
    void setDirection() override;
};