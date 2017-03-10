/*
** IGhost.hpp for cpp_arcade in /home/fossae_t/rendu2/cpp_arcade/games/pacman/include
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Thu Mar 09 17:01:36 2017 Thomas Fossaert
** Last update Fri Mar 10 08:56:47 2017 Thomas Fossaert
*/

#ifndef __IGHOST_HPP__
# define __IGHOST_HPP__

#include <iostream>

namespace pac
{
  enum State
 {
   INVUNERABLE = 0,
   VULNERABLE = 1
 };

  class IGhost
  {
    public:
      virtual void move() = 0;
      virtual void setX(int pos) = 0;
      virtual void setY(int pos) = 0;
      virtual void setState(pac::State pos) = 0;
      virtual void setSpeed(size_t pos) = 0;
      virtual int getX() const = 0;
      virtual int getY() const = 0;
      virtual pac::State getState() const = 0;
      virtual size_t getSpeed() const = 0;
      virtual bool isAlive() const = 0;
      virtual void Dump(void) const = 0;
      virtual ~IGhost(void) { };
    };
}

#endif // __IGHOST_HPP__
