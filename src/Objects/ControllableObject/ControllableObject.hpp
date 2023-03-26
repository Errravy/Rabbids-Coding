#pragma once

#include "../Object.hpp"

class ControllableObject : public Object
{
public:
    virtual void controlled() = 0;
};