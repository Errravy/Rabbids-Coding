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

template <typename T>
void FileHandler::writeToJson(const std::string &filePath, const T &data)
{
    std::ifstream file(getRelativePath(filePath));

    if (file.is_open())
    {
        json jsonData;
        file >> jsonData;

        std::ofstream outputFile(getRelativePath(filePath));

        if (outputFile.is_open())
        {
            json newData = data;
            jsonData["datas"].push_back(newData);

            outputFile << jsonData.dump(4);
            return;
        }

        throw std::runtime_error("Failed to open file: " + filePath);
    }
}

template LevelManager::LevelData FileHandler::readFromJson<LevelManager::LevelData>(const std::string &);
template void FileHandler::writeToJson<DataPersistence::GameData>(const std::string &, const DataPersistence::GameData &);