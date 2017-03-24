/*
** IGhost.hpp for cpp_arcade in /home/fossae_t/rendu2/cpp_arcade/games/pacman/include
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Thu Mar 09 17:01:36 2017 Thomas Fossaert
** Last update Fri Mar 24 17:15:15 2017 Thomas Fossaert
*/

#ifndef __IGAME_HPP__
# define __IGAME_HPP__

#include <iostream>
#include <map>

namespace game
{
  enum State
 {
   INVUNERABLE = 0,
   VULNERABLE = 1
 };

  enum Direction  // Direction de l'entité
  {
    UP = 0,
    RIGHT = 1,
    DOWN = 2,
    LEFT = 3
  };

  class IGame
  {
    protected:
      int         _posX;
      int         _posY;
      game::State _state;
      game::Direction _direction;
      size_t      _speed;
      bool        _isAlive;

    public:
      virtual void move(std::map<int, std::map<int, int>>) = 0;
      virtual void setX(int pos) = 0;
      virtual void setY(int pos) = 0;
      virtual void setState(game::State state) = 0;
      virtual void setSpeed(size_t speed) = 0;
      virtual void setDirection(game::Direction) = 0; //Seteur de Direction
      //virtual void setPoint(size_t point) = 0;
      virtual int getX() const = 0;
      virtual int getY() const = 0;
      virtual game::State getState() const = 0;
      virtual size_t getSpeed() const = 0;
      virtual game::Direction getDirection() const = 0; //Getteu direcion
      virtual int getType() const = 0;
      //virtual size_t getPoint() const = 0;
      virtual bool isAlive() const = 0;
      virtual void Dump(void) const = 0;
      virtual ~IGame(void) { };
    };
}

#endif // __IGAME_HPP__
