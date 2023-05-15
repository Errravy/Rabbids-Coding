#include <iostream>
#include "./Objects/Factory/ObjectFactory.cpp"
// #include "./Objects/Factory/ObjectFactory.hpp"

using namespace std;

int main()
{
  InteractableObject *button = ObjectFactory::Create_IO("Button");
  InteractableObject *idleRabbids = ObjectFactory::Create_IO("IdleRabbids");
  button->Interact();
  idleRabbids->Interact();
  delete button;
  delete idleRabbids;
  return 0;
}
