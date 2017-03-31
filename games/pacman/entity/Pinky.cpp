/*
** Pinky.cpp for cpp_arcade in /home/fossae_t/rendu2/cpp_arcade/games/gameman
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Thu Mar 09 17:02:17 2017 Thomas Fossaert
** Last update Fri Mar 31 09:33:56 2017 Thomas Fossaert
*/

#include "IGame.hpp"
#include "Pinky.hpp"

Pinky::Pinky()
{
  _posX = 13;
  _posY = 14;
  _state = game::INVUNERABLE;
  _speed = 10;
  _isAlive = true;
  _direction = game::Direction::UP;
  _type = 1;
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

void Pinky::move(std::map<int, std::map<int, int>>_gamemap)
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

void Pinky::setDirection(game::Direction direction)
{
  _direction = direction;
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

game::Direction Pinky::getDirection() const
{
  return (_direction);
}

int Pinky::getType() const
{
  return (_type);
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
