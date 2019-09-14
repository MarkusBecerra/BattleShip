
#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <iostream>

class Board
{
	private:
		std::string shotBoard[8][8];
		std::string myBoard[8][8];
		std::string m_rowNames = "ABCDEFGH";
		std::string m_columnNames = "12345678";
		int rowIndex;
		int columnIndex;
		void guessConversion(std::string userGuess);	//converts userGuess to two array indices, updating rowIndex and columnIndex

	public:
		Board();
		void printShotBoard();
		void printMyBoard();

		void setupBoard(int numberOfShips); //asks the player where they want to place the ships. uses with withinBoundary and edits myBoard and shotBoard

		void updateShotBoard(std::string userGuess, bool wasHit); //if blueTilde, change to whiteMiss, if whiteMiss, prints you already shot here, if redHit, prints you already shot here, if ship, change to redHit
		void updateMyBoard(std::string userGuess); //if blueTilde, change to whiteMiss, if whiteMiss, prints you already shot here, if redHit, prints you already shot here, if ship, change to redHit

		bool withinBoundary(std::string userGuess);	//gets called from Player shoot function. Calls guessConversion. Needs to check for valid input.
	};
#endif
