#ifndef DISPLAYMANAGER_H
#define DISPLAYMANAGER_H

#include <iostream>
#include <unordered_map>
#include "Level.h" // Assuming the header file for Level is included

class DisplayManager
{
private:
    static const int RENDER_HEIGHT_MULTIPLIER = 4;
    static const int CELL_WIDTH = 7;
    static const int CELL_HEIGHT = 3;

    // Render colors
    static const int RED_COLOR = 12;   // ConsoleColor::Red
    static const int GREEN_COLOR = 10; // ConsoleColor::Green
    static const int BLUE_COLOR = 9;   // ConsoleColor::Blue
    static const int CYAN_COLOR = 11;  // ConsoleColor::Cyan
    static const int DEFAULT_COLOR = 15;

    static void SetConsoleColor(int color);

public:
    static void RenderLevel(Level& level);
};

#endif // DISPLAYMANAGER_H
