#include "Gangland.h"
#include "Space.h"

#include <ctime>    // time
#include <cstdlib>  // rand()
#include <cmath>    // abs()
#include <iostream>
using namespace std;



GangLand::GangLand(){
    
    setEnergyLevel(100);
    
    setRowLocation(0);
    setColLocation(0);
    
    // just to set all variables to false
    
    for (int y = 0; y < 5; y++) {
        
        for (int x = 0; x < 5; x++) {
            
            spaceGrid[x][y].setIsMoveSpace(false);
            spaceGrid[x][y].setIsActivated(false);
            spaceGrid[x][y].setIsLifeSpace(false);
            spaceGrid[x][y].setIsItem(false);
            spaceGrid[x][y].setHasWeapon(false);
            spaceGrid[x][y].setIsSpace(false);
        }
    }
    
    
    
    // assigning the board
    
    spaceGrid[0][0].setIsSpace(true);
    spaceGrid[1][0].setIsSpace(true);
    spaceGrid[2][0].setIsActivated(true);
    spaceGrid[3][0].setIsSpace(true);
    spaceGrid[4][0].setIsLifeSpace(true);
    
    spaceGrid[0][1].setIsLifeSpace(true);
    spaceGrid[1][1].setHasWeapon(true);
    spaceGrid[2][1].setIsMoveSpace(true);
    spaceGrid[3][1].setIsSpace(true);
    spaceGrid[4][1].setIsItem(true);
    
    spaceGrid[0][2].setIsActivated(true);
    spaceGrid[1][2].setIsSpace(true);
    spaceGrid[2][2].setIsSpace(true);
    spaceGrid[3][2].setIsItem(true);
    spaceGrid[4][2].setIsSpace(true);
    
    spaceGrid[0][3].setIsSpace(true);
    spaceGrid[1][3].setIsSpace(true);
    spaceGrid[2][3].setHasWeapon(true);
    spaceGrid[3][3].setIsSpace(true);
    spaceGrid[4][3].setIsActivated(true);
    
    spaceGrid[0][4].setIsItem(true);
    spaceGrid[1][4].setIsLifeSpace(true);
    spaceGrid[2][4].setIsActivated(true);
    spaceGrid[3][4].setIsMoveSpace(true);
    spaceGrid[4][4].setIsSpace(true);

}

//***********************************************************************************************************************

void GangLand::displayBoard(){
    
    cout << endl << endl
         << "\t\t   M A P " << endl << endl;

    
    for (int y = 0; y < 5; y++) {
        
        for (int x = 0; x < 5; x++) {
            
            // display user's location
            if (getColLocation() == y && getRowLocation() == x ) {
                
                cout << "\t X ";
            }
            // display finish line
            else if (y == 4 && x == 4){
                
                cout << "\t F ";
            }
            // display acitivity location
            else if (spaceGrid[x][y].getIsLifespace() ||
                     spaceGrid[x][y].getIsActivated() ||
                     spaceGrid[x][y].getHasWeapon() ||
                     spaceGrid[x][y].getIsItem() ||
                     spaceGrid[x][y].getIsMoveSpace() ){
                
                cout << "\t ! ";
            }
            // display starting location
            else if(y == 0 && x == 0){
                
                cout << "\t S ";
            }
            // display empty space
            else{
                
                cout << "\t * ";
            }
            

            
        } // x
    
        cout << endl << endl;
        
    } // y
    
    cout << endl << "Life percentage: " << getEnergyLevel() << endl << endl;
    cout << endl
         << "Location:" << endl
         << "\t\t  Column: " << getColLocation() << endl
         << "\t\t  Row: " << getRowLocation() << endl << endl;
    
}

//***********************************************************************************************************************

//----------------------------------------------DRAWINGS

//***********************************************************************************************************************

