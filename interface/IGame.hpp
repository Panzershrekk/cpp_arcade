/*
** IGhost.hpp for cpp_arcade in /home/fossae_t/rendu2/cpp_arcade/games/pacman/include
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Thu Mar 09 17:01:36 2017 Thomas Fossaert
** Last update Wed Apr 05 17:58:34 2017 Thomas Fossaert
*/

#ifndef		__IGAME_HPP__
# define	__IGAME_HPP__

# include <iostream>
# include <map>
# include "IGraph.hpp"
# include "DLLoader.hpp"

namespace Game
{
  enum State
  {
    INVUNERABLE = 0,
    VULNERABLE = 1
  };

  enum Direction
  {
    UP = 0,
    RIGHT = 1,
    DOWN = 2,
    LEFT = 3
  };

  class IGame
  {
    public:
      virtual ~IGame(void) { };

      virtual void startCore(Arcade::DLLoader<Graph::IGraph> &) = 0;

      virtual void		movePlayer(std::map<int, std::map<int, int>>) = 0;
      virtual void		setX(int) = 0;
      virtual void		setY(int) = 0;
      virtual void		setState(Game::State) = 0;
      virtual void		setSpeed(size_t) = 0;
      virtual void		setDirection(Game::Direction) = 0;
      virtual void		setLive(bool) = 0;
      virtual int		getX(void) const = 0;
      virtual int		getY(void) const = 0;
      virtual Game::State	getState(void) const = 0;
      virtual size_t		getSpeed(void) const = 0;
      virtual Game::Direction	getDirection(void) const = 0;
      virtual int		getType(void) const = 0;
      virtual bool		isAlive(void) const = 0;
      virtual void		Dump(void) const = 0;
      virtual int		getScore(void) const = 0;
      virtual void		setScore(int) = 0;
  };
}

#endif		/* __IGAME_HPP__ */
