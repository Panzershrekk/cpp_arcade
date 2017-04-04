/*
** Inky.hpp for cpp_arcade in /home/fossae_t/rendu2/cpp_arcade/games/pacman/include
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Thu Mar 09 17:01:30 2017 Thomas Fossaert
** Last update Tue Apr 04 12:04:30 2017 Thomas Fossaert
*/

#include "IGame.hpp"

class Inky : public game::IGame
{
  private:
    int _type;
  public:
    Inky();
    ~Inky();
    Inky(Inky const & other);
    Inky& operator=(Inky const & other);

    void move(std::map<int, std::map<int, int>>);
    void setX(int pos);
    void setY(int pos);
    void setState(game::State pos);
    void setSpeed(size_t pos);
    void setDirection(game::Direction);
    void setLive(bool);
    int getX() const;
    int getY() const;
    game::State getState() const;
    int getType() const;
    size_t getSpeed() const;
    bool isAlive() const;
    game::Direction getDirection() const;
    void Dump(void) const;
};
