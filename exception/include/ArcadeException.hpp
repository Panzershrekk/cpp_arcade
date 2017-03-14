#include <exception>
#include <iostream>

class ArcadeException : public std::exception
{
private:
  std::string _msg;
public:
  ArcadeException(std::string msg) throw();
  virtual const char* what() const throw();
  virtual ~ArcadeException() throw() {};
};
