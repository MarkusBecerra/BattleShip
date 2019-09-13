
#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <string>
#include <iostream>
#include <fstream>
#include "Player.h"

class Executive
{
	public:
		Executive();
		void mainMenu();
		void shoot(std::string location, int whichPlayer);

	private:

		Player* player_1;
		Player* player_2;
		int m_playerTurn; //keeps track of which player's turn it is
};
#endif
