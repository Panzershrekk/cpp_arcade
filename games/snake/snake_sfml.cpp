/*
** main.cpp for cpp_arcade in /home/fossae_t/rendu2/cpp_arcade
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Thu Mar 09 16:40:59 2017 Thomas Fossaert
// Last update Thu Apr  6 22:38:06 2017 antoine
*/

#include <iostream>
#include <fstream>
#include "IGame.hpp"
#include "IGraph.hpp"
#include "gameMapSfmlSnake.hpp"
// #include "ArcadeException.hpp"

extern "C" void   snake_SFML()
{
  gameMapSfmlSnake *map = new gameMapSfmlSnake();

  map->Game();
}
