/*
** Pinky.cpp for cpp_arcade in /home/fossae_t/rendu2/cpp_arcade/games/gameman
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Thu Mar 09 17:02:17 2017 Thomas Fossaert
** Last update Wed Apr 05 18:09:16 2017 Thomas Fossaert
*/

#include "IGame.hpp"
#include "Pinky.hpp"

Pinky::Pinky()
{
  _posX = 13;
  _posY = 14;
  _state = Game::INVUNERABLE;
  _speed = 10;
  _isAlive = true;
  _direction = Game::Direction::UP;
  _type = 2;
  _score = 0;
  _inCase = true;
}

Pinky::Pinky(int x, int y)
{
  _posX = x;
  _posY = y;
  _state = Game::INVUNERABLE;
  _speed = 10;
  _isAlive = true;
  _direction = Game::Direction::UP;
  _type = 2;
  _score = 0;
  _inCase = true;
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

void Pinky::startCore(Arcade::DLLoader<Graph::IGraph> & core)
{
  (void) core;
}

void Pinky::movePlayer(std::map<int, std::map<int, int>>_gamemap)
{
  int nb = -1;
  int randcond = 0;

  if (_inCase == true)
  {
    if (_direction == Game::Direction::UP && _gamemap[_posY - 1][_posX] == 2)
      setDirection(Game::Direction::RIGHT);
    if (_direction == Game::Direction::RIGHT && _gamemap[_posY][_posX + 1] == 2)
      setDirection(Game::Direction::DOWN);
    if (_direction == Game::Direction::DOWN && _gamemap[_posY + 1][_posX] == 2)
      setDirection(Game::Direction::LEFT);
    if (_direction == Game::Direction::LEFT && _gamemap[_posY][_posX - 1] == 2)
      setDirection(Game::Direction::UP);

    if (_gamemap[_posY - 1][_posX] == 3)
      setDirection(Game::Direction::UP);

    if (_direction == Game::Direction::UP)
      setY(getY() - 1);
    if (_direction == Game::Direction::RIGHT)
      setX(getX() + 1);
    if (_direction == Game::Direction::DOWN)
      setY(getY() + 1);
    if (_direction == Game::Direction::LEFT)
      setX(getX() - 1);
    }
  else
    {
      if (_direction == Game::Direction::UP && (_gamemap[_posY - 1][_posX] == 2
      || _gamemap[_posY][_posX + 1] != 2
      || _gamemap[_posY][_posX - 1] != 2))
        nb = rand() % 4 + 1;
      else if (_direction == Game::Direction::RIGHT && (_gamemap[_posY][_posX + 1] == 2
        || _gamemap[_posY + 1][_posX] != 2
        || _gamemap[_posY - 1][_posX] != 2))
        nb = rand() % 4 + 1;
      else if (_direction == Game::Direction::DOWN && (_gamemap[_posY + 1][_posX] == 2
        || _gamemap[_posY][_posX + 1] != 2
        || _gamemap[_posY][_posX - 1] != 2))
        nb = rand() % 4 + 1;
      else if (_direction == Game::Direction::LEFT && (_gamemap[_posY][_posX - 1] == 2
        || _gamemap[_posY + 1][_posX] != 2
        || _gamemap[_posY - 1][_posX] != 2))
        nb = rand() % 4 + 1;

      if (nb != -1)
      {
        while (randcond != 1)
          {
            if (nb == 1 && (_gamemap[_posY - 1][_posX] != 2 && _gamemap[_posY - 1][_posX] != 3))
              {
                setDirection(Game::Direction::UP);
                randcond = 1;
              }
              else if (nb == 2 && (_gamemap[_posY][_posX + 1] != 2 && _gamemap[_posY][_posX + 1] != 3))
              {
                setDirection(Game::Direction::RIGHT);
                randcond = 1;
              }
              else if (nb == 3 && (_gamemap[_posY + 1][_posX] != 2 && _gamemap[_posY + 1][_posX] != 3))
              {
                setDirection(Game::Direction::DOWN);
                randcond = 1;
              }
              else if (nb == 4 && (_gamemap[_posY][_posX -1] != 2 && _gamemap[_posY][_posX - 1] != 3))
              {
                setDirection(Game::Direction::LEFT);
                randcond = 1;
              }
              else
              nb = rand() % 4 + 1;
            }
        }
      if (_direction == Game::Direction::UP)
        setY(getY() - 1);
      if (_direction == Game::Direction::RIGHT)
        setX(getX() + 1);
      if (_direction == Game::Direction::DOWN)
        setY(getY() + 1);
      if (_direction == Game::Direction::LEFT)
        setX(getX() - 1);

    }
    if (_gamemap[_posY][_posX] == 4)
      _inCase = false;
}

void Pinky::setX(int pos)
{
  _posX = pos;
}

void Pinky::setY(int pos)
{
  _posY = pos;
}

void Pinky::setState(Game::State pos)
{
  _state = pos;
}

void Pinky::setSpeed(size_t pos)
{
  _speed = pos;
}

void Pinky::setDirection(Game::Direction direction)
{
  _direction = direction;
}

void Pinky::setLive(bool live)
{
  _isAlive = live;
}

int Pinky::getX() const
{
  return (_posX);
}

int Pinky::getY() const
{
  return (_posY);
}

Game::State Pinky::getState() const
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

Game::Direction Pinky::getDirection() const
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

int Pinky::getScore() const
{
  return _score;
}

void Pinky::setScore(int s)
{
  _score = s;
}
