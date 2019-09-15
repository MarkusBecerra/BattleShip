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
int numOfShips;

public:
Player(int shipsNum);   //player constructor
~Player();
std::string setRecentGuess();
std::string getRecentGuess();

void shooting(std::string guess, bool hit); 
bool gettingShot(std::string guess);





};
#endif
