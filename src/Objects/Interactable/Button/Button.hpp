#pragma once
#include "../InteractableObject.hpp"

class Button : public InteractableObject
{
public:
    void Interact() override;
};
