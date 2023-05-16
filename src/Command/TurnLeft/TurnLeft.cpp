#include"TurnLeft.hpp"
    TurnLeft::TurnLeft(IControlable* cObj) {
        _cObj = cObj;
    }

    void TurnLeft::execute() override {
        rotate();
    }

    Commands TurnLeft::getEnum() override {
        return Commands::Left;
    }


    void TurnLeft::rotate() {
        switch (_cObj->GetDirection()) {
            case Directions::Up:
                _cObj->SetDirection(180);
                break;
            case Directions::Down:
                _cObj->SetDirection(0);
                break;
            case Directions::Left:
                _cObj->SetDirection(90);
                break;
            case Directions::Right:
                _cObj->SetDirection(270);
                break;
            default:
                break;
        }
    };
