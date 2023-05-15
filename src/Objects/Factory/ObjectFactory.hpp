#pragma once
#include "../Objects.hpp"
#include "../Interactable/InteractableObject.hpp"
#include "../ControllableObject/ControllableObject.hpp"

using namespace std;

class ObjectFactory
{
public:
	static Objects *CreateObject(string ObjectName);
	static InteractableObject *Create_IO(string ObjectName);
	static ControllableObject *Create_CO(string ObjectName);
};