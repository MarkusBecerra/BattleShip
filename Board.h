/**
* \Author: Chance Penner
* \Author: Markus Becerra
* \Author: Sarah Scott
* \Author: Thomas Gardner
* \Author: Haonan Hu
* \File:	 Board.h
* \Date:   09/19/2019
* \Brief:  File is header file
* \copyright: Group "Big SegFault Energy" All rights reserved
*/

#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <iostream>
#include <stdexcept>
#include "Ship.h"

/**
 * The Board class represents a general game board
 * the scale of the board is 8*8
 * all the game-related methods are included in this class
 */
class Board
{
private:
	std::string shotBoard[8][8];
	std::string myBoard[8][8];
	std::string m_rowNames = "ABCDEFGH";
	std::string m_columnNames = "12345678";
	int m_rowIndex;
	int m_columnIndex;
	/**
	* @pre none
	*	@param takes a location string from user
	*	@post converts userGuess to two array indices, updating rowIndex and columnIndex
	*/
	void guessConversion(std::string userGuess);

	std::string blueTilde;
	std::string redHit;
	std::string whiteMiss;
	std::string ship;
	int numberOfShips;
	Ship* m_ship = nullptr;

public:
	/**
	* @pre none
	*	@post board constructor
	*/
	Board();

	/**
	* @pre none
	*	@post Board destructor
	*/
	~Board();

	/**
	* @pre none
	*	@param numbers of ships will be passed in the method for board setting up
	*	@post set up board and fill board with blue tilde
	*/
	Board(int shipnum);

	/**
	* @pre none
	*	@param none
	*	@post print the shot board for player
	*/
	void printShotBoard();

	/**
	* @pre none
	*	@param none
	*	@post print the player board
	*/
	void printMyBoard();

	/**
	* @pre none
	*	@param none
	*	@post prints a blank screen to hide previous player's board
	* and asks the current player to press enter before next step
	*/
	void printIntermission();

	/**
	*	private member variable helper function
	* @pre none
	*	@param takes a int for number of ships
	*	@post change private member variable numberOfShips to shipnum
	*/
	void setNumberofShips(int shipnum);

	/**
	*	private member variable helper function
	* @pre none
	*	@param none
	*	@post get private member variable numberOfShips
	* @return number of Ships
	*/
	int getNumberofShips() const;

	/**
	* @pre none
	*	@param none
	*	@post asks the player where they want to place the ships.
	* uses with withinBoundary and edits myBoard and shotBoard
	*/
	void setupBoard();

	/**
	* @pre user guess location must be valid
	*	@param user's guee location and a boolean value checking hit or not
	*	@post if blueTilde, change to whiteMiss, if whiteMiss, prints you already shot here,
	* if redHit, prints you already shot here, if ship, change to redHit
	*/
	void updateShotBoard(std::string userGuess, bool wasHit);

	/**
	* @pre user guess location must be valid
	*	@param user's guess location
	*	@post updated player's board, if blueTilde, change to whiteMiss,
	*  if whiteMiss, prints you already shot here, if redHit, prints you already shot here,
	*  if ship, change to redHit
	* @return true if it hit a ship
	*/
	bool updateMyBoard(std::string userGuess);

	/**
	* @pre user's guess location must be valid
	*	@param user's guess location
	*	@post gets called from Player shoot function. Calls guessConversion. Needs to check for valid input.
	* @return true if user's guess is in boundary
	*/
	bool withinBoundary(std::string userGuess);

	/**
	* @pre user's guess location must be valid, ship length cant exceed 5
	*	@param user's guess location and size of ship
	*	@post check horizontal placed ship will collide with other ship or not
	* @return true if ships will collide
	*/
	bool noHorizontalCollision(std::string userGuess, int shipLength);

	/**
	* @pre user's guess location must be valid, ship length cant exceed 5
	*	@param user's guess location and size of ship
	*	@post check vertical placed ship will collide with other ship or not
	* @return true if ships will collide
	*/
	bool noVerticalCollision(std::string userGuess, int shipLength);

	/**
	*	private member variable helper function
	* @pre none
	*	@param none
	*	@post get ship object
	* @return ship object
	*/
	Ship* getShip() const;
};
#endif