void GangLand::introDisplay(){
    
    cout << endl << endl
    << "         ....        .                                          " << endl
    << "      .x88' `^x~  xH(`                                          " << endl
    << "     X888   x8 ` 8888h                  u.    u.                " << endl
    << "    88888  888.  %8888         u      x@88k u@88c.      uL      " << endl
    << "   <8888X X8888   X8?       us888u.  ^'8888''8888'  .ue888Nc..  " << endl
    << "   X8888> 488888>'8888x  .@88 '8888'   8888  888R  d88E`'888E`  " << endl
    << "   X8888>  888888 '8888L 9888  9888    8888  888R  888E  888E   " << endl
    << "   ?8888X   ?8888>'8888X 9888  9888    8888  888R  888E  888E   " << endl
    << "    8888X h  8888 '8888~ 9888  9888    8888  888R  888E  888E   " << endl
    << "     ?888  -:8*'  <888'  9888  9888   '*88*' 8888' 888& .888E   " << endl
    << "      `*88.      :88%    '888*''888'    ''   'Y'   *888' 888&   " << endl
    << "         ^'~====''`       ^Y'   ^Y'                 `'   '888E  " << endl
    << "                                                   .dWi   `88E  " << endl
    << "                                                   4888~  J8%   " << endl
    << "                                                    ^'===*'`    " << endl
    << "                                 ^                              " << endl
    << "                                | |                             " << endl
    << "                              @#####@                           " << endl
    << "                            (###   ###)-.                       " << endl
    << "                          .(###     ###) \\                      " << endl
    << "                         /  (###   ###)   )                     " << endl
    << "                         (=-  .@#####@|_--'                     " << endl
    << "                        /\\    \\_|l|_/ (\\                        " << endl
    << "                        (=-\\     |l|    /                       " << endl
    << "                         \\  \\.___|l|___/                        " << endl
    << "                         /\\      |_|   /                        " << endl
    << "                         (=-\\._________/\\                       " << endl
    << "                          \\             /                       " << endl
    << "                           \\._________/                         " << endl
    << "                             #  ----  #                         " << endl
    << "                             #   __   #                         " << endl
    << "                             \\########/                         " << endl
    << "              ...                                   ..          " << endl
    << "          .zf'` `'tu                              dF            " << endl
    << "         x88      '8N.                u.    u.   '88bu.         " << endl
    << "         888k     d88&       u      x@88k u@88c. '*88888bu      " << endl
    << "         8888N.  @888F    us888u.  ^'8888''8888'   ^'*8888N     " << endl
    << "         `88888 9888%  .@88 '8888'   8888  888R   beWE '888L    " << endl
    << "           %888 '88F   9888  9888    8888  888R   888E  888E    " << endl
    << "            8'   '*h=~ 9888  9888    8888  888R   888E  888E    " << endl
    << "          z8Weu        9888  9888    8888  888R   888E  888F    " << endl
    << "         ''88888i.   Z 9888  9888   '*88*' 8888' .888N..888     " << endl
    << "        '   '8888888*  '888*''888'    ''   'Y'    `'888*''      " << endl
    << "              ^'**''    ^Y'   ^Y'                    ''         " << endl << endl << endl;
    
}

//***********************************************************************************************************************

void GangLand::jumpedDisplay(){
    
    // displays "Jumped"

    cout << "          ____  ____   ____      ______  _______        _____        ______        _____     " << endl
         << "         |    ||    | |    |    |      \\/       \\   ___|\\    \\   ___|\\     \\   ___|\\    \\    " << endl
         << "         |    ||    | |    |   /          /\\     \\ |    |\\    \\ |     \\     \\ |    |\\    \\   " << endl
         << "         |    ||    | |    |  /     /\\   / /\\     ||    | |    ||     ,_____/||    | |    |  " << endl
         << "   ____  |    ||    | |    | /     /\\ \\_/ / /    /||    |/____/||     \\--'\\_|/|    | |    |  " << endl
         << "  |    | |    ||    | |    ||     |  \\|_|/ /    / ||    ||    |||     /___/|  |    | |    |  " << endl
         << "  |    | |    ||    | |    ||     |       |    |  ||    ||____|/|     \\____|\\ |    | |    |  " << endl
         << "  |\\____\\|____||\\___\\_|____||\\____\\       |____|  /|____|       |____ '     /||____|/____/|  " << endl
         << "  | |    |    || |    |    || |    |      |    | / |    |       |    /_____/ ||    /    | |  " << endl
         << "   \\|____|____| \\|____|____| \\|____|      |____|/  |____|       |____|     | /|____|____|/   " << endl
         << "      \\(   )/      \\(   )/      \\(          )/       \\(           \\( |_____|/   \\(    )/     " << endl
         << "       '   '        '   '        '          '         '            '    )/       '    '      " << endl
         << endl << endl;
}

//***********************************************************************************************************************

