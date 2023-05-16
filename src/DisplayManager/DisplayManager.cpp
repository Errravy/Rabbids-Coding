#include "DisplayManager.h"

void DisplayManager::SetConsoleColor(int color)
{
#ifdef _WIN32
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
#else
    // Assuming you have a cross-platform solution for setting console colors
    // Please replace this with the appropriate code for your platform
#endif
}

void DisplayManager::RenderLevel(Level& level)
{
    Grid& grid = level.GetGrid();
    grid.CheckCell(level.GetControlable());

    int width = grid.GetWidth();
    int height = grid.GetHeight();

    for (int i = 0; i < height * RENDER_HEIGHT_MULTIPLIER; i++)
    {
        for (int j = 0; j < width; j++)
        {
            Cell* currentCell = grid.GetCells()[std::make_pair(j, i / RENDER_HEIGHT_MULTIPLIER)];

            if (i % RENDER_HEIGHT_MULTIPLIER == 0)
            {
                std::cout << "|=======";
            }
            else if (i % RENDER_HEIGHT_MULTIPLIER == 1)
            {
                std::cout << "|";

                if (currentCell->IsWalkable())
                {
                    SetConsoleColor(GREEN_COLOR);
                    std::cout << "       ";
                }
                else
                {
                    if (currentCell->IsBlocked())
                    {
                        SetConsoleColor(DEFAULT_COLOR);
                        std::cout << "       ";
                    }
                    else
                    {
                        if (IControlable* controlable = dynamic_cast<IControlable*>(currentCell->GetObject()))
                        {
                            SetConsoleColor(BLUE_COLOR);
                            if (controlable->GetDirection() == Directions::Up)
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
                            SetConsoleColor(RED_COLOR);
                            std::cout << "       ";
                        }
                    }
                }

                SetConsoleColor(DEFAULT_COLOR);
            }
            else if (i % RENDER_HEIGHT_MULTIPLIER == 2)
            {
                std::cout << "|";

                if (currentCell->IsWalkable())
                {
                    SetConsoleColor(GREEN_COLOR);
                    std::cout << "   " << currentCell->GetCellObj() << "   ";
                }
                else
                {
                    if (currentCell->IsBlocked())
                    {
                        SetConsoleColor(DEFAULT_COLOR);
                        std::cout << "   " << currentCell->GetCellObj() << "   ";
                    }
                    else
                    {
                        if (IControlable* controlable = dynamic_cast<IControlable*>(currentCell->GetObject()))
                        {
                            SetConsoleColor(BLUE_COLOR);
                            if (controlable->GetDirection() == Directions::Right)
                            {
                                std::cout << "   " << currentCell->GetCellObj() << "   ";
                                std::cout << "   " << currentCell->GetCellObj() << " > ";
                            }
                            else if (controlable->GetDirection() == Directions::Left)
                            {
                                std::cout << " < " << currentCell->GetCellObj() << "   ";
                            }
                        }
                        else
                        {
                            SetConsoleColor(RED_COLOR);
                            std::cout << "   " << currentCell->GetCellObj() << "   ";
                        }
                    }
                }

                SetConsoleColor(DEFAULT_COLOR);
            }
            
            else if (i % RENDER_HEIGHT_MULTIPLIER == 3)
            {
                std::cout << "|";
                            if (currentCell->IsWalkable())
                {
                    SetConsoleColor(GREEN_COLOR);
                    std::cout << "       ";
                    SetConsoleColor(DEFAULT_COLOR);
                }
                else
                {
                    if (currentCell->IsBlocked())
                    {
                        SetConsoleColor(DEFAULT_COLOR);
                        std::cout << "       ";
                        SetConsoleColor(DEFAULT_COLOR);
                    }
                    else
                    {
                        if (IControlable* controlable = dynamic_cast<IControlable*>(currentCell->GetObject()))
                        {
                            SetConsoleColor(BLUE_COLOR);
                            if (controlable->GetDirection() == Directions::Down)
                            {
                                std::cout << "   v   ";
                            }
                            else
                            {
                                std::cout << "       ";
                            }
                            SetConsoleColor(DEFAULT_COLOR);
                        }
                        else
                        {
                            SetConsoleColor(RED_COLOR);
                            std::cout << "       ";
                            SetConsoleColor(DEFAULT_COLOR);
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

        grid.CheckCell(level.GetControlable());
    }
}
