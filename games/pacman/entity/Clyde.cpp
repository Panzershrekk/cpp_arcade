/*
** Clyde.cpp for cpp_arcade in /home/fossae_t/rendu2/cpp_arcade/games/gameman
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Thu Mar 09 17:02:17 2017 Thomas Fossaert
** Last update Fri Mar 31 12:53:10 2017 Thomas Fossaert
*/

#include "IGame.hpp"
#include "Clyde.hpp"

Clyde::Clyde()
{
  _posX = 14;
  _posY = 14;
  _state = game::INVUNERABLE;
  _speed = 10;
  _isAlive = true;
  _direction = game::Direction::UP;
  _type = 4;
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

void Clyde::move(std::map<int, std::map<int, int>>_gamemap)
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

void Clyde::setDirection(game::Direction direction)
{
  _direction = direction;
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

game::Direction Clyde::getDirection() const
{
  return (_direction);
}

int Clyde::getType() const
{
  return (_type);
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