void GangLand::hustlersBlockDisplay(){

    cout << "    ___ ___                 __  .__              /\\                 " << endl
         << "   /   |   \\ __ __  _______/  |_|  |   __________)/ ______          " << endl
         << "  /    ~    \\  |  \\/  ___/\\   __\\  | _/ __ \\_  __ \\/  ___/     " << endl
         << "  \\    Y    /  |  /\\___ \\  |  | |  |_\\  ___/|  | \\/\\___ \\     " << endl
         << "   \\___|_  /|____//____  > |__| |____/\\___  >__|  /____  >         " << endl
         << "         \\/            \\/                 \\/           \\/        " << endl
         << "         __________.__                 __                            " << endl
         << "         \\______   \\  |   ____   ____ |  | __                      " << endl
         << "          |    |  _/  |  /  _ \\_/ ___\\|  |/ /                      " << endl
         << "          |    |   \\  |_(  <_> )  \\___|    <                       " << endl
         << "          |______  /____/\\____/ \\___  >__|_ \\                     " << endl
         << "                 \\/                 \\/     \\/                     " << endl
         << endl << endl;

}

//***********************************************************************************************************************

void GangLand::lifeDisplay(){

    cout << endl
         << "   __    __  ____  ____    _     " << endl
         << "  (  )  (  )(  __)(  __)  / \\    " << endl
         << "  / (_/\\ )(  ) _)  ) _)   \\_/    " << endl
         << "  \\____/(__)(__)  (____)  (_)    " << endl
         << endl << endl;

}

//***********************************************************************************************************************

void GangLand::cripsDisplay(){
    

    cout << "    ______             __                            " << endl
         << "   /      \\           |  \\                         " << endl
         << "  |  $$$$$$\\  ______   \\$$  ______    _______      " << endl
         << "  | $$   \\$$ /      \\ |  \\ /      \\  /       \\  " << endl
         << "  | $$      |  $$$$$$\\| $$|  $$$$$$\\|  $$$$$$$     " << endl
         << "  | $$   __ | $$   \\$$| $$| $$  | $$ \\$$    \\     " << endl
         << "  | $$__/  \\| $$      | $$| $$__/ $$ _\\$$$$$$\\    " << endl
         << "   \\$$    $$| $$      | $$| $$    $$|       $$      " << endl
         << "    \\$$$$$$  \\$$       \\$$| $$$$$$$  \\$$$$$$$    " << endl
         << "                          | $$                       " << endl
         << "                          | $$                       " << endl
         << "                           \\$$                      " << endl
         << endl << endl;

}

//***********************************************************************************************************************

void GangLand::safeDisplay(){

    cout << "   _______  _______  _______  _______    _   " << endl
         << "  (  ____ \\(  ___  )(  ____ \\(  ____ \\  ( )  " << endl
         << "  | (    \\/| (   ) || (    \\/| (    \\/  | |  " << endl
         << "  | (_____ | (___) || (__    | (__      | |  " << endl
         << "  (_____  )|  ___  ||  __)   |  __)     | |  " << endl
         << "        ) || (   ) || (      | (        (_)  " << endl
         << "  /\\____) || )   ( || )      | (____/\\   _   " << endl
         << "  \\_______)|/     \\||/       (_______/  (_)  " << endl
         << endl << endl;

}

//***********************************************************************************************************************

void GangLand::bloodDisplay(){

    cout << "//  .------..------..------..------..------..------.       " << endl
         << "//  |B.--. ||L.--. ||O.--. ||O.--. ||D.--. ||S.--. |       " << endl
         << "//  | :(): || :/\\: || :/\\: || :/\\: || :/\\: || :/\\: |  " << endl
         << "//  | ()() || (__) || :\\/: || :\\/: || (__) || :\\/: |    " << endl
         << "//  | '--'B|| '--'L|| '--'O|| '--'O|| '--'D|| '--'S|       " << endl
         << "//  `------'`------'`------'`------'`------'`------'       " << endl
         << endl << endl;

}

//***********************************************************************************************************************

//                                                  RUN GAME

//***********************************************************************************************************************

