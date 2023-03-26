#pragma once

#include "../InteractableObject.hpp"

class Tas : public InteractableObject
{
public:
    virtual void print() override;
    virtual void interact() override;
};