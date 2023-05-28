#include "DataPersistence.hpp"

DataPersistence *DataPersistence::_instance = nullptr;

DataPersistence *DataPersistence::getInstance()
{
    if (_instance == nullptr)
    {
        _instance = new DataPersistence();
    }

    return _instance;
}

void DataPersistence::saveGame(Level *currentLevel)
{
    // FIXME: This is just a dummy score
    int randomScore = 1 + (rand() % 100);
    GameData gameData;
    gameData._levelName = currentLevel->getLevelName();
    gameData._score = randomScore;
    gameData._isCompleted = currentLevel->isCompleted();

    FileHandler::writeToJson<DataPersistence::GameData>("GameProgress/UserData.json", gameData);
}

void to_json(json &j, const DataPersistence::GameData &gameData)
{
    j = json{
        {"levelName", gameData._levelName},
        {"score", gameData._score},
        {"isCompleted", gameData._isCompleted}};
}