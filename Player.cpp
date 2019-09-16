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

void Player::setRecentGuess(std::string guess)
{
	recentguess = guess;
}

std::string Player::getRecentGuess() const
{
	return recentguess;
}

void Player::shooting(std::string guess, bool hit)
{
	m_board->updateShotBoard(guess,hit);
}
bool Player::gettingShot(std::string guess)
{
	if(m_board->withinBoundary(guess)) //used to test correct input. Can delete this if-else if wanted
	{
		std::cout << "within boundary\n";
	}
	else
	{
		std::cout << "not within boundary\n";


	

	return (m_board->updateMyBoard(guess));
}
