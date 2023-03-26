#include "ObjectFactory.h"
#include ".../Interactable/Button/Button.hpp"
#include ".../Interactable/Button/Button.cpp"
#include ".../Interactable/IdleRabbids/IdleRabbids.hpp"
#include ".../Interactable/IdleRabbids/IdleRabbids.cpp"

InteractableObject *ObjectFactory::CreateObject(string nama)
{
    cout << nama << endl;
    switch (nama)
    {
    case "Button":
        InteractableObject *button = new Button();
        return button;
        break;

    case "IdleRabbids":
        InteractableObject *idleRabbids = new IdleRabbids();
        return idleRabbids;
        break;

    default:
        break;
    }
    return null;
}