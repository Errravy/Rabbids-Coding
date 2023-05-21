#include "Factory.hpp"

// std::ostream &operator<<(std::ostream &os, Objects type)
// {
//     switch (type)
//     {
//     case Objects::Rabbids:
//         os << "Rabbids";
//         break;
//     case Objects::Button:
//         os << "Button";
//         break;
//     case Objects::Bag:
//         os << "Bag";
//         break;
//     default:
//         os << "Unknown";
//         break;
//     }

//     return os;
// }

IObjects *Factory::createObject(Objects type)
{
    // std::cout << "Create object from factory: " << type << std::endl;
    IObjects *newObject;

    switch (type)
    {
    case Objects::Rabbids:
        std::cout << "Rabbids created" << std::endl;
        newObject = new Rabbids();
    case Objects::Button:
        std::cout << "Button created" << std::endl;
        newObject = new Button();
    case Objects::Bag:
        std::cout << "Bag created" << std::endl;
        newObject = new Bag();
    default:
        std::cout << "No object has created" << std::endl;
        newObject = nullptr;
    }

    return newObject;
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