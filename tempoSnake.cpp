/*
** main.cpp for cpp_arcade in /home/fossae_t/rendu2/cpp_arcade
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Thu Mar 09 16:40:59 2017 Thomas Fossaert
// Last update Mon Apr  3 13:34:45 2017 antoine
*/

#include <iostream>
#include <fstream>
#include "IGame.hpp"
#include "IGraph.hpp"
// #include "gameMapNcurses.hpp"
#include "gameMapNcursesSnake.hpp"
#include "ArcadeException.hpp"

int   main(int ac, char **av)
{
  ac++;
  if (av[1][0] == 's')
    {
      gameMapNcursesSnake *map = new gameMapNcursesSnake();
      map->DumpMap();
      map->Game();    
    }
  // else
  //   {
  //     gameMapNcurses *map = new gameMapNcurses();
  //     map->DumpMap();
  //     map->Game();
  //     (void)av;
  //     if (ac != 2)
  // 	{
  // 	  std::cout << "Bad argument" << '\n';
  // 	  return (42);
  // 	}
  //     return (0);
  //   }
}
