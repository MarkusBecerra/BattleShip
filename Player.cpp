//Player cpp file to contain all player functions

#include "Player.h"

Player::Player()
{
	m_board = new Board();
}

Player::~Player()
{
  delete m_board;
}

void Player::Shooting(std::string guess)
{
	
}
void Player::gettingShot(std::string guess)
{
	//use board functions to update myBoard and return whether hit or miss
}
