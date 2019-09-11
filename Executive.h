
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

	private:

		Player* player_1;
		Player* player_2;
};
#endif
