#pragma once
#include "../ControllableObject.hpp"

class Rabbids : public ControllableObject
{
public:
    void getDirection() override;
    void setDirection() override;
};