#pragma once

#include <iostream>
#include <nlohmann/json.hpp>

#include "../../FileSystem/FileHandler.hpp"
#include "../../Playspace/Level/Level.hpp"

using json = nlohmann::json;

class DataPersistence
{
private:
    static DataPersistence *_instance;

public:
    struct GameData
    {
        std::string _levelName;
        int _score;
        bool _isCompleted;

        friend void to_json(json &, const GameData &);
    };

    static DataPersistence *getInstance();

    void saveGame(Level *);
};
