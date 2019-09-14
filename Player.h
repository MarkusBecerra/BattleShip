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
std::string setRecentGuess();
std::string getRecentGuess();

void Shooting(std::string guess); 
void gettingShot(std::string guess);





};
#endif
