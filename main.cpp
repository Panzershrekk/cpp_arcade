//
// Created by huguet_t on 31/03/17.
//


#include <dlfcn.h>
#include <string>
#include <iostream>
#include "IGraph.hpp"

int		main(int ac, char **av)
{
  void *lib;

  if (ac == 2)
  {
    if ((lib = dlopen(av[1], RTLD_LAZY)) == NULL)
    {
      std::cout << "error: failed to load the lib" << av[1] << std::endl;
      exit(EXIT_FAILURE);
    }

    typedef void        (*func_ptr)();
    func_ptr func = (func_ptr) dlsym(lib, "do_menu");

    if (!func)
    {
      std::cout << "error: failed to load the function" << func << std::endl;
      exit(EXIT_FAILURE);
    }
    func();
    dlclose(lib);
    exit(EXIT_SUCCESS);
  }
  else
  {
    std::cout << "./arcade lib" << std::endl;
    exit(EXIT_FAILURE);
  }
}
