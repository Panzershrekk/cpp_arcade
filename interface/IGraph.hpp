/*
** IGameInterface.hpp for cpp_arcade in /home/fossae_t/rendu2/cpp_arcade/lib
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Mon Mar 13 16:42:14 2017 Thomas Fossaert
// Last update Wed Apr  5 13:37:01 2017
*/

#ifndef __IGRAPH_HPP__
# define __IGRAPH_HPP__

# include <iostream>
# include <map>
# include <vector>
# include <ncurses.h>
# include <utility>
# include "DLLoader.hpp"

namespace Game
{
  class IGame;
}

namespace Graph
{
  class IGraph
  {
    public:
      virtual void createMap() = 0;
      virtual void Game() = 0;
      virtual void SetSprite(int x, int y, Game::IGame *entity) = 0;
      virtual void UnsetSprite(int x, int y, Game::IGame *entity) = 0;
      virtual void Animation() = 0;
      virtual std::pair<std::string, std::string>	startMenu(const std::vector<std::string> &, const std::vector<std::string> &) = 0;
      virtual void displayMap(int **) = 0;
      virtual ~IGraph(void) { }
    };
}

#endif // __IGRAPH_HPP__
