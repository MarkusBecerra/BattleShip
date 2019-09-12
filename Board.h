
#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <iostream>

class Board
{
	private:
		std::string myBoard[8][8];
		std::string shotBoard[8][8];
		std::string m_rowNames = "ABCDEFGH";
	public:
		Board();
		void printOpponentBoard();
		void printYouBoard();
};
#endif
