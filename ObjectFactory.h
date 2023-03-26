#include "./Objects/Interactable/Header/InteractableObject.h"
#include <iostream>

using namespace std;

class ObjectFactory
{
public:
	InteractableObject *CreateObject(string ObjectName);
};
