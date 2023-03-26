#pragma once

#include "../InteractableObject.hpp"

class Button : public InteractableObject
{
public:
    virtual void print() override;
    virtual void interact() override;
};