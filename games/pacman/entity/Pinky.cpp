/*
** Pinky.cpp for cpp_arcade in /home/fossae_t/rendu2/cpp_arcade/games/gameman
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Thu Mar 09 17:02:17 2017 Thomas Fossaert
** Last update Fri Mar 24 08:50:31 2017 Thomas Fossaert
*/

#include "IGame.hpp"
#include "Pinky.hpp"

Pinky::Pinky()
{
  _posX = 13;
  _posY = 15;
  _state = game::INVUNERABLE;
  _speed = 10;
  _isAlive = true;
  _direction = gme::Direction::UP;
}

Pinky::~Pinky()
{
}

Pinky::Pinky(Pinky const & other)
{
  _posX = other._posX;
  _posY = other._posY;
  _state = other._state;
  _speed = other._speed;
  _isAlive = other._isAlive;
}

Pinky& Pinky::operator=(Pinky const & other)
{
  _posX = other._posX;
  _posY = other._posY;
  _state = other._state;
  _speed = other._speed;
  _isAlive = other._isAlive;
  return *this;
}

void Pinky::move()
{

}

void Pinky::setX(int pos)
{
  _posX = pos;
}

void Pinky::setY(int pos)
{
  _posY = pos;
}

void Pinky::setState(game::State pos)
{
  _state = pos;
}

void Pinky::setSpeed(size_t pos)
{
  _speed = pos;
}

int Pinky::getX() const
{
  return (_posX);
}

int Pinky::getY() const
{
  return (_posY);
}

game::State Pinky::getState() const
{
  return (_state);
}

size_t Pinky::getSpeed() const
{
  return (_speed);
}

bool  Pinky::isAlive() const
{
  return (false);
}

void Pinky::Dump(void) const
{
  std::cout << "Ghost: Pinky" << '\n';
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
