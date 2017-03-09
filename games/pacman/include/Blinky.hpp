/*
** Blinky.hpp for cpp_arcade in /home/fossae_t/rendu2/cpp_arcade/games/pacman/include
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Thu Mar 09 17:01:30 2017 Thomas Fossaert
** Last update Thu Mar 09 17:14:39 2017 Thomas Fossaert
*/

#include "IGhost.hpp"

class Blinky : public pac::IGhost
{
  private:
    int         _posX;
    int         _posY;
    pac::State  _state;
    size_t      _speed;
  public:
    Blinky();
    ~Blinky();
    Blinky(Blinky const & other);
    Blinky& operator=(Blinky const & other);

    void move();
    void setX(int pos);
    void setY(int pos);
    int getX() const;
    int getY() const;
    void Dump(void) const;
};
