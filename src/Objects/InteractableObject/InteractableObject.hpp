#pragma once

#include "../Object.hpp"

class InteractableObject : public Object
{
public:
    virtual void interact() = 0;
};