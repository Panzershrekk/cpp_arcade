//
// Created by huguet_t on 31/03/17.
//


#include <dlfcn.h>
#include <string>
#include <iostream>

int		main(int ac, char **av)
{
  int		pos;
  void		*lib;

  std::cout << ac << std::endl;
  if (ac > 2)
    exit(EXIT_FAILURE);
  else if (ac == 1)
    std::cout << "SFML" << std::endl;
  else
  {
    if ((lib = dlopen(av[1], RTLD_LAZY)) == NULL)
    {
      std::cout << "fail lib charge" << std::endl;
      exit(EXIT_FAILURE);
    }
  }
  exit(EXIT_SUCCESS);
}
