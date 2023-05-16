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

#include "../ControllableObject/ArmedRabbids/ArmedRabbids.cpp"
#include "../ControllableObject/Claw_Robot/Claw_Robot.cpp"
#include "../ControllableObject/Rabbids/Rabbids.cpp"
#include "../ControllableObject/Vacuum/Vacuum.cpp"

Objects *ObjectFactory::createObject(string ObjectName)
{
    Objects *object = nullptr;
    cout << ObjectName << " Created" << endl;
    
    if(ObjectName == "Button"){
        object = new Button();
        return object;
	}
    else if(ObjectName == "CardBox"){
        object = new CardBox();
        return object;
    }
    else if(ObjectName == "ElectricFence"){
        object = new ElectricFence();
        return object;
    }
    else if(ObjectName == "IdleRabbids"){
        object = new IdleRabbids();
        return object;
    }
    else if(ObjectName == "Saw"){
        object = new Saw();
        return object;
    }
    else if(ObjectName == "SedotWC"){
        object = new SedotWC();
        return object;
    }
    else if(ObjectName == "Tas"){
        object = new Tas();
        return object;
    }
    else if(ObjectName == "Tissue"){
        object = new Tissue();
        return object;
    }
    else if(ObjectName == "WashingMachine"){
        object = new WashingMachine();
        return object;
    }
    else if(ObjectName == "ArmedRabbids"){
        object = new ArmedRabbids();
        return object;
    }
    else if(ObjectName == "Claw_Robot"){
        object = new Claw_Robot();
        return object;
    }
    else if(ObjectName == "Rabbids"){
        object = new Rabbids();
        return object;
    }
    else if(ObjectName == "Vacuum"){
        object = new Vacuum();
        return object;
    }
    else{
        cout << "Object Tidak Ada" << endl;
        return NULL;
    }
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
