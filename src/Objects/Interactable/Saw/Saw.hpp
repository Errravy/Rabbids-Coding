#pragma once
#include "../IInteractable.hpp"

class Saw: public IInteractable
{
    public :
        Saw();
        void react() override;
        
};