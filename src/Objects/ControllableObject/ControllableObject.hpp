#ifndef CONTROLLABLEOBJECT_H
#define CONTROLLABLEOBJECT_H

#pragma once
#include "../Objects.hpp"

class ControllableObject : public Objects
{
public:
    // ControllableObject();
    // ~ControllableObject();

    virtual void setDirection(int newDirection) = 0;
    virtual int getDirection() = 0;

private:

};

#endif