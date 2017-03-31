/*
** Blinky.cpp for cpp_arcade in /home/fossae_t/rendu2/cpp_arcade/games/gameman
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Thu Mar 09 17:02:17 2017 Thomas Fossaert
** Last update Fri Mar 31 10:52:22 2017 Thomas Fossaert
*/

#include "IGame.hpp"
#include "Blinky.hpp"

Blinky::Blinky()
{
  _posX = 13;
  _posY = 13;
  _state = game::INVUNERABLE;
  _speed = 10;
  _isAlive = true;
  _direction = game::Direction::UP;
  _type = 1;
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

void Blinky::move(std::map<int, std::map<int, int>>_gamemap)
{
  if (_direction == game::Direction::UP && _gamemap[_posY - 1][_posX] == 2)
    setDirection(game::Direction::RIGHT);
  if (_direction == game::Direction::RIGHT && _gamemap[_posY][_posX + 1] == 2)
    setDirection(game::Direction::DOWN);
  if (_direction == game::Direction::DOWN && _gamemap[_posY + 1][_posX] == 2)
    setDirection(game::Direction::LEFT);
  if (_direction == game::Direction::LEFT && _gamemap[_posY][_posX - 1] == 2)
    setDirection(game::Direction::UP);

  if (_direction == game::Direction::UP)
      setY(getY() - 1);
  if (_direction == game::Direction::RIGHT)
      setX(getX() + 1);
  if (_direction == game::Direction::DOWN)
      setY(getY() + 1);
  if (_direction == game::Direction::LEFT)
      setX(getX() - 1);
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

void Blinky::setDirection(game::Direction direction)
{
  _direction = direction;
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

game::Direction Blinky::getDirection() const
{
  return (_direction);
}

int Blinky::getType() const
{
  return (_type);
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
