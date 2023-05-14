#include "ObjectFactory.hpp"
#include "../Interactable/Button/Button.hpp"
#include "../Interactable/CardBox/CardBox.hpp"
#include "../Interactable/ElectricFence/ElectricFence.hpp"
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

// Objects *ObjectFactory::CreateObject(string ObjectName)
// {
//     cout << ObjectName << " Created" << endl;
//     if(ObjectName == "Button"){
//         Objects *button = new Button();
//         return button;
// 	}
//     else if(ObjectName == "CardBox"){
//         Objects *cardBox = new CardBox();
//         return cardBox;
//     }
//     else if(ObjectName == "ElectricFence"){
//         Objects *electricFence = new ElectricFence();
//         return electricFence;
//     }
//     else if(ObjectName == "IdleRabbids"){
//         Objects *idleRabbids = new IdleRabbids();
//         return idleRabbids;
//     }
//     else if(ObjectName == "Saw"){
//         Objects *saw = new Saw();
//         return saw;
//     }
//     else if(ObjectName == "SedotWC"){
//         Objects *sedotWC = new SedotWC();
//         return sedotWC;
//     }
//     else if(ObjectName == "Tas"){
//         Objects *tas = new Tas();
//         return tas;
//     }
//     else if(ObjectName == "Tissue"){
//         Objects *tissue = new Tissue();
//         return tissue;
//     }
//     else if(ObjectName == "WashingMachine"){
//         Objects *washingMachine = new WashingMachine();
//         return washingMachine;
//     }
//     else if(ObjectName == "ArmedRabbids"){
//         Objects *armedRabbids = new ArmedRabbids();
//         return armedRabbids;
//     }
//     else if(ObjectName == "Claw_Robot"){
//         Objects *claw_Robot = new Claw_Robot();
//         return claw_Robot;
//     }
//     else if(ObjectName == "Rabbids"){
//         Objects *rabbids = new Rabbids();
//         return rabbids;
//     }
//     else if(ObjectName == "Vacuum"){
//         Objects *vacuum = new Vacuum();
//         return vacuum;
//     }
//     else{
//         cout << "Object Tidak Ada" << endl;
//         return NULL;
//     }

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
// }

ControllableObject *ObjectFactory::Create_CO(string ObjectName)
{
    cout << ObjectName << " Created" << endl;
    if(ObjectName == "ArmedRabbids"){
        ControllableObject *armedRabbids = new ArmedRabbids();
        return armedRabbids;
    }
    else if(ObjectName == "Claw_Robot"){
        ControllableObject *claw_Robot = new Claw_Robot();
        return claw_Robot;
    }
    else if(ObjectName == "Rabbids"){
        ControllableObject *rabbids = new Rabbids();
        return rabbids;
    }
    else if(ObjectName == "Vacuum"){
        ControllableObject *vacuum = new Vacuum();
        return vacuum;
    }
    else
    {
        cout << "Object Tidak Ada" << endl;
        return NULL;
    }
}

InteractableObject *ObjectFactory::Create_IO(string ObjectName){

    cout << ObjectName << " Created" << endl;
    if(ObjectName == "Button"){
        InteractableObject *button = new Button();
        return button;
	}
    else if(ObjectName == "CardBox"){
        InteractableObject *cardBox = new CardBox();
        return cardBox;
    }
    else if(ObjectName == "ElectricFence"){
        InteractableObject *electricFence = new ElectricFence();
        return electricFence;
    }
    else if(ObjectName == "IdleRabbids"){
        InteractableObject *idleRabbids = new IdleRabbids();
        return idleRabbids;
    }
    else if(ObjectName == "Saw"){
        InteractableObject *saw = new Saw();
        return saw;
    }
    else if(ObjectName == "SedotWC"){
        InteractableObject *sedotWC = new SedotWC();
        return sedotWC;
    }
    else if(ObjectName == "Tas"){
        InteractableObject *tas = new Tas();
        return tas;
    }
    else if(ObjectName == "Tissue"){
        InteractableObject *tissue = new Tissue();
        return tissue;
    }
    else if(ObjectName == "WashingMachine"){
        InteractableObject *washingMachine = new WashingMachine();
        return washingMachine;
    }
    else
    {
        cout << "Object Tidak Ada" << endl;
        return NULL;
    }
}
