#pragma once

class Objects
{
    public:
        int posX;
        int posY;
        

    virtual bool isSucked();
    virtual void setPositionX(int x);
    virtual void setPositionY(int y);
    virtual void setPosition(int x, int y);
    virtual std::pair<int, int> getPosition();
    virtual std::string getObjectSymbol();

};