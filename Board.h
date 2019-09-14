
#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <iostream>

class Board
{
	private:
		std::string myBoard[8][8];
		std:string** m_ships = nullptr;
		m_ships = new String*[length];
		for(int i = 0; i < length;)
		std::string shotBoard[8][8];
		std::string m_rowNames = "ABCDEFGH";
		std::string m_columnNames = "12345678";
		int rowIndex;
		int ColumnIndex
		void guessConversion(std::string guess);
	public:
		Board();
		void printShotBoard();
		void printMyBoard();
		bool withinBoundary(std::string userGuess);

};
#endif
