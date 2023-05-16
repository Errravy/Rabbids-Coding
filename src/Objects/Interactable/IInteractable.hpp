#pragma once

#ifndef IINTERACTABLE_HPP
#define IINTERACTABLE_HPP

#include "../IObjects.hpp"

class IInteractable : public IObjects
{
public:
    virtual void react() = 0;
    virtual bool isSucked() = 0;
    virtual void setPositionX(int x) = 0;
    virtual void setPositionY(int y) = 0;
    virtual void setPosition(int x, int y) = 0;
    virtual std::pair<int, int> getPosition() = 0;
    virtual std::string getObjectSymbol() = 0;
};

#endif
