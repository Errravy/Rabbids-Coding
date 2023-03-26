#pragma once
#include "../Interactable/InteractableObject.hpp"
using namespace std;

class ObjectFactory
{
public:
	static InteractableObject *CreateObject(string ObjectName);
};
