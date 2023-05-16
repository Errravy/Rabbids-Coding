#ifndef DisplayManager_h
#define DisplayManager_h

#include <iostream>
#include <unordered_map>
#include "Level.h" // Assuming the header file for Level is included

class DisplayManager {
private:
    static const int renderHeightMultiplier = 4;
    static const int cellWidth = 7;
    static const int cellHeight = 3;

    // Render colors
    static const int redColor = 12;   // ConsoleColor::Red
    static const int greenColor = 10; // ConsoleColor::Green
    static const int blueColor = 9;   // ConsoleColor::Blue
    static const int cyanColor = 11;  // ConsoleColor::Cyan
    static const int defaultColor = 15;

    static void setConsoleColor(int color);

public:
    static void renderLevel(Level& level);
};

#endif /* DisplayManager_h */
