
#include "Board.h"

Board::Board()
{
	for (int i=0; i<8; i++)
	{
		for(int j=0; j<8; j++)
		{
			myBoard[i][j] = "Heyy";
			shotBoard[i][j] = "Hi";
		}
	}
	std::cout << "Hi from Board class\n";
}
