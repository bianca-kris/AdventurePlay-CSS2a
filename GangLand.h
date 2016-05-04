#ifndef gangland_H
#define gangland_H

#include "space.h"
#include "character.h"

#include <iostream>
using namespace std;

class GangLand : public Character{
    
    private:
    
        Space boardGrid[5][5];
    
    public:
    
        GangLand();
    
    
    
    
    
        // Member Methods
    
        void introDisplay();
        void displayBoard();
    
    
    
};

#endif // gangland_H
