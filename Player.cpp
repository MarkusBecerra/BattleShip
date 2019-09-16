//Player cpp file to contain all player functions

#include "Player.h"

Player::Player(int shipNums)
{
	m_board = new Board();
	numOfShips = shipNums;
}

Player::~Player()
{
  delete m_board;
}

void Player::setRecentGuess(std::string userGuess)
{
	recentguess = userGuess;
}

std::string Player::getRecentGuess() const
{
	return recentguess;
}

void Player::shooting(std::string userGuess, bool hit)
{
	m_board->updateShotBoard(userGuess, hit);
}
bool Player::gettingShot(std::string userGuess)
{
	if(m_board->withinBoundary(userGuess)) //used to test correct input. Can delete this if-else if wanted
	{
		std::cout << "within boundary\n";
	}
	else
	{
		throw(std::runtime_error("Out of Boundary\n"));
	}

	return (m_board->updateMyBoard(userGuess));
}

Board* Player::getBoard() const
{
	return m_board;
}
