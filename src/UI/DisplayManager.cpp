#include "DisplayManager.hpp"

void DisplayManager::renderLevel(Level *level)
{
    system("cls");

    Grid *grid = level->getGrid();
    grid->checkCell(level->getControlable());

    int gridWidth = grid->getWidth();
    int gridHeight = grid->getHeight();

    int x = 0;
    int y = 0;

    for (int i = 0; i < gridHeight * _renderHeightMultiplier; i++)
    {
        if (i % 4 == 0)
        {
            for (int j = 0; j < gridWidth; j++)
            {
                std::cout << "|=======";
            }

            std::cout << "|";
        }

        if (i % 4 == 1)
        {
            for (int j = 0; j < gridWidth; j++)
            {
                Cell *currentCell = grid->getCells()[std::make_pair(x, y)];

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
                x++;
            }

            std::cout << "|";
            x = 0;
        }

        if (i % 4 == 2)
        {
            for (int j = 0; j < gridWidth; j++)
            {
                Cell *currentCell = grid->getCells()[std::make_pair(x, y)];

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
                                std::cout << "   " << currentCell->getCellObj() << " > ";
                            }
                            else if (controlable->getDirection() == Directions::Left)
                            {
                                std::cout << " < " << currentCell->getCellObj() << "   ";
                            }
                            else
                            {
                                std::cout << "   " << currentCell->getCellObj() << "   ";
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
                x++;
            }

            std::cout << "|";
            x = 0;
        }

        if (i % 4 == 3)
        {
            for (int j = 0; j < gridWidth; j++)
            {
                Cell *currentCell = grid->getCells()[std::make_pair(x, y)];

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
                        }
                    }
                }

                setConsoleColor(_defaultColor);
                x++;
            }

            std::cout << "|";
            x = 0;
            y++;
        }

        std::cout << std::endl;
    }

    for (int j = 0; j < gridWidth; j++)
    {
        std::cout << "|=======";
    }

    std::cout << "|" << std::endl;

    grid->checkCell(level->getControlable());
}

void DisplayManager::setConsoleColor(int color)
{
}