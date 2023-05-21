#include "Factory.hpp"

IObjects *Factory::createObject(Objects type)
{
    switch (type)
    {
    case Objects::Rabbids:
        return new Rabbids();
    case Objects::Button:
        return new Button();
    case Objects::Bag:
        return new Bag();
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