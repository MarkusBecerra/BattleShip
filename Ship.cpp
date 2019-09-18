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

int Ship::getLength()
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
