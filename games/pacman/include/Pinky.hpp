/*
** Pinky.hpp for cpp_arcade in /home/fossae_t/rendu2/cpp_arcade/games/pacman/include
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Thu Mar 09 17:01:30 2017 Thomas Fossaert
** Last update Wed Mar 22 18:12:28 2017 Thomas Fossaert
*/

#include "IGame.hpp"

class Pinky : public game::IGame
{
  public:
    Pinky();
    ~Pinky();
    Pinky(Pinky const & other);
    Pinky& operator=(Pinky const & other);

    void move();
    void setX(int pos);
    void setY(int pos);
    void setState(game::State pos);
    void setSpeed(size_t pos);
    int getX() const;
    int getY() const;
    game::State getState() const;
    size_t getSpeed() const;
    bool isAlive() const;
    void Dump(void) const;
};
