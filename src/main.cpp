#include <iostream>
#include "./Objects/Factory/ObjectFactory.cpp"
// #include "./Objects/Factory/ObjectFactory.hpp"

using namespace std;

int main()
{
  InteractableObject *button = ObjectFactory::CreateObject("Button");
  InteractableObject *idleRabbids = ObjectFactory::CreateObject("IdleRabbids");
  button->Interact();
  idleRabbids->Interact();
  delete button;
  delete idleRabbids;
  return 0;
}
