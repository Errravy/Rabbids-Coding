#pragma once

#ifndef DisplayManager_h
#define DisplayManager_h

#include <iostream>
#include <unordered_map>

#include "../Playspace/Level/Level.hpp"
#include "../Playspace/Cell/Cell.hpp"
#include "../Playspace/Grid/Grid.hpp"
#include "../Objects/Controlable/IControlable.hpp"

class DisplayManager
{
private:
    static const int _renderHeightMultiplier = 4;
    static const int _cellWidth = 7;
    static const int _cellHeight = 3;

    // Render colors
    static const int _redColor = 12;   // ConsoleColor::Red
    static const int _greenColor = 10; // ConsoleColor::Green
    static const int _blueColor = 9;   // ConsoleColor::Blue
    static const int _cyanColor = 11;  // ConsoleColor::Cyan
    static const int _defaultColor = 15;

    static void setConsoleColor(int);

public:
    static void renderLevel(Level &);
};

#endif
