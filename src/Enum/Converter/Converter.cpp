#include "Converter.hpp"

Objects Converter::convertStringToObjects(const std::string &objectType)
{
    static const std::unordered_map<std::string, Objects> objectMap{
        {"Button", Objects::Button},
        {"ElectricFence", Objects::ElectricFence},
        {"Rabbids", Objects::Rabbids},
        {"IdleRabbids", Objects::IdleRabbids},
        {"WashingMachine", Objects::WashingMachine},
        {"VacuumRobot", Objects::VacuumRobot},
        {"ArmedRabbids", Objects::ArmedRabbids},
        {"ClawRobot", Objects::ClawRobot},
        {"Plunger", Objects::Plunger},
        {"Bomb", Objects::Bomb},
        {"Bag", Objects::Bag},
        {"Bubble", Objects::Bubble},
        {"Soap", Objects::Soap},
        {"CardBox", Objects::CardBox},
        {"Ring", Objects::Ring},
        {"Sausage", Objects::Sausage},
        {"Saw", Objects::Saw},
        {"Tissue", Objects::Tissue},
        {"ToiletPaper", Objects::ToiletPaper},
        {"WateringCan", Objects::WateringCan},
    };

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
        {"Right", Commands::Right},
        {"Interact", Commands::Interact},
    };

    auto it = commandMap.find(commandType);
    if (it != commandMap.end())
    {
        return it->second;
    }

    throw std::runtime_error("Failed to convert: " + commandType + " to Commands enum");
}

Objectives Converter::convertStringToObjectives(const std::string &objectiveType)
{
    static const std::unordered_map<std::string, Objectives> objectiveMap{
        {"FinishLine", Objectives::FinishLine},
    };

    auto it = objectiveMap.find(objectiveType);
    if (it != objectiveMap.end())
    {
        return it->second;
    }

    throw std::runtime_error("Failed to convert: " + objectiveType + " to Objectives enum");
}