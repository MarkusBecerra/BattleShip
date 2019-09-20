/**
* \Author: Chance Penner
* \Author: Markus Becerra
* \Author: Sarah Scott
* \Author: Thomas Gardner
* \Author: Haonan Hu
* \File:   Ship.cpp
* \Date:   09/19/2019
* \Brief:  File is cpp file
* \copyright: Group "Big SegFault Energy" All rights reserved
*/

#include "Ship.h"

void Ship::createShip(int length)
{
  m_length = length;
  m_ship = new std::string[m_length];
}

Ship::Ship()
{
std::string* m_ship = nullptr;
int m_length = 0;
int m_damage = 0;
bool m_Sunk = false;
}

void Ship::setLength(int length)
{
  m_length = length;
}

int Ship::getLength() const
{
  return m_length;
}

void Ship::setCoordinate(std::string coordinate, int index)
{
  m_ship[index] = coordinate;
}

Ship::~Ship()
{
  delete m_ship;
}
