
#include "Board.h"

Board::Board()
{
	std::string rowNames = "ABCDEFGH";

	std::string blueTilde = "\033[1;36m~\033[0m";
	std::string redHit = "\033[1;31mX\033[0m";
	std::string whiteMiss = "\033[1;37mO\033[0m";

	for (int i=0; i<8; i++)
	{
		for(int j=0; j<8; j++)
		{
			myBoard[i][j] = blueTilde;
			shotBoard[i][j] = blueTilde;
		}
	}

	std::cout << "\n\nYour opponent's board: \n\n";

	std::cout << "\t";

	for(int i=0;i<8;i++)
  {
    std::cout << rowNames[i] << "\t";
  }
std::cout << "\n";

  for(int i=0;i<8;i++)
  {
		std::cout << i+1;
		for(int j=0;j<8;j++)
		{
			std::cout << "\t" << shotBoard[i][j];
		}
		std::cout << "\n\n\n";
  }

	std::cout << "Your board: \n\n";
	std::cout << "\t";

	for(int i=0;i<8;i++)
	{
		std::cout << rowNames[i] << "\t";
	}
	std::cout << "\n";

	for(int i=0;i<8;i++)
  {
		std::cout << i+1;
		for(int j=0;j<8;j++)
		{
			std::cout << "\t" << myBoard[i][j];
		}
		std::cout << "\n\n\n";
  }

}
