#ifndef		_CPP_ARCADE_DLLOADER__HPP_
#define		_CPP_ARCADE_DLLOADER__HPP_

# include <dlfcn.h>
# include "IGraph.hpp"

namespace Arcade
{
  template <class T>
  class DLLoader
  {
    public:
      /* Canonical Functions */
      DLLoader(const std::string &);
      virtual ~DLLoader();
      DLLoader(const DLLoader<T> &);
      DLLoader<T>	&operator=(const DLLoader<T> &);

      /* Member functions */
      T*	getInstance(const std::string &);
    private:
      T*			_instance;
      void*			_handler;
  };
}

#endif		/* !_CPP_ARCADE_DLLOADER_HPP_ */
