#include "Factory.hpp"

IObjects *Factory::createObject(Objects type)
{
    switch (type)
    {
    case Objects::ArmedRabbids:
        return new ArmedRabbids();
    case Objects::ClawRobot:
        return new ClawRobot();
    case Objects::Rabbids:
        return new Rabbids();
    case Objects::VacuumRobot:
        return new VacuumRobot();
    case Objects::Bag:
        return new Bag();
    case Objects::Button:
        return new Button();
    case Objects::CardBox:
        return new CardBox();
    case Objects::ElectricFence:
        return new ElectricFence();
    case Objects::IdleRabbids:
        return new IdleRabbids();
    case Objects::Plunger:
        return new Plunger();
    case Objects::Saw:
        return new Saw();
    case Objects::Tissue:
        return new Tissue();
    case Objects::WashingMachine:
        return new WashingMachine();
    default:
        return nullptr;
    }
}

ICommand *Factory::createCommand(IControlable *controlable, Commands type)
{
    switch (type)
    {
    case Commands::Forward:
        return new MoveForward(controlable);
    case Commands::Backward:
        return new MoveBackward(controlable);
    case Commands::Left:
        return new TurnLeft(controlable);
    case Commands::Right:
        return new TurnRight(controlable);
    default:
        return nullptr;
    }
}