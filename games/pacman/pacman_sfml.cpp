/*
** main.cpp for cpp_arcade in /home/fossae_t/rendu2/cpp_arcade
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Thu Mar 09 16:40:59 2017 Thomas Fossaert
// Last update Wed Apr  5 14:24:26 2017 
*/

#include <iostream>
#include <fstream>
#include "IGame.hpp"
#include "IGraph.hpp"
#include "gameMapSfml.hpp"
// #include "ArcadeException.hpp"

extern "C" void   pacman_SFML()
{
  gameMapSfml map;

  map.DumpMap();
  map.Game();
}
