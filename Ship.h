#ifndef SHIP_H
#define SHIP_H

#include <string>
#include <iostream>
#include <fstream>

class Ship
{
private:
std::string* m_ship = nullptr;
int m_length;
int m_damage = 0;
bool m_Sunk = false;

public:
Ship();
void createShip(int length);
//void createShip(int length, int shipNumber);
//bool ConsecutiveCoordinates(int index) I DONT THINK WE NEED THIS
void setCoordinate(std::string coordinate, int index);
std::string getCoordinate(int index);
void setLength(int length);
int getLength();
~Ship();
bool isSunk();

};
#endif
