/*
** IGameInterface.hpp for cpp_arcade in /home/fossae_t/rendu2/cpp_arcade/lib
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Mon Mar 13 16:42:14 2017 Thomas Fossaert
** Last update Wed Mar 22 15:51:26 2017 Thomas Fossaert
*/

#ifndef __IGRAPH_HPP__
# define __IGRAPH_HPP__

#include <iostream>
#include <map>
#include <ncurses.h>

namespace graph
{
  class IGraph
  {
    protected:
      std::map<int, std::map<int, int>> _gamemap;
    public:
      virtual void createMap() = 0;
      virtual void Game() = 0;
      virtual void SetSprite() = 0;
      virtual void UnsetSprite() = 0;
      virtual void Animation() = 0;
      virtual ~IGraph(void) { }
    };
}

#endif // __IGRAPH_HPP__
