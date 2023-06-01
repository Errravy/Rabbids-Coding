#pragma once

#include "../Enum/Objects.hpp"
#include "../Enum/Commands.hpp"

#include "../Objects/IObjects.hpp"

#include "../Objects/Controlable/IControlable.hpp"
#include "../Objects/Controlable/Rabbids/Rabbids.hpp"
#include "../Objects/Controlable/ArmedRabbids/ArmedRabbids.hpp"
#include "../Objects/Controlable/ClawRobot/ClawRobot.hpp"
#include "../Objects/Controlable/VacuumRobot/VacuumRobot.hpp"

#include "../Objects/Interactable/IInteractable.hpp"
#include "../Objects/Interactable/Bag/Bag.hpp"
#include "../Objects/Interactable/Button/Button.hpp"
#include "../Objects/Interactable/CardBox/CardBox.hpp"
#include "../Objects/Interactable/ElectricFence/ElectricFence.hpp"
#include "../Objects/Interactable/IdleRabbids/IdleRabbids.hpp"
#include "../Objects/Interactable/Plunger/Plunger.hpp"
#include "../Objects/Interactable/Saw/Saw.hpp"
#include "../Objects/Interactable/Tissue/Tissue.hpp"
#include "../Objects/Interactable/WashingMachine/WashingMachine.hpp"

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