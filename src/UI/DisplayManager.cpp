#include "DisplayManager.hpp"

void DisplayManager::renderLevel(Level *level)
{
    Grid *grid = level->getGrid();
    grid->checkCell(level->getControlable());

    int width = grid->getWidth();
    int height = grid->getHeight();

    for (int i = 0; i < height * _renderHeightMultiplier; i++)
    {
        for (int j = 0; j < width; j++)
        {
            Cell *currentCell = grid->getCells()[std::make_pair(j, i / _renderHeightMultiplier)];

            if (i % _renderHeightMultiplier == 0)
            {
                std::cout << "|=======";
            }
            else if (i % _renderHeightMultiplier == 1)
            {
                std::cout << "|";

                if (currentCell->isWalkable())
                {
                    setConsoleColor(_greenColor);
                    std::cout << "       ";
                }
                else
                {
                    if (currentCell->isBlocked())
                    {
                        setConsoleColor(_defaultColor);
                        std::cout << "       ";
                    }
                    else
                    {
                        if (IControlable *controlable = dynamic_cast<IControlable *>(currentCell->getObject()))
                        {
                            setConsoleColor(_blueColor);
                            if (controlable->getDirection() == Directions::Up)
                            {
                                std::cout << "   ^   ";
                            }
                            else
                            {
                                std::cout << "       ";
                            }
                        }
                        else
                        {
                            setConsoleColor(_redColor);
                            std::cout << "       ";
                        }
                    }
                }

                setConsoleColor(_defaultColor);
            }
            else if (i % _renderHeightMultiplier == 2)
            {
                std::cout << "|";

                if (currentCell->isWalkable())
                {
                    setConsoleColor(_greenColor);
                    std::cout << "   " << currentCell->getCellObj() << "   ";
                }
                else
                {
                    if (currentCell->isBlocked())
                    {
                        setConsoleColor(_defaultColor);
                        std::cout << "   " << currentCell->getCellObj() << "   ";
                    }
                    else
                    {
                        if (IControlable *controlable = dynamic_cast<IControlable *>(currentCell->getObject()))
                        {
                            setConsoleColor(_blueColor);
                            if (controlable->getDirection() == Directions::Right)
                            {
                                std::cout << "   " << currentCell->getCellObj() << "   ";
                                std::cout << "   " << currentCell->getCellObj() << " > ";
                            }
                            else if (controlable->getDirection() == Directions::Left)
                            {
                                std::cout << " < " << currentCell->getCellObj() << "   ";
                            }
                        }
                        else
                        {
                            setConsoleColor(_redColor);
                            std::cout << "   " << currentCell->getCellObj() << "   ";
                        }
                    }
                }

                setConsoleColor(_defaultColor);
            }
            else if (i % _renderHeightMultiplier == 3)
            {
                std::cout << "|";

                if (currentCell->isWalkable())
                {
                    setConsoleColor(_greenColor);
                    std::cout << "       ";
                    setConsoleColor(_defaultColor);
                }
                else
                {
                    if (currentCell->isBlocked())
                    {
                        setConsoleColor(_defaultColor);
                        std::cout << "       ";
                        setConsoleColor(_defaultColor);
                    }
                    else
                    {
                        if (IControlable *controlable = dynamic_cast<IControlable *>(currentCell->getObject()))
                        {
                            setConsoleColor(_blueColor);
                            if (controlable->getDirection() == Directions::Down)
                            {
                                std::cout << "   v   ";
                            }
                            else
                            {
                                std::cout << "       ";
                            }
                            setConsoleColor(_defaultColor);
                        }
                        else
                        {
                            setConsoleColor(_redColor);
                            std::cout << "       ";
                            setConsoleColor(_defaultColor);
                        }
                    }
                }
            }

            std::cout << "|";
            std::cout << std::endl;
        }

        for (int j = 0; j < width; j++)
        {
            std::cout << "|=======";
        }

        std::cout << "|" << std::endl;

        grid->checkCell(level->getControlable());
    }
}

void DisplayManager::setConsoleColor(int color)
{
}