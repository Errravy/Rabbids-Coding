#include "FileHandler.hpp"

fs::path FileHandler::getRelativePath(const std::string &filePath)
{
    return fs::current_path() / "src" / "Data" / filePath;
}

std::vector<fs::path> FileHandler::getAllFilesInDirectory(const std::string &fileDirectory)
{
    std::vector<fs::path> filePaths;
    fs::path directoryPath = getRelativePath(fileDirectory);

    for (const auto &entry : fs::directory_iterator(directoryPath))
    {
        if (entry.is_regular_file())
        {
            filePaths.push_back(entry.path());
        }
    }

    return filePaths;
}

template <typename T>
T FileHandler::readFromJson(const std::string &filePath)
{
    std::ifstream file(getRelativePath(filePath));

    if (file.is_open())
    {
        json jsonData;
        file >> jsonData;
        return jsonData.get<T>();
    }

    throw std::runtime_error("Failed to open file: " + filePath);
}

template LevelManager::LevelData FileHandler::readFromJson<LevelManager::LevelData>(const std::string &);