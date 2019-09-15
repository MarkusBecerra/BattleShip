
#include "Executive.h"

Executive::Executive()
{
	std::cout <<"Hi from Executive class\n";
	player_1 = new Player();
	player_2 = new Player();
}

void Executive::mainMenu()
{
	int numOfBoats = 0;
	std::cout <<"How many ships would you like to play with? (Choose 1-5): ";
	std::cin >> numOfBoats;
}

void Executive::game()
{
	while(false){





	}
}

void Executive::shoot(std::string location)
{
	bool hit = false;
	if(m_playerTurn == 1)
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
