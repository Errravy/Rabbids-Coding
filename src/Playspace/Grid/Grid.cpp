#include "Grid.hpp"

Grid::Grid(int width, int height) {
    InitializeGridAndCell(width, height);
    GenerateGrid();
}

void Grid::InitializeGridAndCell(int width, int height) {
    this->width = width;
    this->height = height;
    grid = new std::string*[width];
    for (int x = 0; x < width; x++) {
        grid[x] = new std::string[height];
    }
}

void Grid::GenerateGrid() {
    int temp = 0;
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            temp++;
            grid[x][y] = std::to_string(temp);
            cells[std::make_pair(x, y)] = new Cell(x, y);
        }
    }
}

void Grid::CheckCell(IObjects* obj) {
    if (previousCell == nullptr) {
        previousCell = cells[obj->getPosition()];
        previousObject = obj;
    } else {
        previousCell->checkObject(previousObject);
        previousCell = cells[obj->getPosition()];
        previousObject = obj;
    }

    std::pair<int, int> position = obj->getPosition();
    if (position.first < width && position.second < height) {
        cells[position]->checkObject(obj);
    } else {
        std::cout << "Object is out of grid!" << std::endl;
    }
}

void Grid::CheckGridPos(int x, int y) {
    std::cout << grid[x][y] << std::endl;
}

int Grid::GetWidth() {
    return width;
}

int Grid::GetHeight() {
    return height;
}

std::map<std::pair<int, int>, Cell*> Grid::GetCells() {
    return cells;
}
