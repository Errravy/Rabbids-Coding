// #include "Objects/Factory/ObjectFactory.cpp"
// #include "Objects/InteractableObject/Button/Button.cpp"
// #include "Objects/InteractableObject/WashingMachine/WashingMachine.cpp"
// #include "Objects/ControllableObject/IdleRabbids/IdleRabbids.cpp"

#include "Commands/Invoker/Invoker.cpp"
#include "Commands/MoveCommands/MoveForward/MoveForward.cpp"
#include "Commands/MoveCommands/MoveBackward/MoveBackward.cpp"

int main()
{
    // IdleRabbids *idleRabbids = dynamic_cast<IdleRabbids *>(ObjectFactory::createObject("IdleRabbids"));
    // idleRabbids->print();
    // idleRabbids->controlled();

    // Button *button = dynamic_cast<Button *>(ObjectFactory::createObject("Button"));
    // button->print();
    // button->interact();

    // WashingMachine *washingMachine = dynamic_cast<WashingMachine *>(ObjectFactory::createObject("WashingMachine"));
    // washingMachine->print();
    // washingMachine->interact();

    Invoker *invoker = new Invoker();
    MoveForward *moveForward = new MoveForward();
    MoveBackward *moveBackward = new MoveBackward();

    invoker->storeCommand(moveForward);
    invoker->storeCommand(moveBackward);
    invoker->storeCommand(moveForward);
    invoker->executeCommand();

    return 0;
}