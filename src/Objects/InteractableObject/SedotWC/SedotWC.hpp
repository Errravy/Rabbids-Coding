#pragma once

#include "../InteractableObject.hpp"

class SedotWC : public InteractableObject
{
public:
    virtual void print() override;
    virtual void interact() override;
};