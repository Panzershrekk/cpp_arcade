/*
** main.cpp for cpp_arcade in /home/fossae_t/rendu2/cpp_arcade
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Thu Mar 09 16:40:59 2017 Thomas Fossaert
** Last update Thu Mar 09 16:52:37 2017 Thomas Fossaert
*/

#include <iostream>

int   main(int ac, char **av)
{
  (void)av;
  if (ac != 2)
  {
    std::cout << "Bad argument" << '\n';
    return (42);
  }
  return (0);
}
