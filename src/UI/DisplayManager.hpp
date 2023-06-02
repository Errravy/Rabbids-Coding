#pragma once

#define RED "\x1b[47;41m"
#define GREEN "\x1b[47;42m"
#define BLUE "\x1b[47;44m"
#define CYAN "\x1b[47;46m"
#define YELLOW "\x1b[47;43m"
#define DEFAULT "\x1b[0m"

#define RENDER_HEIGHT_MULTIPLIER 4

#include "../Playspace/Level/Level.hpp"
#include "../Playspace/Grid/Grid.hpp"
#include "../Playspace/Cell/Cell.hpp"

class DisplayManager
{
private:
    static void setConsoleColor(const char *);

public:
    static void renderLevel(Level *);
};