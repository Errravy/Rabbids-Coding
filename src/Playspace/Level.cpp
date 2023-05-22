#include "Level.h"

Level::Level(Invoker& const invoker) 
{
    grid = new Grid(6, 10);
    this->invoker = invoker;
}

Grid Level::GetGrid() { return grid; }

Invoker Level::Invoker() { return invoker; }

void Level::ShowAvailableMoves() { }

bool Level::isCompleted() { return isCompleted; }

void Level::SetControllable(ControllableObject& const controllable)
{
    this->controllable = controllable;
}

ControllableObject Level::GetControllable() { return controllable; }