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

Executive::Executive()
{
	int numOfBoats = 0;
	std::cout <<"How many ships would you like to play with? (Choose 1-5): ";
	std::cin >> numOfBoats;
	player_1 = new Player(numOfBoats);
	player_2 = new Player(numOfBoats);
	gameOver = false;
	m_player_1Turn = 1;
	std::cout <<"\n\n\nPlayer 1 place your ships\n";
	player_1 -> getBoard() -> setupBoard();
	player_2 -> getBoard() -> setupBoard();

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
				player_1->getBoard()->printShotBoard();
				player_1->getBoard()->printMyBoard();
				std::cout <<"Player 1: Where would you like to shoot? ";
			}
			else
			{
				player_2->getBoard()->printShotBoard();
				player_2->getBoard()->printMyBoard();
				std::cout <<"Player 2: Where would you like to shoot? ";
			}
			std::cin >> guess;
			shoot(guess);
			if(m_player_1Turn % 2 == 1)
			{

				std::cout << "PLAYER 1 BOARDS\n";
				player_1->getBoard()->printShotBoard();
				player_1->getBoard()->printMyBoard();
				std::cin.ignore();
				std::cout <<"Player 1 please hit enter and let other player shoot at your ships in secret\n";
				std::cin.ignore();
				player_1->getBoard()->printIntermission();
			}
			else
			{
				std::cout << "PLAYER 2 BOARDS\n";
				player_2->getBoard()->printShotBoard();
				player_2->getBoard()->printMyBoard();
				std::cin.ignore();
				std::cout <<"Player 2 please hit enter and let other player shoot at your ships in secret\n";
				std::cin.ignore();
				player_2->getBoard()->printIntermission();
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
