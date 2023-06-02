#pragma once

#include "../ICommand.hpp"
#include "../../Objects/Controlable/IControlable.hpp"
#include "../../Objects/Interactable/IInteractable.hpp"
#include "../../Playspace/Grid/Grid.hpp"

class Interact : public ICommand
{
private:
    IControlable* _player;
    Grid* _grid;

public:
    Interact(IControlable* player,Grid* grid);
    void execute() override;
};