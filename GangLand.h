#ifndef gangland_H
#define gangland_H

#include "space.h"
#include "character.h"

#include <iostream>
using namespace std;

class GangLand : public Character{
    
    public:
    
        Space spaceGrid[5][5];
        
    public:
    
        // construtor
        GangLand();
    
        // Member Methods

        void runGame();
        // function that when called will run the whole game
    
        void moveCharacter(int diceRoll);
        // moves character to the space indicated by the diceRoll
        // changing the characters rowLocation and colLocation.
    
        int diceRoll();
        // returns a random in from 1 - 6
    
        int checkActivity();
        // will return an int indicating which activity the user has landed on, if any.
    
    
        // ----------- ACTIVITIES
    
        // to do add the functions for the activity spaces when landed on
        void activatedSpace();
        void emptySpace();
        void itemSpace();
        void lifeSpace();
        void moveSpace();
        void weaponSpace();
    
        // ----------- DRAWINGS
    
        void introDisplay();
        // displays intro banner and introduces the games rule and beginning story.
    
        void displayBoard();
        // displays the board with user location, spaces, and activity spots.
    
        void jumpedDisplay();
    
        void hustlersBlockDisplay();

        void lifeDisplay();
    
        void cripsDisplay();
    
        void safeDisplay();

        void bloodDisplay();
    
};

#endif // gangland_H























