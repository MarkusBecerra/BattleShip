
#include "Executive.h"

Executive::Executive()
{
	std::cout <<"Hi from Executive class\n";
}

void Executive::mainMenu()
{
	int numOfBoats = 1;
	std::cout <<"How many ships would you like to play with? (Choose 1-5): ";
	std::cin >> numOfBoats;
}
