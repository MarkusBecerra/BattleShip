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

void setRecentGuess(std::string guess); //member variable helper function
std::string getRecentGuess() const; //member variable helper function

void shooting(std::string guess, bool hit);
bool gettingShot(std::string guess);

};
#endif
