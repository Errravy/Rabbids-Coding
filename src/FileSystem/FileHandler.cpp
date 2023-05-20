#include "FileHandler.hpp"

fs::path FileHandler::getRelativePath(const std::string &filePath)
{
    return fs::current_path() / "src" / "Data" / filePath;
}