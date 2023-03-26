#pragma once

#include "../ControllableObject.hpp"

class IdleRabbids : public ControllableObject
{
public:
    virtual void print() override;
    virtual void controlled() override;
};