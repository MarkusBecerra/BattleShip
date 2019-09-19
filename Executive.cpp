
#include "Executive.h"
#include <limits>

//ADD FUNCTION TO HEADER
int Executive::boatCheck() // will return numOfBoats
{
	int numOfBoats = 0;
	std::string tempBoats = " ";

	std::cout << "How many ships would you like to play with? (Choose 1-5): ";
	std::getline(std::cin, tempBoats);

	if(tempBoats.length() > 1 || tempBoats.length() < 1)
	{
		std::cout << "Must be a one-digit number from 1-5!\n";
		boatCheck();
	}

	if(tempBoats.at(0) < 1 || tempBoats.at(0) > 5)
	{
		boatCheck();
	}

	if(std::cin.fail())			//check for integer input
	{
			std::cout << "Invalid input, expecting integer!" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

			std::cout << "How many ships would you like to play with? (Choose 1-5): ";
			std::getline(std::cin, tempBoats);
			boatCheck();
	}

	if(tempBoats.length() == 1)
	{
		numOfBoats = tempBoats.at(0) - '0';
	}

	return numOfBoats;
}

Executive::Executive()
{
	int numOfBoats = 0;
	std::string tempBoats = " ";			//using string to use getline string.at(1)

	try
	{
		numOfBoats = boatCheck();
	}

	catch(std::runtime_error &rte)
	{
		std::cout << rte.what();
	}

	std::cout << "NUMBER OF BOATS: " << numOfBoats << "\n";
	std::cout << "LENGTH OF TEMPBOATS: " << tempBoats.length() << "\n";

	player_1 = new Player(numOfBoats);
	player_2 = new Player(numOfBoats);
	gameOver = false;
	m_player_1Turn = 1;
	game();			//GAME NOW CALLED HERE RATHER THAN IN MAIN
		/////end those lines
}

void Executive::mainMenu()
{

}

void Executive::game()
{
	std::string guess;
	int testTemp = 5;
	while(!gameOver && testTemp > 0)
	{
		try
		{
			if(m_player_1Turn % 2 == 1)
			{
				std::cout <<"Player 1: Where would you like to shoot? ";
			}
			else
			{
				std::cout <<"Player 2: Where would you like to shoot? ";
			}

//////below is the try catch block to make sure the guess is a string of length 2
			try
			{
				std::cin >> guess;

				while(guess.length() != 2)			//checking that string length is 2
				{
					std::cout << "Please enter a coordinate, such as A1,B5,H2: ";
					std::cin >> guess;
				}

				shoot(guess);

			}
			catch (std::string message)
			{
				//what do we add here??
			}
///////end try catch block for checking length of guess string

			if(m_player_1Turn % 2 == 1)
			{
				std::cout << "PLAYER 1 BOARDS\n";
				player_1->getBoard()->printShotBoard();
				player_1->getBoard()->printMyBoard();
			}
			else
			{
				std::cout << "PLAYER 2 BOARDS\n";
				player_2->getBoard()->printShotBoard();
				player_2->getBoard()->printMyBoard();
			}
			m_player_1Turn++;
			testTemp--;
		}
		catch(std::runtime_error &rte)
		{
			std::cout << rte.what();
		}
	}
}



void Executive::shoot(std::string location)
{
	bool hit = false;
	if(m_player_1Turn % 2 == 1)
	{
		hit = player_2->gettingShot(location);
		player_1->shooting(location,hit);

	}
	else
	{
		hit = player_1->gettingShot(location);
		player_2->shooting(location,hit);
	}

}
