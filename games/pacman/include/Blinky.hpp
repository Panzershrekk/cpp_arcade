/*
** Blinky.hpp for cpp_arcade in /home/fossae_t/rendu2/cpp_arcade/games/pacman/include
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Thu Mar 09 17:01:30 2017 Thomas Fossaert
** Last update Thu Apr 06 16:24:24 2017 Thomas Fossaert
*/

#ifndef _BLINKY_HPP_
# define _BLINKY_HPP_

#include "IGame.hpp"

class Blinky : public Game::IGame
{
  private:
    int         _posX;
    int         _posY;
    Game::State _state;
    Game::Direction _direction;
    size_t      _speed;
    bool        _isAlive;
    int		      _score;

    int         _type;
    bool         _inCase;
  public:
    Blinky();
    Blinky(int x, int y);
    ~Blinky();
    Blinky(Blinky const & other);
    Blinky& operator=(Blinky const & other);

    void startCore(Arcade::DLLoader<Graph::IGraph> &);
    void movePlayer(std::map<int, std::map<int, int>> _gamemap);
    void setX(int pos);
    void setY(int pos);
    void setState(Game::State pos);
    void setSpeed(size_t pos);
    void setDirection(Game::Direction);
    void setLive(bool);
    int getX() const;
    int getY() const;
    Game::State getState() const;
    size_t getSpeed() const;
    int getType() const;
    bool isAlive() const;
    Game::Direction getDirection() const;

    int getScore() const;
    void setScore(int s);

    void Dump(void) const;
};

#endif
