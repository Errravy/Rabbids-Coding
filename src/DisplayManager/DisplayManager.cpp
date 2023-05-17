#include "DisplayManager.h"

void DisplayManager::setConsoleColor(int color)
{
#ifdef _WIN32
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
#else
    // Assuming you have a cross-platform solution for setting console colors
    // Please replace this with the appropriate code for your platform
#endif
}

void DisplayManager::renderLevel(Level &level)
{
    Grid &grid = level.getGrid();
    grid.checkCell(level.getControlable());

    int width = grid.getWidth();
    int height = grid.getHeight();

    for (int i = 0; i < height * renderHeightMultiplier; i++)
    {
        for (int j = 0; j < width; j++)
        {
            Cell *currentCell = grid.getCells()[std::make_pair(j, i / renderHeightMultiplier)];

            if (i % renderHeightMultiplier == 0)
            {
                std::cout << "|=======";
            }
            else if (i % renderHeightMultiplier == 1)
            {
                std::cout << "|";

                if (currentCell->isWalkable())
                {
                    setConsoleColor(greenColor);
                    std::cout << "       ";
                }
                else
                {
                    if (currentCell->isBlocked())
                    {
                        setConsoleColor(defaultColor);
                        std::cout << "       ";
                    }
                    else
                    {
                        if (IControlable *controlable = dynamic_cast<IControlable *>(currentCell->getObject()))
                        {
                            setConsoleColor(blueColor);
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
                            setConsoleColor(redColor);
                            std::cout << "       ";
                        }
                    }
                }

                setConsoleColor(defaultColor);
            }
            else if (i % renderHeightMultiplier == 2)
            {
                std::cout << "|";

                if (currentCell->isWalkable())
                {
                    setConsoleColor(greenColor);
                    std::cout << "   " << currentCell->getCellObj() << "   ";
                }
                else
                {
                    if (currentCell->isBlocked())
                    {
                        setConsoleColor(defaultColor);
                        std::cout << "   " << currentCell->getCellObj() << "   ";
                    }
                    else
                    {
                        if (IControlable *controlable = dynamic_cast<IControlable *>(currentCell->getObject()))
                        {
                            setConsoleColor(blueColor);
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
                            setConsoleColor(redColor);
                            std::cout << "   " << currentCell->getCellObj() << "   ";
                        }
                    }
                }

                setConsoleColor(defaultColor);
            }
            else if (i % renderHeightMultiplier == 3)
            {
                std::cout << "|";

                if (currentCell->isWalkable())
                {
                    setConsoleColor(greenColor);
                    std::cout << "       ";
                    setConsoleColor(defaultColor);
                }
                else
                {
                    if (currentCell->isBlocked())
                    {
                        setConsoleColor(defaultColor);
                        std::cout << "       ";
                        setConsoleColor(defaultColor);
                    }
                    else
                    {
                        if (IControlable *controlable = dynamic_cast<IControlable *>(currentCell->getObject()))
                        {
                            setConsoleColor(blueColor);
                            if (controlable->getDirection() == Directions::Down)
                            {
                                std::cout << "   v   ";
                            }
                            else
                            {
                                std::cout << "       ";
                            }
                            setConsoleColor(defaultColor);
                        }
                        else
                        {
                            setConsoleColor(redColor);
                            std::cout << "       ";
                            setConsoleColor(defaultColor);
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

        grid.checkCell(level.getControlable());
    }
