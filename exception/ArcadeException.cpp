#include "ArcadeException.hpp"

ArcadeException::ArcadeException(std::string msg) throw() : _msg(msg)
{
}

const char *ArcadeException::what() const throw()
{
  return (_msg.c_str());
}
