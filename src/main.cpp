#include <iostream>
#include "./Objects/Interactable/InteractableObject.hpp"
#include "./Objects/Factory/ObjectFactory.hpp"
#include "./Objects/Factory/ObjectFactory.cpp"

using namespace std;

int main()
{
  InteractableObject button = ObjectFactory.CreateObject("Button");
  button.Interact();
  return 0;
}
