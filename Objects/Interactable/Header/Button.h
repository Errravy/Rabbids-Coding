#include <iostream>
#include "InteractableObject.h"

class Button : public InteractableObject
{
public:
    void Interact() override;
};
