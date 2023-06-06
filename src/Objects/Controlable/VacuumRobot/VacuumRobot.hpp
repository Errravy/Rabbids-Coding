#pragma once

#include "../IControlable.hpp"
#include "../../../Command/ICommand.hpp"

class VacuumRobot : public IControlable
{
public:
    VacuumRobot();

    void setPositionX(int) override;
    void setPositionY(int) override;
    void setPosition(int, int) override;
    std::pair<int, int> getPosition() override;
    std::string getObjectSymbol() override;

    ICommand *setCommand(ICommand *) override;
    ICommand *getCommand(Commands) override;
    std::vector<std::string> getCommands() override;
    void setDirection(int) override;
    Directions getDirection() override;
};