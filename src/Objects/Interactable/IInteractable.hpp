#pragma once

#ifndef IINTERACTABLE_HPP
#define IINTERACTABLE_HPP

#include "../IObjects.hpp"

class IInteractable : public IObjects
{
public:
    IInteractable() = default;
    virtual void react() = 0;
};

#endif
