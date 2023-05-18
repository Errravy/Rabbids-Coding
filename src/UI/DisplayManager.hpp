#pragma once

#include "../Playspace/Level/Level.hpp"
#include "../Playspace/Grid/Grid.hpp"
#include "../Playspace/Cell/Cell.hpp"

class DisplayManager
{
private:
    static const int _renderHeightMultiplier = 4;

    // Render colors
    static const int _redColor = 12;   // ConsoleColor::Red
    static const int _greenColor = 10; // ConsoleColor::Green
    static const int _blueColor = 9;   // ConsoleColor::Blue
    static const int _cyanColor = 11;  // ConsoleColor::Cyan
    static const int _defaultColor = 15;

    static void setConsoleColor(int);

public:
    static void renderLevel(Level *);
};