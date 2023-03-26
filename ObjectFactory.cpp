#include "ObjectFactory.h"
#include "./Objects/Interactable/Header/InteractableObject.h"
#include "./Objects/Interactable/Header/Button.h"
#include <iostream>

InteractableObject *ObjectFactory::CreateObject(string nama)
{
    cout << nama << endl;
    InteractableObject *button = new Button();
    return button;
}