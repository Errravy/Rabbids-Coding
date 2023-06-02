#include "Level.hpp"

Level::Level(std::string levelName, int width, int height, Invoker *invoker)
{
    _grid = new Grid(width, height);
    _levelName = levelName;
    _invoker = invoker;
}

void Level::showAvailableMoves()
{
    std::cout << "Available moves:" << std::endl;
    for (int i = 0; i < _controlable->getCommands().size(); i++)
    {
        std::cout << i + 1 << ". " << _controlable->getCommands()[i] << std::endl;

        if (i == _controlable->getCommands().size() - 1)
        {
            std::cout << "9. Execute commands" << std::endl;
        }
    }
}

Grid *Level::getGrid()
{
    return _grid;
}

std::string Level::getLevelName()
{
    return _levelName;
}

int Level::getScore()
{
    return _score;
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

void Level::setObjective(IObjective *objective)
{
    _invoker->setObjective(objective);

    _grid->getCells()[objective->getCoordinates()]->setToFinishLine();
}

bool Level::isCompleted()
{
    return _isCompleted;
}

void Level::setCompleted(bool isCompleted)
{
    _isCompleted = isCompleted;
}
