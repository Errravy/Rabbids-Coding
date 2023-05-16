#include "Grid.h"

// Constructor
Grid::Grid(int width, int height)
{
    InitializeGridAndCell(width, height);
    GenerateGrid();
}

// Private methods
void Grid::InitializeGridAndCell(int width, int height)
{
    this->width = width;
    this->height = height;
    grid = new std::string*[width];
    for (int x = 0; x < width; x++)
    {
        grid[x] = new std::string[height];
    }
}

void Grid::GenerateGrid()
{
    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            temp++;
            grid[x][y] = std::to_string(temp);
            cells[std::make_pair(x, y)] = new Cell(x, y);
        }
    }
}

// Public methods
void Grid::CheckCell(IObjects* obj)
{
    if (previousCell == nullptr)
    {
        previousCell = cells[obj->GetPosition()];
        previousObject = obj;
    }
    else
    {
        previousCell->CheckObject(previousObject);
        previousCell = cells[obj->GetPosition()];
        previousObject = obj;
    }

    std::pair<int, int> position = obj->GetPosition();
    if (position.first < width && position.second < height)
    {
        cells[position]->CheckObject(obj);
    }
    else
    {
        std::cout << "Object is out of grid!" << std::endl;
    }
}

void Grid::CheckGridPos(int x, int y)
{
    std::cout << grid[x][y] << std::endl;
}

int Grid::GetWidth()
{
    return width;
}

int Grid::GetHeight()
{
    return height;
}

std::unordered_map<std::pair<int, int>, Cell*, CellHash>& Grid::GetCells()
{
    return cells;
}
