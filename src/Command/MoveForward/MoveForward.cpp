#include "MoveForward.hpp"

MoveForward::MoveForward(IControlable* cObj) {
    _cObj = cObj;
}

void MoveForward::execute() override {
    moveByDirection();
}

Commands MoveForward::getEnum() override {
    return Commands::Forward;
}

void MoveForward::moveByDirection() {
    switch (_cObj->GetDirection()) {
    case Directions::Up:
         _cObj->setPositionY(_cObj->getPosition().y - 1);
        break;
    case Directions::Down:
        _cObj->setPositionY(_cObj->getPosition().y + 1);
        break;
    case Directions::Left:
        _cObj->setPositionX(_cObj->getPosition().x - 1);
        break;
    case Directions::Right:
        _cObj->setPositionX(_cObj->getPosition().x + 1);
        break;
    default:
        break;
    }
}