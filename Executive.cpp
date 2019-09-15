
#include "Executive.h"

Executive::Executive()
{
	int numOfBoats = 0;
	std::cout <<"How many ships would you like to play with? (Choose 1-5): ";
	std::cin >> numOfBoats;
	player_1 = new Player(numOfBoats);
	player_2 = new Player(numOfBoats);
	gameOver = false;
	m_player_1Turn = true;
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
		if(m_player_1Turn)
			std::cout <<"Player 1: Where would you like to shoot? ";
		else
			std::cout <<"Player 2: Where would you like to shoot? ";
		std::cin >> guess;
		shoot(guess);
		m_player_1Turn = !m_player_1Turn;
		testTemp--;

	}
}



void Executive::shoot(std::string location)
{
	bool hit = false;
	if(m_player_1Turn)
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
