/*
** gameMapNcurses.cpp for cpp_arcade in /home/fossae_t/rendu2/cpp_arcade/games/gameman
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Thu Mar 09 17:02:17 2017 Thomas Fossaert
** Last update Thu Mar 23 17:31:17 2017 Thomas Fossaert
*/

#include <fstream>
#include <unistd.h>
#include "gameMapNcurses.hpp"

gameMapNcurses::gameMapNcurses()
{
  char c;
  unsigned int i = 0;
  unsigned int j = 0;

  std::ifstream fin("./games/pacman/sprite/NcurseMap.txt");
  if(!fin) {
    std::cout << "Cannot open file for input.\n";
  }
  while (fin.get(c))
  {
    if (c != '\n')  {
      if (c == '|')
        _gamemap[i][j] = TabType::WALL;
      if (c == '*')
        _gamemap[i][j] = TabType::SPACGUM;
      if (c == '.')
        _gamemap[i][j] = TabType::PACGUM;
      if (c == ' ')
        _gamemap[i][j] = TabType::WALKABLE;
      if (c == '_')
        _gamemap[i][j] = TabType::GATE;
      if (c == 'M')
        _gamemap[i][j] = TabType::GHOST;
      if (c == 'C')
      _gamemap[i][j] = TabType::PACMAN;
    }
    j++;
    if (c == '\n')  {
      _height++;
      i++;
      j = 0;
    }
  }
  fin.close();
  _witdh = 28;
}

gameMapNcurses::~gameMapNcurses()
{
}

gameMapNcurses::gameMapNcurses(gameMapNcurses const & other)
{
  (void) other;
}

gameMapNcurses& gameMapNcurses::operator=(gameMapNcurses const & other)
{
  (void) other;
  return *this;
}

void gameMapNcurses::createMap()
{
  int i = 0;
  int j = 0;

  while (i != _height)
  {
    while (j != _witdh)
      {
        if (_gamemap[i][j] == TabType::WALL)
          mvprintw(i, j, "|");
        else if (_gamemap[i][j] == TabType::WALKABLE)
          mvprintw(i, j, " ");
        else if (_gamemap[i][j] == TabType::GATE)
          mvprintw(i, j, "_");
        else if (_gamemap[i][j] == TabType::PACGUM)
          mvprintw(i, j, ".");
        else if (_gamemap[i][j] == TabType::SPACGUM)
          mvprintw(i, j, "*");
        else if (_gamemap[i][j] == TabType::GHOST)
          mvprintw(i, j, "M");
        else if (_gamemap[i][j] == TabType::PACMAN)
          mvprintw(i, j, "C");
        else
          mvprintw(i, j, " ");
        j++;
      }
    j = 0;
    i++;
  }
}

void gameMapNcurses::Game()
{
  int   ch;
  int   row;
  int   col;

  game::IGame *blinky = new Blinky();
  /*game::IGame *pinky = new Pinky();
  game::IGame *inky = new Inky();
  game::IGame *clyde = new Clyde();*/


  (void)row;
  initscr();
  nodelay(stdscr, TRUE);
  keypad(stdscr, TRUE);
  noecho();
  curs_set(0);
  createMap();
  while (ch != 'q' && ch != 'Q')
  {
    noecho();
    clear();
    createMap();
    getmaxyx(stdscr,row,col);
    ch = getch();
    blinky->move(_gamemap);
    //blinky->setY(blinky->getY() - 1);
    SetSprite(blinky->getX(), blinky->getY());
    UnsetSprite(blinky->getX(), blinky->getY() + 1);
    sleep(2);
  }
  getch();
  endwin();
}

void gameMapNcurses::SetSprite(int x, int y)
{
  _gamemap[y][x] = TabType::GHOST;
}

void gameMapNcurses::UnsetSprite(int x, int y)
{
  _gamemap[y][x] = TabType::WALKABLE;
}

void gameMapNcurses::Animation()
{

}

void gameMapNcurses::DumpMap()
{
  int i = 0;
  int j = 0;

  while (i != _height)
  {
    while (j != _witdh)
      {
        std::cout << _gamemap[i][j];
        j++;
      }
    std::cout << '\n';
    j = 0;
    i++;
  }
}
