/*
** Pacman.cpp for cpp_arcade in /home/fossae_t/rendu2/cpp_arcade/games/gameman
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Thu Mar 09 17:02:17 2017 Thomas Fossaert
** Last update Fri Mar 31 10:40:52 2017 Thomas Fossaert
*/

#include "IGame.hpp"
#include "Pacman.hpp"

Pacman::Pacman()
{
  _posX = 13;
  _posY = 17;
  _state = game::VULNERABLE;
  _speed = 10;
  _isAlive = true;
  _direction = game::Direction::LEFT;
  _type = 0;
}

Pacman::~Pacman()
{
}

Pacman::Pacman(Pacman const & other)
{
  _posX = other._posX;
  _posY = other._posY;
  _state = other._state;
  _speed = other._speed;
  _isAlive = other._isAlive;
}

Pacman& Pacman::operator=(Pacman const & other)
{
  _posX = other._posX;
  _posY = other._posY;
  _state = other._state;
  _speed = other._speed;
  _isAlive = other._isAlive;
  return *this;
}

void Pacman::move(std::map<int, std::map<int, int>>_gamemap)
{
  if (_direction == game::Direction::UP && _gamemap[_posY - 1][_posX] != 2)
      setY(getY() - 1);
  if (_direction == game::Direction::RIGHT && _gamemap[_posY][_posX + 1] != 2)
      setX(getX() + 1);
  if (_direction == game::Direction::DOWN && _gamemap[_posY + 1][_posX] != 2)
      setY(getY() + 1);
  if (_direction == game::Direction::LEFT && _gamemap[_posY][_posX - 1] != 2)
      setX(getX() - 1);
}

void Pacman::setX(int pos)
{
  _posX = pos;
}

void Pacman::setY(int pos)
{
  _posY = pos;
}

void Pacman::setState(game::State pos)
{
  _state = pos;
}

void Pacman::setSpeed(size_t pos)
{
  _speed = pos;
}

void Pacman::setDirection(game::Direction direction)
{
  _direction = direction;
}

int Pacman::getX() const
{
  return (_posX);
}

int Pacman::getY() const
{
  return (_posY);
}

game::State Pacman::getState() const
{
  return (_state);
}

size_t Pacman::getSpeed() const
{
  return (_speed);
}

bool  Pacman::isAlive() const
{
  return (false);
}

game::Direction Pacman::getDirection() const
{
  return (_direction);
}

int Pacman::getType() const
{
  return (_type);
}

void Pacman::Dump(void) const
{
  std::cout << "Ghost: Pacman" << '\n';
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
