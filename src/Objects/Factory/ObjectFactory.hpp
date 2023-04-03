#pragma once
#include "../Interactable/InteractableObject.hpp"
#include "../ControllableObject/ControllableObject.hpp"
using namespace std;

class ObjectFactory
{
public:
	static InteractableObject *CreateInteractableObject(string ObjectName);
	static ControllableObject *CreateControllableObject(string ObjectName);
};
