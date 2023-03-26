#pragma once

#include "../InteractableObject.hpp"

class WashingMachine : public InteractableObject
{
public:
    virtual void print() override;
    virtual void interact() override;
};