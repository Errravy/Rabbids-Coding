#include "ObjectFactory.hpp"
#include "../Interactable/Button/Button.hpp"
#include "../Interactable/CardBox/CardBox.hpp"
#include "../Interactable/ElectricFence/CardBox.hpp"
#include "../Interactable/IdleRabbids/IdleRabbids.hpp"
#include "../Interactable/Saw/Saw.hpp"
#include "../Interactable/SedotWC/SedotWC.hpp"
#include "../Interactable/Tas/Tas.hpp"
#include "../Interactable/Tissue/Tissue.hpp"
#include "../Interactable/WashingMachine/WashingMachine.hpp"

#include "../ControllableObject/ArmedRabbids/ArmedRabbids.hpp"
#include "../ControllableObject/Claw_Robot/Claw_Robot.hpp"
#include "../ControllableObject/Rabbids/Rabbids.hpp"
#include "../ControllableObject/Vacuum/Vacuum.hpp"

Objects *ObjectFactory::CreateObject(string nama)
{
    cout << nama << " Created" << endl;
    switch (nama)
    {
        case "Button":
            Objects *button = new Button();
            return button;
            break;
        
        case "CardBox":
            Objects *cardBox = new CardBox();
            return cardBox;
            break; 

        case "ElectricFence":  
            Objects *electricFence = new ElectricFence();
            return electricFence;
            break;

        case "IdleRabbids":
            Objects *idleRabbids = new IdleRabbids();
            return idleRabbids;
            break;
        
        case "Saw":
            Objects *saw = new Saw();
            return saw;
            break;
        
        case "SedotWC":
            Objects *sedotWC = new SedotWC();
            return sedotWC;
            break;
        
        case "Tas":
            Objects *tas = new Tas();
            return tas;
            break; 

        case "Tissue":
            Objects *tissue = new Tissue();
            return tissue;
            break;
        
        case "WashingMachine":
            Objects *washingMachine = new WashingMachine();
            return washingMachine;
            break;

        case "ArmedRabbids":
            Objects *armedRabbids = new ArmedRabbids();
            return armedRabbids;
            break;

        case "Claw_Robot":
            Objects *claw_Robot = new Claw_Robot();
            return claw_Robot;
            break;
        
        case "Rabbids":
            Objects *rabbids = new Rabbids();
            return rabbids;
            break;
        
        case "Vacuum":
            Objects *vacuum = new Vacuum();
            return vacuum;
            break;

        default:
            cout << "Object Tidak Ada" << endl;
            break;
    }

    // if (nama == "Button")
    // {
    //     Objects *button = new Button();
    //     return button;
    // }
    // else if (nama == "IdleRabbids")
    // {
    //     InteractableObject *idleRabbids = new IdleRabbids();
    //     return idleRabbids;
    // }
    // else
    // {
    //     return NULL;
    // }
}

// ControllableObject *ObjectFactory::CreateControllableObject(string nama)
// {
//     cout << nama << " Created" << endl;
//     if (nama == "Rabbids")
//     {
//         ControllableObject *rabbids = new Rabbids();
//         return rabbids;
//     }
//     else
//     {
//         return NULL;
//     }
// }