void GangLand::runGame(){
    
    srand(time(0));

    
    setEnergyLevel(100);
    
    int quit = 0;
    
    do{
    
        // --------------------------------------------------- intro (start)
        
        introDisplay();
    
        string name = "";
        //char sex = ' ';
    
        cout << "Welcome to Gang Land" << endl
             << "Yes you read right, GANG LAND!" << endl
             << "You ended up in one of the world's worst towns and there is only one way out." << endl
             << "The sad part is it will not be pretty." << endl
             << "Your strength and luck will be put to the test." << endl << endl
             << "First off, let's get to know each other," << endl
             << "My homies call me Lil' Joker. " << endl
             << "and I will be narrating your death.. OH SH*T! I mean your journey." << endl
             << "Whatever, so What's your name foo?" << endl << endl;
        cin >> name;
    
        /*
        cout << endl << endl
             << "Orale " << name << " nice to meet you blood." << endl
             << "What gender are you, it is 2016 and I can't tell by your name." << endl
             << "Enter M for male and F for female." << endl << endl;
        cin >> sex;
    
        sex = toupper(sex);
    
        if (sex != 'M' && sex != 'F' ) {
        
            cout << "Since you did not enter male or female. " << endl
                 << "We're going to make you a female." << endl;
        
            sex = 'F';
        }
        
        */
    
        cout << endl
             << "Alright koo homie, well lets start it off cause it's getting darker." << endl
             << "We ain't rich around here so we'll be using a high-tech" << endl
             << "State of the art two dimensional map of the hood" << endl << endl
             << "(FYI hood is short for neighborhood), I don't know if you know what I mean bruh." << endl << endl
             << "Anyways, here is the map." << endl << endl
             << " X marks your spot on the game board." << endl
             << " ! is an active spot - it can mean danger or safety" << endl
             << "   But who we kidding, we're in the hood, so it means danger, oh and" << endl
             << " F is the finish line" << endl << endl;
    
        displayBoard();
    
        cout << "I know, the map isn't amazing" << endl
             << "My cousin Big Joker stole it from microsoft" << endl
             << "It was the beta or something," << endl
             << "but whatever, what can you expect from them anyway right, it isn't apple." << endl
             << "GOOD LUCK! (you'll need it)" << endl << endl;
    
        // --------------------------------------------------- intro (end)
    
    
        cout << "Alright then bruh, around here life is a gamble." << endl
             << "and that is exactly how you'll move." << endl
             << "Lets roll the dice and see what square you land on." << endl << endl;
        
        
        // -------------------------------------------------- gameplay loop
        // will run until the user reaches the finish line
        
        
        int roll;
        
        do {
            
            if (getEnergyLevel() <= 0) {
                
                cout << endl << endl
                     << "You died!" << endl << endl;
                
                break;
            }
            
            
            
            cout << "===========================================================================" << endl << endl;
            
            roll = diceRoll();
            
            moveCharacter(roll);
        
            displayBoard();
            
            
            switch ( checkActivity() ) {
                    
                case 1:
                    activatedSpace();
                    break;
                    
                case 2:
                    emptySpace();
                    break;
                    
                case 3:
                    itemSpace();
                    break;
                    
                case 4:
                    lifeSpace();
                    break;
                
                case 5:
                    moveSpace();
                    break;
                    
                case 6:
                    weaponSpace();
                    break;
                    
                default:
                    cout << "ERROR - switch landed on default." << endl;
                    break;
            }
            
            
            
            
        
        }while( ! (getRowLocation() == 4 && getColLocation() == 4) );
            
            
            
            // debug
            cout << endl << endl
                 << "row " << getRowLocation() << endl
                 << "col " << getColLocation();
        
        
        
        // ---------------------------------------------------- Game Over (ask to play again)
        
        cout << endl << endl << endl << endl
             << "GAME OVER!"
             << endl << endl << endl << endl
             << "Do you want to play again?" << endl
             << "Enter 0 to quit or 1 to play again." << endl;
        cin >> quit;
        
        if (quit != 0 && quit != 1) {
            
            cout << "Since you don't know how to follow foo, then you can't play anymore!" << endl;
            quit = 0;
        }
        
        
        
    }while(quit == 1);
    
    cout << endl << endl << "Thanks for playing" << endl << endl;
    
}

//***********************************************************************************************************************


int GangLand::diceRoll(){
    
    int roll = rand() % 6 + 1, signal;
    
    do{
        cout << endl
             << "Enter any number to roll the dice: ";
        cin >> signal;
        
    }while( isdigit(signal) );
    
    cout << endl << "....... and the dice rolls a ....... : " << roll << endl;
    
    
    return roll;
    
}

//***********************************************************************************************************************

