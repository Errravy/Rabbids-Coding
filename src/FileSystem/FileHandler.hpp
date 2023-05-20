#pragma once

#include <iostream>
#include <filesystem>
#include <vector>

namespace fs = std::filesystem;

class FileHandler
{
public:
    static fs::path getRelativePath(const std::string &);
    static std::vector<fs::path> getAllFilesInDirectory(const std::string &);
};