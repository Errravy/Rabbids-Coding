#include "Level.hpp"

Level::Level(std::string levelName, int width, int height, Invoker *invoker)
{
    _grid = new Grid(width, height);
    _levelName = levelName;
    _invoker = invoker;
}

Grid *Level::getGrid()
{
    return _grid;
}

std::string Level::getLevelName()
{
    return _levelName;
}

Invoker *Level::getInvoker()
{
    return _invoker;
}

IControlable *Level::getControlable()
{
    return _controlable;
}

void Level::setControlable(IControlable *controlable)
{
    _controlable = controlable;
}

bool Level::isCompleted()
{
    return false;
}
