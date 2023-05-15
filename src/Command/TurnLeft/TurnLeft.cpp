class TurnLeft : public ICommand {
private:
    IControlable* _cObj;

public:
    TurnLeft(IControlable* cObj) {
        _cObj = cObj;
    }

    void Execute() override {
        Rotate();
    }

    Commands GetEnum() override {
        return Commands::Left;
    }

private:
    void Rotate() {
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
    }
};
