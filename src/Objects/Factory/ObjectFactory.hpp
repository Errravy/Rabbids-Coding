#pragma once

#include "../../Enums/Objects.hpp"
#include "../IObjects.hpp"
#include "../Interactable/IInteractable.hpp"
#include "../Controlable/IControlable.hpp"

class ObjectFactory
{
public:
	static IObjects *createObject(Objects ObjectName);
	static IInteractable *Create_IO(Objects ObjectName);
	static IControlable *Create_CO(Objects ObjectName);
};