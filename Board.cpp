
#include "Board.h"
#include <sstream>

Board::Board()
{

	blueTilde = "\033[1;36m~\033[0m"; //CITATION NEEDED
	redHit = "\033[1;31mX\033[0m";	//CITATION NEEDED
	whiteMiss = "\033[1;37mO\033[0m";	//CITATION NEEDED
	ship = "\033[1;32m∆\033[0m";

	for (int i=0; i<8; i++)
	{
		for(int j=0; j<8; j++)
		{
			myBoard[i][j] = blueTilde;
			shotBoard[i][j] = blueTilde;
		}
	}

}

Board::Board(int shipnum)
{
	numberOfShips = shipnum;
	blueTilde = "\033[1;36m~\033[0m"; //CITATION NEEDED
	redHit = "\033[1;31mX\033[0m";	//CITATION NEEDED
	whiteMiss = "\033[1;37mO\033[0m";	//CITATION NEEDED
	ship = "\033[1;32m∆\033[0m";

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
	std::cout << '\t';
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
	std::string location = myBoard[m_rowIndex][m_columnIndex];
	if(location == blueTilde)
	{
		myBoard[m_rowIndex][m_columnIndex] = whiteMiss;
	}
	else if(location == ship)
	{
		myBoard[m_rowIndex][m_columnIndex] = redHit;
		return true;
	}
	else if(location == redHit || location == whiteMiss)
	{
		std::cout << "\nYou already shot at this location!\n";
	}
	return false;
}

void Board::updateShotBoard(std::string userGuess, bool wasHit)
{
	guessConversion(userGuess);
	if(wasHit)
	{
		shotBoard[m_rowIndex][m_columnIndex] = redHit;
	}
	else
	{
		shotBoard[m_rowIndex][m_columnIndex] = whiteMiss;
	}
}

//assumes userGuess is within boundary since that is checked first
void Board::guessConversion(std::string userGuess) //converts userGuess to two indices and updates member variables m_rowIndex and m_columnIndex with those indices
{
	std::cout << "guess: " << userGuess << "\n";
	for(unsigned int i=0;i<m_rowNames.length();i++)	//had to make i an unsigned int since m_rowNames.length() returns an unsigned in as well
	{
		if(userGuess.at(0) == m_rowNames.at(i))
		{
			m_columnIndex = i;
			break;
		}
		else
		{
			m_columnIndex = 9; //sets m_rowIndex to a number outside of the range so that it's not just the value it held previously.
											//if the letter the user typed is withing "ABCDEFGH", then the correct index is set and we break out
											//of this for loop and m_rowIndex does not become 9
		}
	}
	int temp = userGuess.at(1) - '0'; //sets temp to the index the user typed. We subtract 'a' to convert it from the ASCII value to the proper decimal value. citation needed

	m_rowIndex = temp - 1; //sets it to the column the user wants, but subtracts 1 to get the proper index
	std::cout << "column: " << m_columnIndex << " row: " << m_rowIndex << "\n";
}

bool Board::withinBoundary(std::string userGuess) //a check for valid input still needs to be made, either here or where the user inputs the guess
{
	guessConversion(userGuess);
	if((0 <= m_rowIndex && m_rowIndex <= 7) && (0 <= m_columnIndex && m_columnIndex <= 7))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Board::noHorizontalCollision(std::string userGuess, int shipLength)
{
	guessConversion(userGuess);
	for(int i = 0; i < shipLength; i++) //Add try catch block friends!
 {
	if((0 <= m_rowIndex && m_rowIndex <= 7) && (0 <= m_columnIndex + i && m_columnIndex + i <= 7))
		{
		if(myBoard[m_rowIndex][m_columnIndex + i] != blueTilde)
			{
			return false;
			}
		}
	else
	{
		return false;
	}
	return true;
 }
}

void Board::setupBoard()
{
	std::string userGuess;
	std::string userDirection;
	m_ship =  new Ship[numberOfShips];
	for(int i = 0; i < numberOfShips; i++)
	{
		m_ship[i].createShip(i+1);
		if(m_ship[i].getLength() == 1)
		{
			printMyBoard();
			std::cout<<"Where would you like to place this ship of size 1? Enter your coordinate: ";
			std::cin>>userGuess;
			if(withinBoundary(userGuess))
			{
				myBoard[m_rowIndex][m_columnIndex] = ship;
				m_ship[i].setCoordinate(userGuess, 0);
				printMyBoard();
			}
			else
			{
				std::cout<<"WRONG HEY TEAM MAKE SURE TO ADD A LOOP HERE UNTIL THE PLAYER ADDS VALID INPUT FOR THE FREAKING SHIP!";
			}
		}
		else
		{

			std::cout<<"HORIZTONAL(H) OR VERTICAL(V)? ";
			std::cin>>userDirection;
			if(userDirection == "H")
			{
				printMyBoard();
				std::cout<<"Where would you like the head of this ship to be (The left most coordinate)?";
				std::cin>>userGuess;
				if(noHorizontalCollision(userGuess,i+1))
				{
					guessConversion(userGuess); //pushing two int indexes back to orignal spot of user guess
					for(int j = 0; j < m_ship[i].getLength(); j++ )
					{
						myBoard[m_rowIndex][m_columnIndex+j] = ship;
						//m_ship[i].setCoordinate(userGuess, j);

					}
				}


			}
		}

	}

}