void GangLand::moveCharacter(int diceRoll){
    
    int temp = 0;
    
    if (diceRoll + getRowLocation() <= 4) {
        
        setRowLocation(diceRoll + getRowLocation() );
    }
    else if (diceRoll + getRowLocation() > 4 && getColLocation() + 1 <= 4){
        
        temp = diceRoll - 5;
        setRowLocation(getRowLocation() + temp);
        setColLocation(getColLocation() + 1);
    }
    else{
        
        setRowLocation(4);
        setColLocation(4);
    }

}

//***********************************************************************************************************************

int GangLand::checkActivity(){
    
    
    if (spaceGrid[getRowLocation() ][getColLocation() ].getIsActivated() ) {
        
        return 1;
    }
    
    else if (spaceGrid[getRowLocation() ][getColLocation() ].getIsSpace() ) {
        
        return 2;
    }
    
    else if (spaceGrid[getRowLocation() ][getColLocation() ].getIsItem() ) {
        
        return 3;
    }
    
    else if (spaceGrid[getRowLocation() ][getColLocation() ].getIsLifespace() ) {
        
        return 4;
    }

    else if (spaceGrid[getRowLocation() ][getColLocation() ].getIsMoveSpace() ){
        
        return 5;
    }
    
    else if (spaceGrid[getRowLocation() ][getColLocation() ].getHasWeapon() ){
        
        return 6;
    }
    
    else {
        
        cout << "ERROR - Checked for activity and none was found." << endl
             << "Row: " << getRowLocation() << endl
             << "Col: " << getColLocation() << endl;
        
        return 0;
    }
    
}

//***********************************************************************************************************************

// --------------------------------------- ACTIVITIES

//***********************************************************************************************************************



void GangLand::activatedSpace(){
    
    
    int guess1, guess2, answer = rand() % 5 + 1, exit = 0;
    string hood;
    
    
    bloodDisplay();
    
    cout << "Oh sh*t homie! You went the wrong direction (said lil' joker)" << endl << endl
         << "Hey whats up homie, this is BLOOD territory, where you from?! (gangsters)" << endl
         << "Be careful what you reply to them or else you'll get jumped (lil' joker)" << endl << endl
         << "Enter a response" << endl;
    cin >> hood;
    
    cout << endl
         << "Wow did you really just say that?! (lil' joker)" << endl
         << "F*ck " << hood << " this BOMPTON homie! " << endl << endl
         << "No one knows what BOMPTON is.... but either way ur done (lil' joker)" << endl
         << "Hands up, you are about to get..........." << endl << endl;
    
    jumpedDisplay();
    
    cout << "In order to fight off the gangsters" << endl
         << "You will be asked to guess a number from 1 - 5 " << endl << endl
         << "If you guess the wrong answer within 2 attempts your going end up in the hospital" << endl
         << "If you guess the right number then you are able to knock a gangster out and run away" << endl << endl
         << "Okay foo, take your first guess" << endl
         << "GUESS 1: ";
    cin >> guess1;
    
    
    if (guess1 == answer) {
        
        cout << "MONEY!.....You got it RIGHT!" << endl
             << "You dodged a hit and landed an uppercut and ran away" << endl
             << "Took a couple hits but you good." << endl;
        
        if (getColLocation() == 2 && getRowLocation() == 0) {
            
            setColLocation(4);
            setRowLocation(0);
        }
        else if (getColLocation() == 2 && getRowLocation() == 0) {
            
            setColLocation(4);
            setRowLocation(0);
        }
        else if(getColLocation() == 2 && getRowLocation() == 4){
            
            setColLocation(4);
            setRowLocation(4);
        }
        
        setEnergyLevel( getEnergyLevel() - 25);
        
        exit++;
    }
    else{
        
        cout << "POW! PUNCH! KICK! BOOM!" << endl
             << "Love the sound effects don't you " << endl
             << "Well your guess was incorrect, you get one more attempt or say hello to the hospital" << endl
             << "GUESS 2: ";
        cin >> guess2;
    }
    
    if (guess2 == answer && exit == 0) {
        
        cout << "MONEY!.....You got it RIGHT!" << endl
             << "You dodged a hit and landed an uppercut and ran away" << endl
             << "Took a couple hits but you good." << endl;
        
        if (getColLocation() == 2 && getRowLocation() == 0) {
            
            setColLocation(4);
            setRowLocation(0);
        }
        else if (getColLocation() == 2 && getRowLocation() == 0) {
            
            setColLocation(4);
            setRowLocation(0);
        }
        else if(getColLocation() == 2 && getRowLocation() == 4){
            
            setColLocation(4);
            setRowLocation(4);
        }
        
        setEnergyLevel( getEnergyLevel() - 25);
        
        exit++;
    }
    
    if (exit == 0) {
        
        if (getColLocation() == 0 && getRowLocation() == 2) {
            
            cout << "Since you got jumped at this location" << endl
                 << "They knocked you out and dropped you off at the starting point" << endl << endl
                 << "Life Percentage: " << getEnergyLevel() << endl << endl;
            
            setColLocation(0);
            setRowLocation(0);
        }
        
        setEnergyLevel( getEnergyLevel() - 50);
    }/*
    else{
    
        cout << endl
             << "Man I told you to be careful what you responded (lil' joker)" << endl
             << "You got knocked the F*** out haha." << endl
             << "You alright though bruh, get up" << endl
             << "Wish I cud've helped, I was just too busy recording it to put in on Youtube" << endl << endl
             << "Life Percentage: " << getEnergyLevel() << endl << endl;
    }*/
    
    cout << endl
         << "The number is: " << answer << endl << endl;
    
    displayBoard();
}
//***********************************************************************************************************************

