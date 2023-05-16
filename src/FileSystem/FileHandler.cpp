#include "FileHandler.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

std::string FileHandler::relativePath = "./Data";

std::string FileHandler::GetAbsolutePath(const std::string &folderName)
{
    return relativePath + "/" + folderName;
}

std::vector<fs::path> FileHandler::GetAllLevelFiles(const std::string &folderName)
{
    std::vector<fs::path> filePaths;
    std::string directoryPath = GetAbsolutePath(folderName);

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
T FileHandler::ReadFromJson(const std::string &filePath)
{
    std::ifstream fileStream(GetAbsolutePath(filePath));
    if (!fileStream.is_open())
    {
        throw std::runtime_error("Failed to open file: " + filePath);
    }

    std::ostringstream oss;
    oss << fileStream.rdbuf();
    std::string jsonContent = oss.str();

    fileStream.close();

    // Deserialize JSON string using custom implementation
    T data = CustomJson::Deserialize<T>(jsonContent);

    return data;
}

template <typename T>
void FileHandler::WriteToJson(const std::string &filePath, const T &data)
{
    std::ofstream fileStream(GetAbsolutePath(filePath));
    if (!fileStream.is_open())
    {
        throw std::runtime_error("Failed to open file: " + filePath);
    }

    // Serialize data to JSON string using custom implementation
    std::string jsonContent = CustomJson::Serialize(data);

    fileStream << jsonContent;
    fileStream.close();
}

namespace CustomJson
{
    // Serialize an object to JSON format
    std::string Serialize(const std::map<std::string, std::string> &data)
    {
        std::ostringstream oss;
        oss << "{";
        bool first = true;
        for (const auto &[key, value] : data)
        {
            if (!first)
            {
                oss << ",";
            }
            oss << "\"" << key << "\":\"" << value << "\"";
            first = false;
        }
        oss << "}";
        return oss.str();
    }

    // Deserialize a JSON string to an object
    std::map<std::string, std::string> Deserialize(const std::string &json)
    {
        std::map<std::string, std::string> data;
        std::string key, value;
        bool isKey = false;
        bool isValue = false;
        bool inString = false;
        for (char c : json)
        {
            if (c == '"')
            {
                inString = !inString;
            }
            else if (inString)
            {
                if (isKey)
                {
                    key += c;
                }
                else if (isValue)
                {
                    value += c;
                }
            }
            else
            {
                if (c == ':')
                {
                    isKey = false;
                    isValue = true;
                }
                else if (c == ',')
                {
                    data[key] = value;
                    key.clear();
                    value.clear();
                    isKey = true;
                    isValue = false;
                }
            }
        }
        if (!key.empty() && !value.empty())
        {
            data[key] = value;
        }
        return data;
    }
}