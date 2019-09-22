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

void Ship::createShip(int length)   //createShip function that takes in length for parameter
{
  m_length = length;            //set m_length to the passed in length
  m_ship = new std::string[m_length];   //create a new array of strings of m_length (number of ships)
}

Ship::Ship()    //ship default constructor
{
  m_ship = nullptr;   //set m_ship member variable to nullptr
  m_length = 0;       //set m_length member variable to 0
  m_damage = 0;       //set m_damage member variable to 0
}

void Ship::setLength(int length)      //setLength function that takes in length
{
  m_length = length;    //set m_length to length variable
}

int Ship::getLength() const     //getLength function that returns the length of a ship
{
  return m_length;    //return m_length, the number of ships
}

void Ship::setCoordinate(std::string coordinate, int index)   //setCoordinate function taking in coordinate and index (for array)
{
  m_ship[index] = coordinate;   //set m_ship array at passed in index to coordinate
//  std::cout<<coordinate <<'\n';
}

std::string Ship::getCoordinate(int index) const    //getCoordinate function that takes in an index
{
  return m_ship[index];   //return the coordinate at the passed in index
}

Ship::~Ship()   //ship destructor
{
  delete[] m_ship;    //delete the m_ship array
}

void Ship::addDamage()    //addDamage function
{
  m_damage++;   //increment the damage by one when a ship is hit
}

int Ship::getDamage() const   //getDamage function that returns m_damage
{
  return m_damage;    //return m_damage
}

void Ship::setDamage(int newDamage)   //setDamage function that takes in an int for newDamage
{
  m_damage = newDamage;   //setting m_damage to newDamage
}

bool Ship::isSunk()   //isSunk() function that returns a boolean
{
  if(m_damage == m_length)    //if the damage equals the length of the ship
  {
    // std::cout << "\nis sunk\n" << "length: " << m_length << "\n";
    return true;    //return true, the ship is sunk
  }
  else    //if the damage does not equal the length of the ship
  {
    return false;   //return false, the ship is not sunk
  }
}
