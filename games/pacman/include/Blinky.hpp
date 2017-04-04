/*
** Blinky.hpp for cpp_arcade in /home/fossae_t/rendu2/cpp_arcade/games/pacman/include
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Thu Mar 09 17:01:30 2017 Thomas Fossaert
** Last update Tue Apr 04 14:02:07 2017 Thomas Fossaert
*/

#include "IGame.hpp"

class Blinky : public game::IGame
{
  private:
    int         _posX;
    int         _posY;
    game::State _state;
    game::Direction _direction;
    size_t      _speed;
    bool        _isAlive;
    int		      _score;

    int         _type;
  public:
    Blinky();
    Blinky(int x, int y);
    ~Blinky();
    Blinky(Blinky const & other);
    Blinky& operator=(Blinky const & other);

    void move(std::map<int, std::map<int, int>> _gamemap);
    void setX(int pos);
    void setY(int pos);
    void setState(game::State pos);
    void setSpeed(size_t pos);
    void setDirection(game::Direction);
    void setLive(bool);
    int getX() const;
    int getY() const;
    game::State getState() const;
    size_t getSpeed() const;
    int getType() const;
    bool isAlive() const;
    game::Direction getDirection() const;

    int getScore() const;
    void setScore(int s);

    void Dump(void) const;
};
