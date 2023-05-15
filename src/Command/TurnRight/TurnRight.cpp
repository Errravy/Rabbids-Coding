class TurnRight : public ICommand {
private:
    IControlable* _cObj;

public:
    TurnRight(IControlable* cObj) {
        _cObj = cObj;
    }

    void Execute() override {
        Rotate();
    }

    Commands GetEnum() override {
        return Commands::Right;
    }

private:
    void Rotate() {
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
    }
};
