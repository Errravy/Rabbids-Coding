#pragma once

#include "../IObjects.hpp"

class IInteractable : public IObjects
{
public:
    virtual void react() = 0;
    std::unique_ptr<IInteractable> self;
};