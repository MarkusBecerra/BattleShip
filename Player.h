//Player header file to define the functions for each Player

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "Board.h"

class Player
{
private:
Board* m_board = nullptr;
std::string recentguess;


public:
Player();   //player constructor
~Player();
std::string setrecentGuess();
std::string getrecentGuess();




};
#endif
