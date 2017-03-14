/*
** Blinky.cpp for cpp_arcade in /home/fossae_t/rendu2/cpp_arcade/games/gameman
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Thu Mar 09 17:02:17 2017 Thomas Fossaert
** Last update Tue Mar 14 09:07:14 2017 Thomas Fossaert
*/

#include "IGame.hpp"
#include "Blinky.hpp"

Blinky::Blinky()
{
  _posX = 0;
  _posY = 0;
  _state = game::INVUNERABLE;
  _speed = 10;
  _isAlive = true;
}

Blinky::~Blinky()
{
}

Blinky::Blinky(Blinky const & other)
{
  _posX = other._posX;
  _posY = other._posY;
  _state = other._state;
  _speed = other._speed;
  _isAlive = other._isAlive;
}

Blinky& Blinky::operator=(Blinky const & other)
{
  _posX = other._posX;
  _posY = other._posY;
  _state = other._state;
  _speed = other._speed;
  _isAlive = other._isAlive;
  return *this;
}

void Blinky::move()
{

}

void Blinky::setX(int pos)
{
  _posX = pos;
}

void Blinky::setY(int pos)
{
  _posY = pos;
}

void Blinky::setState(game::State pos)
{
  _state = pos;
}

void Blinky::setSpeed(size_t pos)
{
  _speed = pos;
}

int Blinky::getX() const
{
  return (_posX);
}

int Blinky::getY() const
{
  return (_posY);
}

game::State Blinky::getState() const
{
  return (_state);
}

size_t Blinky::getSpeed() const
{
  return (_speed);
}

bool  Blinky::isAlive() const
{
  return (false);
}

void Blinky::Dump(void) const
{
  std::cout << "Ghost: Blinky" << '\n';
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
