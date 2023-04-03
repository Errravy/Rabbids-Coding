#pragma once
#include "../InteractableObject.hpp"

class ElectricFence : public InteractableObject
{
public:
    void React() override;
};