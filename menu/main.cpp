//
// Created by huguet_t on 31/03/17.
//


#include <dlfcn.h>
#include <string>
#include <iostream>
#include "include/IGraph.hpp"

int		main(int ac, char **av)
{
  void		*lib;

  if (ac > 2)
    exit(EXIT_FAILURE);
  /*
  else if (ac == 1)
  {
    menu test;

    test.Game();
  }
  else
  */
  {
    if ((lib = dlopen(av[1], RTLD_LAZY)) == NULL)
      exit(EXIT_FAILURE);

    typedef void	(*func_ptr)();
    func_ptr func = (func_ptr)dlsym(lib,"do_menu");

    if (!func)
    {
      std::cout << "The error is    " << dlerror() << std::endl;
      exit(EXIT_FAILURE);
    }
    func();
  }
  exit(EXIT_SUCCESS);
}
