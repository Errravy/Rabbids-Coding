#pragma once

#include "../Enum/Objects.hpp"
#include "../Enum/Commands.hpp"

#include "../Objects/IObjects.hpp"
#include "../Objects/Controlable/IControlable.hpp"
#include "../Objects/Controlable/Rabbids/Rabbids.hpp"
#include "../Objects/Interactable/Bag/Bag.hpp"
#include "../Objects/Interactable/Button/Button.hpp"

#include "../Command/ICommand.hpp"
#include "../Command/MoveBackward/MoveBackward.hpp"
#include "../Command/MoveForward/MoveForward.hpp"
#include "../Command/TurnLeft/TurnLeft.hpp"
#include "../Command/TurnRight/TurnRight.hpp"

class Factory
{
public:
    static IObjects *createObject(Objects);
    static ICommand *createCommand(IControlable *, Commands);
};