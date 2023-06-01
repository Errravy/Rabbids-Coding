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

    for (int i = 0; i < gridHeight * RENDER_HEIGHT_MULTIPLIER; i++)
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
                    setConsoleColor(GREEN);
                    std::cout << "       ";
                }
                else
                {
                    if (currentCell->isBlocked())
                    {
                        setConsoleColor(DEFAULT);
                        std::cout << "       ";
                    }
                    else
                    {
                        if (IControlable *controlable = dynamic_cast<IControlable *>(currentCell->getCurrentControlableObject()))
                        {
                            setConsoleColor(BLUE);

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
                            setConsoleColor(RED);
                            std::cout << "       ";
                        }
                    }
                }

                setConsoleColor(DEFAULT);
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
                    setConsoleColor(GREEN);
                    std::cout << "   " << currentCell->getCellObjectSymbol() << "   ";
                }
                else
                {
                    if (currentCell->isBlocked())
                    {
                        setConsoleColor(DEFAULT);
                        std::cout << "   " << currentCell->getCellObjectSymbol() << "   ";
                    }
                    else
                    {
                        if (currentCell->getCurrentControlableObject() != nullptr && currentCell->getCurrentObject() != nullptr)
                        {
                            setConsoleColor(BLUE);

                            IControlable *controlable = dynamic_cast<IControlable *>(currentCell->getCurrentControlableObject());

                            if (controlable->getDirection() == Directions::Right)
                            {
                                std::cout << "" << currentCell->getCellObjectSymbol() << " > / " << currentCell->getCurrentObject()->getObjectSymbol() << "";
                            }
                            else if (controlable->getDirection() == Directions::Left)
                            {
                                std::cout << "< " << currentCell->getCellObjectSymbol() << " / " << currentCell->getCurrentObject()->getObjectSymbol() << "";
                            }
                            else
                            {
                                std::cout << " " << currentCell->getCellObjectSymbol() << " / " << currentCell->getCurrentObject()->getObjectSymbol() << " ";
                            }
                        }
                        else
                        {
                            if (IControlable *controlable = dynamic_cast<IControlable *>(currentCell->getCurrentControlableObject()))
                            {
                                setConsoleColor(BLUE);

                                if (controlable->getDirection() == Directions::Right)
                                {
                                    std::cout << "   " << currentCell->getCellObjectSymbol() << " > ";
                                }
                                else if (controlable->getDirection() == Directions::Left)
                                {
                                    std::cout << " < " << currentCell->getCellObjectSymbol() << "   ";
                                }
                                else
                                {
                                    std::cout << "   " << currentCell->getCellObjectSymbol() << "   ";
                                }
                            }
                            else
                            {
                                setConsoleColor(RED);
                                std::cout << "   " << currentCell->getCellObjectSymbol() << "   ";
                            }
                        }
                    }
                }

                setConsoleColor(DEFAULT);
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
                    setConsoleColor(GREEN);
                    std::cout << "       ";
                    setConsoleColor(DEFAULT);
                }
                else
                {
                    if (currentCell->isBlocked())
                    {
                        setConsoleColor(DEFAULT);
                        std::cout << "       ";
                        setConsoleColor(DEFAULT);
                    }
                    else
                    {
                        if (IControlable *controlable = dynamic_cast<IControlable *>(currentCell->getCurrentControlableObject()))
                        {
                            setConsoleColor(BLUE);

                            if (controlable->getDirection() == Directions::Down)
                            {
                                std::cout << "   v   ";
                            }
                            else
                            {
                                std::cout << "       ";
                            }

                            setConsoleColor(DEFAULT);
                        }
                        else
                        {
                            setConsoleColor(RED);
                            std::cout << "       ";
                        }
                    }
                }

                setConsoleColor(DEFAULT);
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

void DisplayManager::setConsoleColor(const char *color)
{
    std::cout << color;
}