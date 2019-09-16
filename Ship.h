#ifndef SHIP_H
#define SHIP_H

#include <string>
#include <iostream>
#include <fstream>

class Ship
{
private:
std::string* m_ship = nullptr;
int length;

public:
Ship();
void createShip();
void setCoordinate(std::string coordinate, int index);
std::string getCoordinate(int index);
void setLength(int length);
int getLength();
~Ship();


};
#endif
