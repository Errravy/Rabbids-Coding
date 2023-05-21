#pragma once

#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <vector>
#include <map>

#include "../Core/LevelManager/LevelManager.hpp"

using json = nlohmann::json;
namespace fs = std::filesystem;

class FileHandler
{
public:
    static fs::path getRelativePath(const std::string &);
    static std::vector<fs::path> getAllFilesInDirectory(const std::string &);

    template <typename T>
    static T readFromJson(const std::string &);
};
