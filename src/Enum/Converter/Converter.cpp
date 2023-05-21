#include "Converter.hpp"

Objects Converter::convertStringToObjects(const std::string &objectType)
{
    static const std::unordered_map<std::string, Objects> objectMap{
        {"Rabbids", Objects::Rabbids},
        {"Button", Objects::Button},
        {"Bag", Objects::Bag}};

    auto it = objectMap.find(objectType);
    if (it != objectMap.end())
    {
        return it->second;
    }

    throw std::runtime_error("Failed to convert: " + objectType + " to Objects enum");
}

Commands Converter::convertStringToCommands(const std::string &commandType)
{
    static const std::unordered_map<std::string, Commands> commandMap{
        {"Forward", Commands::Forward},
        {"Backward", Commands::Backward},
        {"Left", Commands::Left},
        {"Right", Commands::Right}};

    auto it = commandMap.find(commandType);
    if (it != commandMap.end())
    {
        return it->second;
    }

    throw std::runtime_error("Failed to convert: " + commandType + " to Commands enum");
}