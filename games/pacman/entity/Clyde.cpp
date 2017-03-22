/*
** Clyde.cpp for cpp_arcade in /home/fossae_t/rendu2/cpp_arcade/games/gameman
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Thu Mar 09 17:02:17 2017 Thomas Fossaert
** Last update Wed Mar 22 18:12:47 2017 Thomas Fossaert
*/

#include "IGame.hpp"
#include "Clyde.hpp"

Clyde::Clyde()
{
  _posX = 0;
  _posY = 0;
  _state = game::INVUNERABLE;
  _speed = 10;
  _isAlive = true;
}

Clyde::~Clyde()
{
}

Clyde::Clyde(Clyde const & other)
{
  _posX = other._posX;
  _posY = other._posY;
  _state = other._state;
  _speed = other._speed;
  _isAlive = other._isAlive;
}

Clyde& Clyde::operator=(Clyde const & other)
{
  _posX = other._posX;
  _posY = other._posY;
  _state = other._state;
  _speed = other._speed;
  _isAlive = other._isAlive;
  return *this;
}

void Clyde::move()
{

}

void Clyde::setX(int pos)
{
  _posX = pos;
}

void Clyde::setY(int pos)
{
  _posY = pos;
}

void Clyde::setState(game::State pos)
{
  _state = pos;
}

void Clyde::setSpeed(size_t pos)
{
  _speed = pos;
}

int Clyde::getX() const
{
  return (_posX);
}

int Clyde::getY() const
{
  return (_posY);
}

game::State Clyde::getState() const
{
  return (_state);
}

size_t Clyde::getSpeed() const
{
  return (_speed);
}

bool  Clyde::isAlive() const
{
  return (false);
}

void Clyde::Dump(void) const
{
  std::cout << "Ghost: Clyde" << '\n';
  std::cout << "Pos X: " << getX() << '\n';
  std::cout << "Pos Y: " << getY() << '\n';
  std::cout << "State: ";
  if (_state == 0)
    std::cout << "INVUNERABLE" << '\n';
  else
    std::cout << "VULNERABLE" << '\n';
  std::cout << "Speed: " << _speed << '\n';
  std::cout << "ALive: " << _isAlive << '\n';
}
