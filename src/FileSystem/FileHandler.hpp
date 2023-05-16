#ifndef FILEHANDLER_HPP
#define FILEHANDLER_HPP

#include <string>
#include <vector>
#include <filesystem>
#include <map>

namespace fs = std::filesystem;

class FileHandler
{
public:
    static std::string relativePath;

    static std::string GetAbsolutePath(const std::string &folderName);
    static std::vector<fs::path> GetAllLevelFiles(const std::string &folderName);

    template <typename T>
    static T ReadFromJson(const std::string &filePath);

    template <typename T>
    static void WriteToJson(const std::string &filePath, const T &data);
};

namespace CustomJson
{
    std::string Serialize(const std::map<std::string, std::string> &data);
    std::map<std::string, std::string> Deserialize(const std::string &json);
}

#endif // FILEHANDLER_HPP
