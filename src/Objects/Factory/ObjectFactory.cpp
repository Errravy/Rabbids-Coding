#include "ObjectFactory.hpp"

Object *ObjectFactory::createObject(const char *objectName)
{
    if (objectName == "Button")
    {
        return new Button();
    }
    else if (objectName == "WashingMachine")
    {
        return new WashingMachine();
    }
    else if (objectName == "IdleRabbids")
    {
        return new IdleRabbids();
    }
    else
    {
        return nullptr;
    }
}