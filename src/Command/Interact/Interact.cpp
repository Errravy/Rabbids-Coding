#include "Interact.hpp"

Interact::Interact(IControlable* player,Grid* grid)
{
    _player = player;
    _grid = grid;
}

void Interact::execute()
{
    std::pair<int, int> pos = _player->getPosition();
    IInteractable* obj = nullptr;
    if (obj = dynamic_cast<IInteractable*>(_grid->getCells()[pos]->getCurrentObject()))
    {
        if (obj != nullptr)
            obj->react();
        else
            return;
    }
}