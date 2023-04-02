#include "ObjectFactory.hpp"
#include "../Interactable/Button/Button.hpp"
#include "../Interactable/Button/Button.cpp"
#include "../Interactable/IdleRabbids/IdleRabbids.hpp"
#include "../Interactable/IdleRabbids/IdleRabbids.cpp"
#include "../ControllableObject/Rabbids/Rabbids.hpp"
#include "../ControllableObject/Rabbids/Rabbids.cpp"

InteractableObject *ObjectFactory::CreateInteractableObject(string nama)
{
    cout << nama << " Created" << endl;
    if (nama == "Button")
    {
        InteractableObject *button = new Button();
        return button;
    }
    else if (nama == "IdleRabbids")
    {
        InteractableObject *idleRabbids = new IdleRabbids();
        return idleRabbids;
    }
    else
    {
        return NULL;
    }
}

ControllableObject *ObjectFactory::CreateControllableObject(string nama)
{
    cout << nama << " Created" << endl;
    if (nama == "Rabbids")
    {
        ControllableObject *rabbids = new Rabbids();
        return rabbids;
    }
    else
    {
        return NULL;
    }
}