
#include "Board.h"

Board::Board()
{

	blueTilde = "\033[1;36m~\033[0m";
	redHit = "\033[1;31mX\033[0m";
	whiteMiss = "\033[1;37mO\033[0m";
	//ship = "\033[1;37m\033[0m";

	for (int i=0; i<8; i++)
	{
		for(int j=0; j<8; j++)
		{
			myBoard[i][j] = blueTilde;
			shotBoard[i][j] = blueTilde;
		}
	}

}

void Board::printShotBoard()
{
	std::cout << "\n\t\t\tYour opponent's board\n";

	for(int i=0;i<8;i++)
  {
    std::cout << m_rowNames[i] << "\t";
  }
std::cout << "\n";

  for(int i=0;i<8;i++)
  {
		std::cout << i+1;
		for(int j=0;j<8;j++)
		{
			std::cout << "\t" << shotBoard[i][j];
		}
		if(i != 7)
		{
			std::cout << "\n\n\n"; //prints spaces between rows. Not needed at end to conserve space
		}
		else
		{
			std::cout << "\n\n"; //prints only one newline instead of three to conserve space
		}
  }
}

void Board::printMyBoard()
{
	std::cout << "\t\t\tYour board\n";
	std::cout << "\t";

	for(int i=0;i<8;i++)
	{
		std::cout << m_rowNames[i] << "\t";
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



bool Board::updateMyBoard(std::string userGuess)
{
	guessConversion(userGuess);
	std::string location = myBoard[rowIndex][columnIndex];
	if(location == blueTilde)
		myBoard[rowIndex][columnIndex] = whiteMiss;
	//else if(location == ship)
	//{
	//	myBoard[rowIndex][columnIndex] = redHit;
	//	return true;
	//}
	return false;
}

void Board::updateShotBoard(std::string userGuess, bool wasHit)
{
}

void Board::guessConversion(std::string userGuess)
{
	rowIndex = 0;
	columnIndex = 0;
}




