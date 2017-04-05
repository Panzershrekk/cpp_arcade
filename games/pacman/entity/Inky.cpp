/*
** Inky.cpp for cpp_arcade in /home/fossae_t/rendu2/cpp_arcade/games/gameman
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Thu Mar 09 17:02:17 2017 Thomas Fossaert
** Last update Wed Apr 05 15:45:22 2017 Thomas Fossaert
*/

#include "IGame.hpp"
#include "Inky.hpp"

Inky::Inky()
{
  _posX = 12;
  _posY = 14;
  _state = game::INVUNERABLE;
  _speed = 10;
  _isAlive = true;
  _direction = game::Direction::UP;
  _type = 3;
  _score = 0;
  _inCase = true;
}

Inky::Inky(int x, int y)
{
  _posX = x;
  _posY = y;
  _state = game::INVUNERABLE;
  _speed = 10;
  _isAlive = true;
  _direction = game::Direction::UP;
  _type = 3;
  _score = 0;
  _inCase = true;
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

void Inky::movePlayer(std::map<int, std::map<int, int>>_gamemap)
{
  int nb = -1;
  int randcond = 0;

  if (_inCase == true)
  {
    if (_direction == game::Direction::UP && _gamemap[_posY - 1][_posX] == 2)
      setDirection(game::Direction::RIGHT);
    if (_direction == game::Direction::RIGHT && _gamemap[_posY][_posX + 1] == 2)
      setDirection(game::Direction::DOWN);
    if (_direction == game::Direction::DOWN && _gamemap[_posY + 1][_posX] == 2)
      setDirection(game::Direction::LEFT);
    if (_direction == game::Direction::LEFT && _gamemap[_posY][_posX - 1] == 2)
      setDirection(game::Direction::UP);

    if (_gamemap[_posY - 1][_posX] == 3)
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
  else
    {
      if (_direction == game::Direction::UP && (_gamemap[_posY - 1][_posX] == 2
      || _gamemap[_posY][_posX + 1] != 2
      || _gamemap[_posY][_posX - 1] != 2))
        nb = rand() % 4 + 1;
      else if (_direction == game::Direction::RIGHT && (_gamemap[_posY][_posX + 1] == 2
        || _gamemap[_posY + 1][_posX] != 2
        || _gamemap[_posY - 1][_posX] != 2))
        nb = rand() % 4 + 1;
      else if (_direction == game::Direction::DOWN && (_gamemap[_posY + 1][_posX] == 2
        || _gamemap[_posY][_posX + 1] != 2
        || _gamemap[_posY][_posX - 1] != 2))
        nb = rand() % 4 + 1;
      else if (_direction == game::Direction::LEFT && (_gamemap[_posY][_posX - 1] == 2
        || _gamemap[_posY + 1][_posX] != 2
        || _gamemap[_posY - 1][_posX] != 2))
        nb = rand() % 4 + 1;

      if (nb != -1)
      {
        while (randcond != 1)
          {
            if (nb == 1 && (_gamemap[_posY - 1][_posX] != 2 && _gamemap[_posY - 1][_posX] != 3))
              {
                setDirection(game::Direction::UP);
                randcond = 1;
              }
              else if (nb == 2 && (_gamemap[_posY][_posX + 1] != 2 && _gamemap[_posY][_posX + 1] != 3))
              {
                setDirection(game::Direction::RIGHT);
                randcond = 1;
              }
              else if (nb == 3 && (_gamemap[_posY + 1][_posX] != 2 && _gamemap[_posY + 1][_posX] != 3))
              {
                setDirection(game::Direction::DOWN);
                randcond = 1;
              }
              else if (nb == 4 && (_gamemap[_posY][_posX -1] != 2 && _gamemap[_posY][_posX - 1] != 3))
              {
                setDirection(game::Direction::LEFT);
                randcond = 1;
              }
              else
              nb = rand() % 4 + 1;
            }
        }
      if (_direction == game::Direction::UP)
        setY(getY() - 1);
      if (_direction == game::Direction::RIGHT)
        setX(getX() + 1);
      if (_direction == game::Direction::DOWN)
        setY(getY() + 1);
      if (_direction == game::Direction::LEFT)
        setX(getX() - 1);

    }
    if (_gamemap[_posY][_posX] == 4)
      _inCase = false;
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

void Inky::setDirection(game::Direction direction)
{
  _direction = direction;
}

void Inky::setLive(bool live)
{
  _isAlive = live;
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

game::Direction Inky::getDirection() const
{
  return (_direction);
}

int Inky::getType() const
{
  return (_type);
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

int Inky::getScore() const
{
  return _score;
}

void Inky::setScore(int s)
{
  _score = s;
}
