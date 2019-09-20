/**
* \Author: Chance Penner
* \Author: Markus Becerra
* \Author: Sarah Scott
* \Author: Thomas Gardner
* \Author: Haonan Hu
* \File:	Executive.h
* \Date:   09/19/2019
* \Brief:  File is header file
* \copyright: Group "Big SegFault Energy" All rights reserved
*/

#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <string>
#include <iostream>
#include <fstream>
#include "Player.h"

/**
 * The Executive class controls the game
 * all the methods are implemented for making the Battleship game
 */
class Executive
{
public:
	/**
	* @pre none
	*	@post created and set up the game board
	*/
	Executive();

	/**
	* @pre none
	*	@post print the main menu for the game
	*/
	void mainMenu();

	/**
	* @pre location must be valid
	* @param takes a location from user
	*	@post shoot the location
	*/
	void shoot(std::string location);

	/**
	* @pre none
	* @param none
	*	@post start the game offically
	*/
	void game();

	int boatCheck();		//checks that number of boats are valid

private:

	Player* player_1;
	Player* player_2;
	int m_player_1Turn; //true if player1 turn, false if player2 turn
	bool gameOver;	//game over to stop the while loop once the game ends
};
#endif
