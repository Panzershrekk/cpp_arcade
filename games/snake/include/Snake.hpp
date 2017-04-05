//
// Snake.hpp for snake in /home/antoine/Bureau/Epi/Arcade/cpp_arcade/games/snake/include
//
// Made by antoine
// Login   <antoine@epitech.net>
//
// Started on  Mon Apr  3 11:43:45 2017 antoine
// Last update Tue Apr  4 19:52:34 2017 antoine
//

#include "IGame.hpp"
#include <vector>

#ifndef _SNAKE_
# define _SNAKE_

class Position {
public:
  int x;
  int y;
};

class Snake : public Game::IGame
{
  private:
    int         _posX;
    int         _posY;
    Game::State _state;
    Game::Direction _direction;
    size_t      _speed;
    bool        _isAlive;
    int		      _score;

    int _type;
  std::vector<Position> _posSnake;
  int _needGrowth;
public:
  Snake();
  ~Snake();
    Snake(Snake const & other);
    Snake& operator=(Snake const & other);

    void startCore(Arcade::DLLoader<Graph::IGraph> & core);
    void movePlayer(std::map<int, std::map<int, int>> _gamemap);
    void setX(int pos);
    void setY(int pos);
    void setDirection(Game::Direction);
    int getX() const;
    int getY() const;
    bool isAlive() const;
    Game::Direction getDirection() const;
    void Dump(void) const;
  void setState(Game::State);
  void setSpeed(size_t);
  Game::State getState() const;
  size_t getSpeed() const;
  int getType() const;
  int getScore() const;
  void setScore(int s);
  std::vector<Position> getPosSnake() const;
  void setPosSnake(std::vector<Position>);
  int getNeedGrowth() const;
  void setNeedGrowth(int);
  void setLive(bool);
};

#endif
