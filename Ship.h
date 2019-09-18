#ifndef SHIP_H
#define SHIP_H

#include <string>
#include <iostream>
#include <fstream>

class Ship
{
private:
int m_shipNumber;
std::string* m_ship = nullptr;
int length
int damage = 0;
int* x_CoordinateList = nullptr;
int* y_CoordinateList = nullptr;
bool m_Sunk = false;

public:
Ship();
void createShip(int length, int shipNumber);
//void createShip(int length, int shipNumber);
void setCoordinate(std::string coordinate, int index, int* xCoordinateList, int* yCoordinateList);
std::string getCoordinate(int index);
void setLength(int length);
int getLength();
~Ship();
bool isSunk();

};
#endif
