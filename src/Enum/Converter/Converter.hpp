#pragma once

#include <iostream>
#include <unordered_map>

#include "../Objects.hpp"
#include "../Commands.hpp"

class Converter
{
public:
    static Objects convertStringToObjects(const std::string &);
    static Commands convertStringToCommands(const std::string &);
};