
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
	Board Player1;
	Board Player2;

	Player1.printOpponentBoard();
	Player1.printYouBoard();
}
