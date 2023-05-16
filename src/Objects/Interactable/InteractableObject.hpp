#pragma once
#include "../Objects.hpp"

class InteractableObject : public Objects
{
public:
    virtual void Interact() = 0;
};
