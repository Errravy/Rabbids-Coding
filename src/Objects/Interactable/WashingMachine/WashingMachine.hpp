#pragma once
#include "InteractableObject.hpp"

class WashingMachine : public InteractableObject
{
public:
    virtual void Interact() override;
};