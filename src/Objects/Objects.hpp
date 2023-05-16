#pragma once

class Objects
{
    public:
        int posX;
        int posY;
        

    bool IsSucked();
    void SetPositionX(int x);
    void SetPositionY(int y);
    void SetPosition(int x, int y);
    std::pair<int, int> GetPosition();
    std::string GetObjectSymbol();

};