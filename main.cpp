#include <iostream>
#include "./Objects/Interactable/Header/InteractableObject.h"
#include "./Objects/Interactable/Header/Button.h"
#include "./Objects/Interactable/Header/SedotWC.h"

using namespace std;

int main()
{
  InteractableObject *button = new Button();
  InteractableObject *sedotWC = new SedotWC();
  button->Interact();
  sedotWC->Interact();
  delete button;
  delete sedotWC;
  return 0;
}
