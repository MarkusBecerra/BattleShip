
#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <iostream>
#include <stdexcept>
#include "Ship.h"

class Board
{
	private:
		std::string shotBoard[8][8];
		std::string myBoard[8][8];
		std::string m_rowNames = "ABCDEFGH";
		std::string m_columnNames = "12345678";
		int m_rowIndex;
		int m_columnIndex;
		void guessConversion(std::string userGuess);	//converts userGuess to two array indices, updating rowIndex and columnIndex

		std::string blueTilde;
		std::string redHit;
		std::string whiteMiss;
		std::string ship;
		int numberOfShips;
		Ship* m_ship = nullptr;

	public:
		Board(int shipnum);
		Board();
		void printShotBoard();
		void printMyBoard();
		void printIntermission();

		void setNumberOfShips(int shipnum);
		void getNumberofShips();

		void setupBoard(); //asks the player where they want to place the ships. uses with withinBoundary and edits myBoard and shotBoard

		void updateShotBoard(std::string userGuess, bool wasHit); //if blueTilde, change to whiteMiss, if whiteMiss, prints you already shot here, if redHit, prints you already shot here, if ship, change to redHit
		bool updateMyBoard(std::string userGuess); //if blueTilde, change to whiteMiss, if whiteMiss, prints you already shot here, if redHit, prints you already shot here, if ship, change to redHit, return whether it hit a ship

		bool withinBoundary(std::string userGuess);	//gets called from Player shoot function. Calls guessConversion. Needs to check for valid input.
		bool noHorizontalCollision(std::string userGuess, int shipLength);
	};
#endif
