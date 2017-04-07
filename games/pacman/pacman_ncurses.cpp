/*
** main.cpp for cpp_arcade in /home/fossae_t/rendu2/cpp_arcade
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Thu Mar 09 16:40:59 2017 Thomas Fossaert
// Last update Thu Apr  6 15:58:53 2017 Thomas Fossaert
*/

#include <iostream>
#include <fstream>
#include "IGame.hpp"
#include "IGraph.hpp"
#include "gameMapNcurses.hpp"

extern "C" void   pacman_ncurses()
{
  gameMapNcurses *map = new gameMapNcurses();

  map->Game();
  delete map;
}
