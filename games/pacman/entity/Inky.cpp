/*
** Inky.cpp for cpp_arcade in /home/fossae_t/rendu2/cpp_arcade/games/gameman
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Thu Mar 09 17:02:17 2017 Thomas Fossaert
** Last update Thu Mar 23 16:50:01 2017 Thomas Fossaert
*/

#include "IGame.hpp"
#include "Inky.hpp"

Inky::Inky()
{
  _posX = 12;
  _posY = 15;
  _state = game::INVUNERABLE;
  _speed = 10;
  _isAlive = true;
}

Inky::~Inky()
{
}

Inky::Inky(Inky const & other)
{
  _posX = other._posX;
  _posY = other._posY;
  _state = other._state;
  _speed = other._speed;
  _isAlive = other._isAlive;
}

Inky& Inky::operator=(Inky const & other)
{
  _posX = other._posX;
  _posY = other._posY;
  _state = other._state;
  _speed = other._speed;
  _isAlive = other._isAlive;
  return *this;
}

void Inky::move()
{

}

void Inky::setX(int pos)
{
  _posX = pos;
}

void Inky::setY(int pos)
{
  _posY = pos;
}

void Inky::setState(game::State pos)
{
  _state = pos;
}

void Inky::setSpeed(size_t pos)
{
  _speed = pos;
}

int Inky::getX() const
{
  return (_posX);
}

int Inky::getY() const
{
  return (_posY);
}

game::State Inky::getState() const
{
  return (_state);
}

size_t Inky::getSpeed() const
{
  return (_speed);
}

bool  Inky::isAlive() const
{
  return (false);
}

void Inky::Dump(void) const
{
  std::cout << "Ghost: Inky" << '\n';
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
