/*
** ArcadeException.hpp for cpp_arcade in /home/fossae_t/rendu2/cpp_arcade/exception/include
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Tue Mar 14 16:47:11 2017 Thomas Fossaert
** Last update Tue Mar 14 16:47:17 2017 Thomas Fossaert
*/

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
