#include "ObjectFactory.hpp"
#include "../Interactable/Button/Button.cpp"
#include "../Interactable/CardBox/CardBox.cpp"
#include "../Interactable/ElectricFence/ElectricFence.cpp"
#include "../Interactable/IdleRabbids/IdleRabbids.cpp"
#include "../Interactable/Saw/Saw.cpp"
#include "../Interactable/SedotWC/SedotWC.cpp"
#include "../Interactable/Tas/Tas.cpp"
#include "../Interactable/Tissue/Tissue.cpp"
#include "../Interactable/WashingMachine/WashingMachine.cpp"

#include "../Controlable/ArmedRabbids/ArmedRabbids.cpp"
#include "../Controlable/ClawRobot/ClawRobot.cpp"
#include "../Controlable/Rabbids/Rabbids.cpp"
#include "../Controlable/Vacuum/Vacuum.cpp"

IObjects *ObjectFactory::createObject(Objects ObjectName)
{
    IObjects *object = nullptr;
    std::cout << ObjectName << " Created" << std::endl;

    if (ObjectName == button)
    {
        object = new Button();
    }
    else if (ObjectName == cardBox)
    {
        object = new CardBox();
    }
    else if (ObjectName == electricFence)
    {
        object = new ElectricFence();
    }
    else if (ObjectName == idleRabbids)
    {
        object = new IdleRabbids();
    }
    else if (ObjectName == saw)
    {
        object = new Saw();
    }
    else if (ObjectName == sedotWC)
    {
        object = new SedotWC();
    }
    else if (ObjectName == tas)
    {
        object = new Tas();
    }
    else if (ObjectName == tissue)
    {
        object = new Tissue();
    }
    else if (ObjectName == washingMachine)
    {
        object = new WashingMachine();
    }
    else if (ObjectName == armedRabbids)
    {
        object = new ArmedRabbids();
    }
    else if (ObjectName == clawRobot)
    {
        object = new ClawRobot();
    }
    else if (ObjectName == rabbids)
    {
        object = new Rabbids();
    }
    else if (ObjectName == vacuumRobot)
    {
        object = new Vacuum();
    }
    else
    {
        std::cout << "Object Tidak Ada" << std::endl;
        return nullptr;
    }

    return object;
}

// if (ObjectName == "Button")
// {
//     Objects *button = new Button();
//     return button;
// }
// else if (ObjectName == "IdleRabbids")
// {
//     InteractableObject *idleRabbids = new IdleRabbids();
//     return idleRabbids;
// }
// else
// {
//     return NULL;
// }

// ControllableObject *ObjectFactory::Create_CO(string ObjectName)
// {
//     cout << ObjectName << " Created" << endl;
//     if(ObjectName == "ArmedRabbids"){
//         ControllableObject *armedRabbids = new ArmedRabbids();
//         return armedRabbids;
//     }
//     else if(ObjectName == "Claw_Robot"){
//         ControllableObject *claw_Robot = new Claw_Robot();
//         return claw_Robot;
//     }
//     else if(ObjectName == "Rabbids"){
//         ControllableObject *rabbids = new Rabbids();
//         return rabbids;
//     }
//     else if(ObjectName == "Vacuum"){
//         ControllableObject *vacuum = new Vacuum();
//         return vacuum;
//     }
//     else
//     {
//         cout << "Object Tidak Ada" << endl;
//         return NULL;
//     }
// }

// InteractableObject *ObjectFactory::Create_IO(string ObjectName){

//     cout << ObjectName << " Created" << endl;
//     if(ObjectName == "Button"){
//         InteractableObject *button = new Button();
//         return button;
// 	}
//     else if(ObjectName == "CardBox"){
//         InteractableObject *cardBox = new CardBox();
//         return cardBox;
//     }
//     else if(ObjectName == "ElectricFence"){
//         InteractableObject *electricFence = new ElectricFence();
//         return electricFence;
//     }
//     else if(ObjectName == "IdleRabbids"){
//         InteractableObject *idleRabbids = new IdleRabbids();
//         return idleRabbids;
//     }
//     else if(ObjectName == "Saw"){
//         InteractableObject *saw = new Saw();
//         return saw;
//     }
//     else if(ObjectName == "SedotWC"){
//         InteractableObject *sedotWC = new SedotWC();
//         return sedotWC;
//     }
//     else if(ObjectName == "Tas"){
//         InteractableObject *tas = new Tas();
//         return tas;
//     }
//     else if(ObjectName == "Tissue"){
//         InteractableObject *tissue = new Tissue();
//         return tissue;
//     }
//     else if(ObjectName == "WashingMachine"){
//         InteractableObject *washingMachine = new WashingMachine();
//         return washingMachine;
//     }
//     else
//     {
//         cout << "Object Tidak Ada" << endl;
//         return NULL;
//     }
// }
