
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
		void shoot(std::string location);
		void game();

	private:

		Player* player_1;
		Player* player_2;
		int m_player_1Turn; //true if player1 turn, false if player2 turn
		bool gameOver;	//game over to stop the while loop once the game ends
};
#endif
