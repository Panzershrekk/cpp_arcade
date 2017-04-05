/*
** Pacman.hpp for cpp_arcade in /home/fossae_t/rendu2/cpp_arcade/games/pacman/include
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Thu Mar 09 17:01:30 2017 Thomas Fossaert
** Last update Wed Apr 05 15:45:58 2017 Thomas Fossaert
*/

#include "IGame.hpp"

class Pacman : public game::IGame
{
  private:
    int         _posX;
    int         _posY;
    game::State _state;
    game::Direction _direction;
    size_t      _speed;
    bool        _isAlive;
    int		      _score;

    int _type;
  public:
    Pacman();
    Pacman(int x, int y);

    ~Pacman();
    Pacman(Pacman const & other);
    Pacman& operator=(Pacman const & other);

    void movePlayer(std::map<int, std::map<int, int>> _gamemap);
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
    bool isAlive() const;
    game::Direction getDirection() const;
    int getType() const;
    void Dump(void) const;

    int getScore() const;
    void setScore(int s);
};
