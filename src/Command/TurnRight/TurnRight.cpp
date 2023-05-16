#include"TurnRight.hpp"
    TurnRight::TurnRight(IControlable* cObj) {
        _cObj = cObj;
    }

    void TurnRight::execute() override {
        rotate();
    }

    Commands TurnRight::getEnum() override {
        return Commands::Right;
    }


    void TurnRight::rotate() {
        switch (_cObj->GetDirection()) {
            case Directions::Up:
                _cObj->SetDirection(0);
                break;
            case Directions::Down:
                _cObj->SetDirection(180);
                break;
            case Directions::Left:
                _cObj->SetDirection(270);
                break;
            case Directions::Right:
                _cObj->SetDirection(90);
                break;
            default:
                break;
        }
    };
