
#include "Executive.h"

Executive::Executive()
{
	std::cout <<"Hi from Executive class\n";
	player_1 = new Player();
	player_2 = new Player();
}

void Executive::mainMenu()
{
	int numOfBoats = 1;
	std::cout <<"How many ships would you like to play with? (Choose 1-5): ";
	std::cin >> numOfBoats;


}

void Executive::shoot(std::string location)
{
	if(m_playerTurn == 1)
	{
		player_2->gettingShot(location);
	}
}
