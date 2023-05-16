class IControlable : public IObjects {
public:
    virtual ICommand* setCommand(ICommand* command) = 0;
    virtual ICommand* getCommand(Commands commands) = 0;
    virtual void setDirection(int direction) = 0;
    virtual Directions getDirection() = 0;
    
};