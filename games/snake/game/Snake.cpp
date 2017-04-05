/*
** Pacman.cpp for cpp_arcade in /home/fossae_t/rendu2/cpp_arcade/games/gameman
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Thu Mar 09 17:02:17 2017 Thomas Fossaert
// Last update Tue Apr  4 20:28:33 2017 antoine
*/

#include "IGame.hpp"
#include "Snake.hpp"

Snake::Snake()
{
  Position tmp;

  _needGrowth = 0;
  tmp.x = 5;
  tmp.y = 4;
  _posSnake.push_back(tmp);
  tmp.x = 5;
  tmp.y = 3;
  _posSnake.push_back(tmp);
  // _posSnake[0].x = 5;
  // _posSnake[0].y = 5;
  _posX = 5;
  _posY = 5;
  _score = 0;
  _isAlive = true;
  _direction = game::Direction::DOWN;
}

Snake::~Snake()
{
}

Snake::Snake(Snake const & other)
{
  _score = other._score;
  _posX = other._posX;
  _posY = other._posY;
  _state = other._state;
  _speed = other._speed;
  _isAlive = other._isAlive;
}

Snake& Snake::operator=(Snake const & other)
{
  _score = other._score;
  _posX = other._posX;
  _posY = other._posY;
  _state = other._state;
  _speed = other._speed;
  _isAlive = other._isAlive;
  return *this;
}

void Snake::setLive(bool s)
{
  s++;
}

void Snake::setScore(int s)
{
  _score = s;
}

int Snake::getScore() const
{
  return (_score);
}

std::vector<Position> Snake::getPosSnake() const
{
  return (_posSnake);
}

void	Snake::setPosSnake(std::vector<Position> posSnake)
{
  _posSnake = posSnake;
}

void Snake::movePlayer(std::map<int, std::map<int, int>>_gamemap)
{
  if (_direction == game::Direction::UP)
    setY(getY() - 1);
  if (_direction == game::Direction::RIGHT)
    setX(getX() + 1);
  if (_direction == game::Direction::DOWN)
    setY(getY() + 1);
  if (_direction == game::Direction::LEFT)
    setX(getX() - 1);
  if (_gamemap[_posY][_posX] == 2)
    {
      _score += 10;
      _needGrowth = 1;
    }
  if (_gamemap[_posY][_posX] == 3 || _gamemap[_posY][_posX] == 1)
    {
      //DIE PAR RENTRAGE DANS LE MUR OUI CE MOT EXISTE PAS
    }
}

void	Snake::setNeedGrowth(int ng)
{
  _needGrowth = ng;
}

int	Snake::getNeedGrowth() const
{
  return (_needGrowth);
}

void Snake::setX(int pos)
{
  _posX = pos;
}

void Snake::setY(int pos)
{
  _posY = pos;
}

void Snake::setDirection(game::Direction direction)
{
  _direction = direction;
}

int Snake::getX() const
{
  return (_posX);
}

int Snake::getY() const
{
  return (_posY);
}

bool  Snake::isAlive() const
{
  return (false);
}

game::Direction Snake::getDirection() const
{
  return (_direction);
}

void Snake::Dump(void) const
{
  std::cout << "Snake:" << '\n';
  std::cout << "Pos X: " << getX() << '\n';
  std::cout << "Pos Y: " << getY() << '\n';
  std::cout << "ALive: " << _isAlive << '\n';
}

void	Snake::setState(game::State state)
{
  (void) state;
}


void	Snake::setSpeed(size_t speed)
{
  (void) speed;
}


game::State	Snake::getState() const
{
  return(_state);
}

size_t Snake::getSpeed() const
{
  return (_speed);
}

int Snake::getType() const
{
  return (1);
}
