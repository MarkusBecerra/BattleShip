/**
* \Author: Chance Penner
* \Author: Markus Becerra
* \Author: Sarah Scott
* \Author: Thomas Gardner
* \Author: Haonan Hu
* \File:	 Executive.cpp
* \Date:   09/19/2019
* \Brief:  File is cpp file
* \copyright: Group "Big SegFault Energy" All rights reserved
*/


#include "Executive.h"
#include <limits>
#include "algorithm" //for toupper

int Executive::boatCheck() //will return numOfBoats when valid
{
	int numOfBoats = 0;						//declaring numberOfBoats
	std::string tempBoats = " ";	//declaring tempBoats string for storing numOfBoats as a string

	std::cout << "How many ships would you like to play with? (Choose 1-5): ";		//prompt user for number of ships

	try
	{
		std::getline(std::cin, tempBoats);		//try block to gather the users desired number of boats in a getline
	}

	catch(std::out_of_range &ex)		//catch out of range if the user just presses enter, or the getline fails another way
	{
		std::cout << "No input was recieved, please enter a number 1-5: \n";		//print error message
		return boatCheck();		//return the boatCheck function to get a new input for the number of boats desired
	}

	if(tempBoats.length() < 1 || tempBoats.length() > 1)		//check if the length of the string is NOT equal to one
	{
		std::cout << "Must be a one-digit number from 1-5!\n";	//print error that the digit was greater than length 1
		return boatCheck();		//return the boatCheck function to get a new input for the number of boats desired
	}

	else		//if the tempBoats length was equal to 1
	{
		numOfBoats = tempBoats.at(0) - '0';		//set numOfBoats integer equal to the first character of the tempBoats string

		if(numOfBoats < 1 || numOfBoats > 5)		//if numOfBoats is not between one and five (inclusive)
		{
			std::cout << "Must be an integer from 1-5!\n";		//print error message that the number is out of the range
			return boatCheck();		//return boatCheck function to get a new input for the number of boats desired
		}

		else
		{
			return numOfBoats;		//if the number of boats is valid (1-5), return the integer itself
		}
	}

}

Executive::Executive()		//Executive constructor
{
	int numOfBoats = 0;		//int numOfBoats to store the number of boats

	try		//DO WE NEED TRY CATCH HERE???!
	{
		numOfBoats = boatCheck();		//try block to set Executive constructor's numOfBoats to the value returned by boatCheck
	}

	catch(std::runtime_error &rte)	//catch error if the function fails
	{
		std::cout << "Invalid number of ships";		//print error message if the function fails
	}

	player_1 = new Player(numOfBoats); 		//create player 1 object passing in the number of boats
	player_2 = new Player(numOfBoats);		//create player 2 object passing in the number of boats
	m_gameOver = false;			//m_gameOver member variable set to false at the beginning of the game
	m_player_1Turn = 1;			//m_player_1Turn member boolean set to 1, game starts with player 1's turn

	std::cout <<"\nPlayer 1 place your ships\n";		//prompt player1 to place their ships
	player_1 -> getBoard() -> setupBoard();					//call getBoard and setupBoard from board.cpp to create the two boards for player1
	std::cout <<"\nPlayer 2 place your ships\n";		//promt player2 to place their ships
	player_2 -> getBoard() -> setupBoard();					//call getBoard and setupBoard from board.cpp to create the two boards for player2
	game();		//call Executive game function to start the game once both players have set up their boards

}

Executive::~Executive()		//Executive destructor
{
	delete player_1;		//delete player1 object
	delete player_2;		//delete player2 object
}

void Executive::mainMenu()		//KEEP OR NOT????
{

}

void Executive::game()
{
	std::string guess = " ";

	while(!m_gameOver)
	{
		try
		{
			guess = " ";			//reinitializes guess to prevent infinite out of boundary loop

			while(guess.length() != 2)
			{
				if(m_player_1Turn % 2 == 1)	//if it is player 1's turn
				{
					player_1->getBoard()->printShotBoard();
					player_1->getBoard()->printMyBoard();
					std::cout << "Player 1: Where would you like to shoot: "; //print player's board and opponent's board and ask for user a location to shoot

					std::getline(std::cin, guess);

					std::transform(guess.begin(), guess.end(),guess.begin(), ::toupper);	//converts guess to uppercase

					std::cout << "guess: " << guess << "\n"; //print out user's guess

					if(guess.length() != 2)
					{
						std::cout << "Invalid coordinate! Try again.\n";
					}

				}
				else	//if it is player 2's turn
				{
					player_2->getBoard()->printShotBoard();
					player_2->getBoard()->printMyBoard();
					std::cout <<"Player 2: Where would you like to shoot: ";

					std::getline(std::cin, guess);

					std::transform(guess.begin(), guess.end(),guess.begin(), ::toupper);	//converts guess to uppercase


					if(guess.length() != 2)
					{
						std::cout << "Invalid coordinate! Try again.\n";
					}

				}
			}

			shoot(guess);

			if(m_player_1Turn % 2 == 1 && !m_gameOver) //if it is player 1's turn
			{

				std::cout << "PLAYER 1 TURN\n";
				player_1->getBoard()->printShotBoard();
				player_1->getBoard()->printMyBoard();

				std::cout <<"Player 1 please hit enter and let other player shoot at your ships in secret: ";
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n'); //get rid of user's ramdon input to crash the game

				player_1->getBoard()->printIntermission();
			}
			else if(m_player_1Turn % 2 == 0 && !m_gameOver)	//if it is player 2's turn
			{
				std::cout << "PLAYER 2 TURN\n";
				player_2->getBoard()->printShotBoard();
				player_2->getBoard()->printMyBoard();

				std::cout <<"Player 2 please hit enter and let other player shoot at your ships in secret: ";
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n'); //get rid of user's ramdon input to crash the game

				player_2->getBoard()->printIntermission();
			}

			m_player_1Turn++; //change player turn
		}
		catch(std::runtime_error &rte)
		{
			std::cout << rte.what();
		}
	}

	if(m_player_1Turn % 2 == 1) //m_player_1Turn gets changed right before this, which is why the value is comparing different than above
	{
		player_2->getBoard()->printShotBoard();
		player_2->getBoard()->printMyBoard();

		std::cout << "PLAYER 2 WINS!\n";
	}
	else
	{
		player_1->getBoard()->printShotBoard();
		player_1->getBoard()->printMyBoard();

		std::cout << "PLAYER 1 WINS!\n";
	}

}

void Executive::shoot(std::string location)
{
	int numberOfShips = player_1->getBoard()->getNumberofShips(); //sets the number of ships

	bool hit = false;

	if(m_player_1Turn % 2 == 1)
	{
		hit = player_2->gettingShot(location);
		player_1->shooting(location,hit);

		for(int i=0;i<numberOfShips;i++)	//checks for game over
		{
			if(player_2->getBoard()->getShip()[i].isSunk())
			{
				m_gameOver = true;	//sets to true if they are sunk
			}
			else
			{
				m_gameOver = false;	//sets back to false if any are not sunk and then breaks out of for loop
				break;
			}
		}


	}
	else
	{
		hit = player_1->gettingShot(location);
		player_2->shooting(location,hit);

		for(int i=0;i<numberOfShips;i++)	//checks for game over
		{
			if(player_1->getBoard()->getShip()[i].isSunk())
			{
				m_gameOver = true;	//sets to true if they are sunk
			}
			else
			{
				m_gameOver = false; //sets back to false if any are not sunk and then breaks out of for loop
				break;
			}
		}
	}
}
