#pragma once

#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

class FileHandler
{
public:
    static fs::path getRelativePath(const std::string &);
};