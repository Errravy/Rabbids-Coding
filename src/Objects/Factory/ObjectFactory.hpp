#pragma once

#include "../Object.hpp"
#include "../InteractableObject/Button/Button.hpp"
#include "../InteractableObject/WashingMachine/WashingMachine.hpp"
#include "../ControllableObject/IdleRabbids/IdleRabbids.hpp"

class ObjectFactory
{
public:
	static Object *createObject(const char *);
};
