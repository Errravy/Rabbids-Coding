#include <iostream>
#include "./Objects/Factory/ObjectFactory.cpp"
#include "./Objects/Interactable/InteractableObject.hpp"
#include <typeinfo>
// #include "./Objects/Factory/ObjectFactory.hpp"

using namespace std;

int main()
{
  Objects* button = ObjectFactory::CreateObject("Button");
  if(InteractableObject *interactableButton = static_cast<InteractableObject*>(button))
  {
    interactableButton->Interact();
  }
  else
  {
    cout << "Not Interactable" << endl;
  }
//  cout << typeid(interactableButton).name() << endl;
  return 0;
}
