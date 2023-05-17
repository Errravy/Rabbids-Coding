#include <iostream>

#include "Objects/Controlable/IControlable.hpp"
#include "Objects/Controlable/Rabbids/Rabbids.hpp"
#include "Objects/Controlable/ClawRobot/ClawRobot.hpp"

#include "Objects/Interactable/IInteractable.hpp"
#include "Objects/Interactable/IdleRabbids/IdleRabbids.hpp"
#include "Objects/Interactable/SedotWC/SedotWC.hpp"


#include "Command/ICommand.hpp"
#include "Command/MoveForward/MoveForward.hpp"
#include "Command/MoveBackward/MoveBackward.hpp"

#include "Enum/Commands.hpp"

int main()
{
	//IControlable *rabbids = new ClawRobot();
	//ICommand *command = new MoveBackward(rabbids);

	//rabbids->setCommand(command);
	//rabbids->getCommand(Commands::CommandBackward)->execute();

	IInteractable* button = new SedotWC();
	button->react();
}