#pragma once

#include <unordered_map>
#include <vector>

#include "../IObjects.hpp"
#include "../../Enum/Commands.hpp"
#include "../../Enum/Directions.hpp"
#include "../../Command/ICommand.hpp"

class IControlable : public IObjects
{
protected:
    std::unordered_map<Commands, ICommand *> _command;
    Directions _z;

public:
    virtual ICommand *setCommand(ICommand *) = 0;
    virtual ICommand *getCommand(Commands) = 0;
    virtual std::vector<std::string> getCommands() = 0;
    virtual void setDirection(int) = 0;
    virtual Directions getDirection() = 0;
};