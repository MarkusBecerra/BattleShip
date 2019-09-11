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
