/*
** gameMapNcurses.cpp for cpp_arcade in /home/fossae_t/rendu2/cpp_arcade/games/gameman
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Thu Mar 09 17:02:17 2017 Thomas Fossaert
** Last update Fri Mar 31 09:23:39 2017 Thomas Fossaert
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
  _oldSPrite = 1;
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
  //int   t = 0;

  game::IGame *pacman = new Pacman();
  game::IGame *blinky = new Blinky();
  game::IGame *pinky = new Pinky();
  /*game::IGame *inky = new Inky();
  game::IGame *clyde = new Clyde();*/


  (void)row;
  initscr();
  nodelay(stdscr, TRUE);
  keypad(stdscr, TRUE);
  noecho();
  curs_set(0);
  timeout(500);
  createMap();
  while (ch != 'q' && ch != 'Q')
  {
    noecho();
    getmaxyx(stdscr,row,col);
    ch = getch();
    if (ch == KEY_UP)
      pacman->setDirection(game::Direction::UP);
    if (ch == KEY_DOWN)
      pacman->setDirection(game::Direction::DOWN);
    if (ch == KEY_LEFT)
      pacman->setDirection(game::Direction::LEFT);
    if (ch == KEY_RIGHT)
      pacman->setDirection(game::Direction::RIGHT);

    pacman->move(_gamemap);
    SetSprite(pacman->getX(), pacman->getY(), pacman);
    createMap();
    UnsetSprite(pacman->getX(), pacman->getY(), pacman);

    blinky->move(_gamemap);
    SetSprite(blinky->getX(), blinky->getY(), blinky);
    createMap();
    UnsetSprite(blinky->getX(), blinky->getY(), blinky);

    pinky->move(_gamemap);
    SetSprite(pinky->getX(), pinky->getY(), pinky);
    createMap();
    UnsetSprite(pinky->getX(), pinky->getY(), pinky);
    //clear();
  }
  getch();
  endwin();
}

void gameMapNcurses::SetSprite(int x, int y, game::IGame *entity)
{
  if (entity->getType() == 0)
  {
    _oldSPrite = 1;
    _gamemap[y][x] = TabType::PACMAN;
  }
  else
  {
    _oldSPrite = _gamemap[y][x];
    _gamemap[y][x] = TabType::GHOST;
  }
}

void gameMapNcurses::UnsetSprite(int x, int y, game::IGame *entity)
{
  /*if (entity->getType() == 0)
  {
    if (entity->getDirection() == 0 && _gamemap[y + 1][x] != TabType::WALL)
      _gamemap[y][x] = _oldSPrite;
    if (entity->getDirection() == 1 && _gamemap[y][x - 1] != TabType::WALL)
      _gamemap[y][x] = _oldSPrite;
    if (entity->getDirection() == 2 && _gamemap[y - 1][x] != TabType::WALL)
      _gamemap[y][x] = _oldSPrite;
    if (entity->getDirection() == 3 && _gamemap[y][x + 1] != TabType::WALL)
      _gamemap[y][x] = _oldSPrite;
  }
  else
  {*/
    if (entity->getDirection() == 0 && _gamemap[y/* + 1*/][x] != TabType::WALL)
      _gamemap[y][x] = _oldSPrite;
    if (entity->getDirection() == 1 && _gamemap[y][x/* - 1*/] != TabType::WALL)
      _gamemap[y][x] = _oldSPrite;
    if (entity->getDirection() == 2 && _gamemap[y/* - 1*/][x] != TabType::WALL)
      _gamemap[y][x] = _oldSPrite;
    if (entity->getDirection() == 3 && _gamemap[y][x/* + 1*/] != TabType::WALL)
      _gamemap[y][x] = _oldSPrite;
    /*}*/
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
