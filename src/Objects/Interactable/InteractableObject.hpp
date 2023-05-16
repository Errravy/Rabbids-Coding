#pragma once
#ifndef IINTERACTABLE_HPP
#define IINTERACTABLE_HPP

#include "Objects.hpp"

class IInteractable : public IObjects
{
public:
    virtual void react() = 0;
};

#endif // IINTERACTABLE_HPP