void GangLand::emptySpace(){
    
    safeDisplay();
    
    cout << "Koo, keep staying low" << endl
         << "you are safe for now...." << endl
         << "Life Percentage: " << getEnergyLevel() << endl << endl;

    
    displayBoard();
}

//***********************************************************************************************************************

void GangLand::itemSpace(){
    
    cripsDisplay();
    
    int guess;
    
    cout << "Oh snap! The CRIPS have an offer for you, cause gang offers are always a win win HA!" << endl
         << "So the CEO of the CRIPS Organizational Gang found out that you are a computer science student" << endl
         << "Therefore he wants you to make a delivery for him" << endl
         << "First you must answer a CS question to prove yourself" << endl << endl
         << "Okay boy, so in order to make this delivery for me, (Big Joker)" << endl
         << "You must first answer me this" << endl
         << "What is the largest number that an int can hold in C++" << endl << endl
         << "Hint: its 5 digits long," << endl
         << "      2 numbers are identical (3rd and 5th number)" << endl
         << "      they add up to 25" << endl
         << "      the fourth number is one less the number that is duplicated" << endl << endl
         << "And yes I know this information, I used to code before the gang life" << endl
         << "One guess, your guess is: ";
    cin >> guess;
    
    cout << endl << endl;
    
    if (guess == 32767) {
        
        cout << "Dang I guess you payed attention in class homie" << endl
             << "I can't believe you actually got it right, unless you cheated" << endl
             << "If so, oh well ain't like we follow rules either" << endl
             << "Thanks for the delivery too man, weel give you a ride closer to the end of town" << endl;
        
        setColLocation(4);
        setRowLocation(2);
        
    }
    else{
        
        cout << "Wow and you call yourself a CS major" << endl
             << "Even gangsters are dissappointed in you, that says a lot" << endl
             << "But since dissappointment is not enough" << endl
             << "Hey baby joker shoot this kid!" << endl << endl;
        
        setEnergyLevel(getEnergyLevel() - 25);
    }
    
    
    cout << "Life Percentage: " << getEnergyLevel() << endl << endl;

    displayBoard();
    
}

//***********************************************************************************************************************

void GangLand::lifeSpace(){
    
    lifeDisplay();
    
    setEnergyLevel(100);
    
    cout << "Yes we found a 40oz Old English under the bridge!" << endl
         << "Drink up then homie, and enjoy your health back to one hunnid" << endl << endl
         << "Life Percentage: " << getEnergyLevel() << endl << endl;

    displayBoard();
}

//***********************************************************************************************************************

