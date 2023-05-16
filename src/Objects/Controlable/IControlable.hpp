#pragma once

#ifndef ICONTROLABLE_HPP
#define ICONTROLABLE_HPP

#include "../IObjects.hpp"
#include "../../Command/ICommand.hpp"
#include "../../Enums/Directions.hpp"
#include "../../Enums/Commands.hpp"

class IControlable : public IObjects
{
public:
    virtual ICommand *setCommand(ICommand *command) = 0;
    virtual ICommand *getCommand(Commands commands) = 0;
    virtual void setDirection(int direction) = 0;
    virtual Directions getDirection() = 0;
};

#endif