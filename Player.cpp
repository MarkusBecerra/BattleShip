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

void Player::shooting(std::string guess, bool hit)
{
	
}
bool Player::gettingShot(std::string guess)
{
	return (m_board->updateMyBoard(guess));	

}