void GangLand::moveSpace(){
    
    char answer;
    
    hustlersBlockDisplay();
    
    
    cout << "Koo you walked into HUSTLER'S block (lil' Joker)" << endl << endl
         << "Whats up young blood, you up for high card wins? (Tiny Joker - not related to lil' Joker)" << endl
         << "C'mon don't be scared, live a little" << endl
         << "If you win well drop you off a street closer to the end of the town in your favor" << endl
         << "HA but if you lose then we do the opposite" << endl
         << "And I can't promise your safety on that ride :) " << endl << endl
         << "So what is it going to be barney? " << endl
         << "Enter Y for yes and N for no" << endl;
    cin >> answer;
    
    cout << endl;
    
    answer = toupper(answer);
    
    if (answer != 'Y' && answer != 'N') {
        
        cout << "Well since you do not know how to answer rules by entering " << answer << endl
             << "We have answered for you, enjoy the ride a street in the opposite direction \"Buddy\" " << endl;
        answer = 'N';
    }
    
    if (answer == 'Y') {
        
        int dealer = rand() % 9 + 2, user = rand() % 9 + 2;
        
        cout << "Okay lets get this going.. High card it is" << endl
             << "Rules are simple person with the highest card wins, one try" << endl
             << "that is basically it if you don't get it oh well, better for me" << endl << endl;
        

        cout << "I go first... and my card is a.......: " << dealer << " of hearts" << endl
             << "Your turn " << getName() << endl
             << "and yours is a ......................: " << user << " of diamonds" << endl;
        
        if (user > dealer) {
            
            cout << "You lucky son of a...." << endl
                 << "Well I am a man of my word, so shut up on hop on the Escalade." << endl;
            
            setRowLocation(getRowLocation() + 1);
        }
        else{
            
            cout << "Aw you want to cry?" << endl
                 << "You can keep your  " << user << " of diamonds and put it where the sun don't shine" << endl
                 << "Now jump in the car and try and get cozy cuz my hungry dogs going to ride with you" << endl
                 << "And yes they will bite, in case you are curious." << endl << endl;
            
            
            setEnergyLevel(getEnergyLevel() - 25);
            
        } // end if (loses gambling)
        
        
        
    } // end if (user denies gambling)
    else{
        
        cout << "Well here's the thing little man" << endl
             << "You put me in a particular situation, saying no to me in front of my homies." << endl << endl
             << "So we are going to give you a ride, you want to go south, but we're taking you north." << endl
             << "and you can sit in the back of the truck with my tiny cuddly pitbull and doberman" << endl
             << "Who also by the way have not eating in about a week, hey times are rough right, have fun!"
             << endl << endl;
        
        setEnergyLevel(getEnergyLevel() - 25);
    }
    
    cout << "Life Percentage: " << getEnergyLevel() << endl << endl;
    
    displayBoard();
    
}

//***********************************************************************************************************************

/*
 
 if achieved [1][1] -> [1][2]
 
 */


void GangLand::weaponSpace(){
    
    srand(time(0));
    
    string response, coinface;
    int coin = rand() % 2;
    
    cout << "Weapon space" << endl;
    
    cout << endl
         << "You have been stopped by a cop" << endl
         << "You look familiar..So where you headed thief? (cop)" << endl
         << getName() << ": ";
    cin >> response;
    
    cout << "Well it looks like you're on probation" << endl
         << "Respon ->:";
    cin >> response;
    
    cout << "Well around here, we obey the law" << endl
         << "And IM the law" << endl << endl
         << "So unless you have a good amount of cash on you" << endl
         << "How much money do you have?" << endl
         << "Respond ->:";
    cin >> response;
    
    cout << "Uuuuuu... you're just a couple thousand short " << endl
         << "But hey, I'm in a good mood today, and I was about to clock out already." << endl
         << "So how about we flip a coin, make this exciting" << endl
         << "Call it in the air, if you win, I only give you a beating" << endl
         << "But if you lose, then I take you to jail... deal?.... deal!" << endl
         << "Enter heads or tails" << endl
         << "Respond ->:";
    cin >> response;
    
    response[0] = tolower(response[0] );
    
    
    if (coin == 0) {
        
        coinface = "tails";
    }
    else{
        
        coinface = "heads";
    }
    
    
    if (response[0] != 't' && response[0] != 'h') {
        
        cout << "Well since you didn't call anything, I call heads" << endl;
        
        response[0] = 't';
    }
    
    if (response[0] == coinface[0]) {
        
        cout << "Lucky guy, you won the toss" << endl
             << "Now hold on cuz I want to try out this taser I just bought." << endl;
        
        setEnergyLevel(getEnergyLevel() - 25);
        
        if (getColLocation() == 1 && getRowLocation() == 1) {
            
            cout << endl << endl
                 << "Lucky space, you move down a row!!" << endl << endl;
            
            setColLocation(1);
            setRowLocation(2);
        }
        
    }
    else{
        
        cout << "Ha! Sucks for you, I win!" << endl
             << "Now one advice, do not drop the soap" << endl << endl;
    }
    
    
    
    
}

//***********************************************************************************************************************






















