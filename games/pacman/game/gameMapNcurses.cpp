/*
** gameMapNcurses.cpp for cpp_arcade in /home/fossae_t/rendu2/cpp_arcade/games/gameman
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Thu Mar 09 17:02:17 2017 Thomas Fossaert
** Last update Wed Apr 05 15:09:42 2017 Thomas Fossaert
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
      if (c == 'B')
      {
        _gamemap[i][j] = TabType::BLINKY;
        _blinky = new Blinky(j, i);
      }
      if (c == 'P')
      {
        _gamemap[i][j] = TabType::PINKY;
        _pinky = new Pinky(j, i);
      }
      if (c == 'I')
      {
        _gamemap[i][j] = TabType::INKY;
        _inky = new Inky(j ,i);
      }
      if (c == 'Y')
      {
        _gamemap[i][j] = TabType::CLYDE;
        _clyde = new Clyde(j, i);
      }
      if (c == 'C')
      {
        _gamemap[i][j] = TabType::PACMAN;
        _pacman = new Pacman(j, i);
      }
    }
    j++;
    _witdh = j;
    if (c == '\n')  {
      _height++;
      i++;
      j = 0;
    }
  }
  fin.close();
  _oldSPrite = 1;
  _blinkyCurr = 1;
  _pinkyCurr = 1;
  _inkyCurr = 1;
  _clydeCurr = 1;

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
          {
            attron(COLOR_PAIR(1));
            mvprintw(i, j, "|");
          }
        else if (_gamemap[i][j] == TabType::WALKABLE)
          mvprintw(i, j, " ");
        else if (_gamemap[i][j] == TabType::GATE)
          {
            attron(COLOR_PAIR(3));
            mvprintw(i, j, "_");
          }
        else if (_gamemap[i][j] == TabType::PACGUM)
          {
            attron(COLOR_PAIR(2));
            mvprintw(i, j, ".");
          }
        else if (_gamemap[i][j] == TabType::SPACGUM)
          {
            attron(COLOR_PAIR(2));
            mvprintw(i, j, "*");
          }
        else if (_gamemap[i][j] == TabType::BLINKY)
          {
            attron(COLOR_PAIR(3));
            mvprintw(i, j, "B");
          }
        else if (_gamemap[i][j] == TabType::PACMAN)
          {
            attron(COLOR_PAIR(2));
            mvprintw(i, j, "C");
          }
          else if (_gamemap[i][j] == TabType::PINKY)
            {
              attron(COLOR_PAIR(4));
              mvprintw(i, j, "P");
            }
          else if (_gamemap[i][j] == TabType::INKY)
            {
              attron(COLOR_PAIR(5));
              mvprintw(i, j, "I");
            }
          else if (_gamemap[i][j] == TabType::CLYDE)
            {
              attron(COLOR_PAIR(6));
              mvprintw(i, j, "Y");
            }
        else
          mvprintw(i, j, " ");
        j++;
        attroff(COLOR_PAIR(1));
        attroff(COLOR_PAIR(2));
        attroff(COLOR_PAIR(3));
        attroff(COLOR_PAIR(4));
        attroff(COLOR_PAIR(5));
        attroff(COLOR_PAIR(6));
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
  int   t = 0;
  int   prevX = 0;
  int   prevY = 0;
  int   win = 1;

  (void)row;
  initscr();
  nodelay(stdscr, TRUE);
  keypad(stdscr, TRUE);
  noecho();
  curs_set(0);
  timeout(500);
  createMap();
  start_color();
  init_color(COLOR_GREEN, 1000, 500, 0);
  init_pair(1, COLOR_BLUE, COLOR_BLUE);
  init_pair(2, COLOR_YELLOW, COLOR_BLACK);
  init_pair(3, COLOR_RED, COLOR_BLACK);
  init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(5, COLOR_CYAN, COLOR_BLACK);
  init_pair(6, COLOR_GREEN, COLOR_BLACK);

  while ((ch != 'q' && ch != 'Q') && (_pacman->isAlive() == true && win != 0))
  {
    noecho();
    getmaxyx(stdscr,row,col);

    int i = 0;
    int j = 0;
    while (i != _height)
    {
      while (j != _witdh)
      {
        if (_gamemap[i][j] == 4)
          win++;
        j++;
      }
      j = 0;
      i++;
    }
    if (win > 1)
      win = 1;
    else
      win = 0;

    createMap();

    if (_gamemap[_pacman->getY()][_pacman->getX()] == TabType::BLINKY
        || _gamemap[_pacman->getY()][_pacman->getX()] == TabType::PINKY
        || _gamemap[_pacman->getY()][_pacman->getX()] == TabType::INKY
        || _gamemap[_pacman->getY()][_pacman->getX()] == TabType::CLYDE)
      _pacman->setLive(false);

    ch = getch();
    if (ch == KEY_UP)
      _pacman->setDirection(game::Direction::UP);
    if (ch == KEY_DOWN)
      _pacman->setDirection(game::Direction::DOWN);
    if (ch == KEY_LEFT)
      _pacman->setDirection(game::Direction::LEFT);
    if (ch == KEY_RIGHT)
      _pacman->setDirection(game::Direction::RIGHT);

    _oldSPrite = 1;
    prevX = _pacman->getX();
    prevY = _pacman->getY();
    _pacman->move(_gamemap);
    SetSprite(_pacman->getX(), _pacman->getY(), _pacman);
    UnsetSprite(prevX, prevY, _pacman);

    prevX = _blinky->getX();
    prevY = _blinky->getY();
    UnsetSprite(prevX, prevY, _blinky);
    _blinky->move(_gamemap);
    _blinkyCurr = _gamemap[_blinky->getY()][_blinky->getX()];
    SetSprite(_blinky->getX(), _blinky->getY(), _blinky);

    if (t > 10)
    {
      prevX = _pinky->getX();
      prevY = _pinky->getY();
      UnsetSprite(prevX, prevY, _pinky);
      _pinky->move(_gamemap);
      _pinkyCurr = _gamemap[_pinky->getY()][_pinky->getX()];
      SetSprite(_pinky->getX(), _pinky->getY(), _pinky);
    }

    if (t > 20)
    {
      prevX = _inky->getX();
      prevY = _inky->getY();
      UnsetSprite(prevX, prevY, _inky);
      _inky->move(_gamemap);
      _inkyCurr = _gamemap[_inky->getY()][_inky->getX()];
      SetSprite(_inky->getX(), _inky->getY(), _inky);
    }

    if (t > 30)
    {
      prevX = _clyde->getX();
      prevY = _clyde->getY();
      UnsetSprite(prevX, prevY, _clyde);
      _clyde->move(_gamemap);
      _clydeCurr = _gamemap[_clyde->getY()][_clyde->getX()];
      SetSprite(_clyde->getX(), _clyde->getY(), _clyde);
    }
    t++;
  }
  getch();
  endwin();
}

void gameMapNcurses::SetSprite(int x, int y, game::IGame *entity)
{
  if (entity->getType() == 0)
    _gamemap[y][x] = TabType::PACMAN;
  else
  {
    if (entity->getType() == 1)
      _gamemap[y][x] = TabType::BLINKY;
    if (entity->getType() == 2)
      _gamemap[y][x] = TabType::PINKY;
    if (entity->getType() == 3)
      _gamemap[y][x] = TabType::INKY;
    if (entity->getType() == 4)
      _gamemap[y][x] = TabType::CLYDE;
  }
}

void gameMapNcurses::UnsetSprite(int x, int y, game::IGame *entity)
{
  if (entity->getType() == 0 && (x != entity->getX() || y != entity->getY()))
    _gamemap[y][x] = _oldSPrite;
  else if (entity->getType() == 1 && (_blinkyCurr != 8 && _blinkyCurr != 9 && _blinkyCurr != 10))
    _gamemap[y][x] = _blinkyCurr;
  else if (entity->getType() == 2 && (_pinkyCurr != 6 && _pinkyCurr != 9 && _pinkyCurr != 10))
    _gamemap[y][x] = _pinkyCurr;
  else if (entity->getType() == 3 && (_inkyCurr != 6 && _inkyCurr != 8 && _inkyCurr != 10))
    _gamemap[y][x] = _inkyCurr;
  else if (entity->getType() == 4 && (_clydeCurr != 6 && _clydeCurr != 8 && _clydeCurr != 9))
    _gamemap[y][x] = _clydeCurr;
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
