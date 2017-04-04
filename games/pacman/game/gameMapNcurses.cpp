/*
** gameMapNcurses.cpp for cpp_arcade in /home/fossae_t/rendu2/cpp_arcade/games/gameman
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Thu Mar 09 17:02:17 2017 Thomas Fossaert
** Last update Tue Apr 04 13:07:28 2017 Thomas Fossaert
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
  _blinkyCurr = 1;
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
        else if (_gamemap[i][j] == TabType::GHOST)
          {
            attron(COLOR_PAIR(3));
            mvprintw(i, j, "M");
          }
        else if (_gamemap[i][j] == TabType::PACMAN)
          {
            attron(COLOR_PAIR(2));
            mvprintw(i, j, "C");
          }
        else
          mvprintw(i, j, " ");
        j++;
        attroff(COLOR_PAIR(1));
        attroff(COLOR_PAIR(2));
        attroff(COLOR_PAIR(3));
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

  game::IGame *pacman = new Pacman();
  game::IGame *blinky = new Blinky();
  game::IGame *pinky = new Pinky();
  game::IGame *inky = new Inky();
  game::IGame *clyde = new Clyde();


  (void)row;
  initscr();
  nodelay(stdscr, TRUE);
  keypad(stdscr, TRUE);
  noecho();
  curs_set(0);
  timeout(500);
  createMap();
  start_color();
  init_pair(1, COLOR_BLUE, COLOR_BLUE);
  init_pair(2, COLOR_YELLOW, COLOR_BLACK);
  init_pair(3, COLOR_RED, COLOR_BLACK);
  while ((ch != 'q' && ch != 'Q') && pacman->isAlive() == true)
  {
    noecho();
    getmaxyx(stdscr,row,col);

    createMap();

    if (_gamemap[pacman->getY()][pacman->getX()] == TabType::GHOST)
      pacman->setLive(false);
      
    ch = getch();
    if (ch == KEY_UP)
      pacman->setDirection(game::Direction::UP);
    if (ch == KEY_DOWN)
      pacman->setDirection(game::Direction::DOWN);
    if (ch == KEY_LEFT)
      pacman->setDirection(game::Direction::LEFT);
    if (ch == KEY_RIGHT)
      pacman->setDirection(game::Direction::RIGHT);

    _oldSPrite = 1;
    prevX = pacman->getX();
    prevY = pacman->getY();
    pacman->move(_gamemap);
    SetSprite(pacman->getX(), pacman->getY(), pacman);
    UnsetSprite(prevX, prevY, pacman);

    prevX = blinky->getX();
    prevY = blinky->getY();
    UnsetSprite(prevX, prevY, blinky);
    blinky->move(_gamemap);
    _blinkyCurr = _gamemap[blinky->getY()][blinky->getX()];
    SetSprite(blinky->getX(), blinky->getY(), blinky);

    if (t > 10)
    {
      prevX = pinky->getX();
      prevY = pinky->getY();
      UnsetSprite(prevX, prevY, pinky);
      pinky->move(_gamemap);
      _pinkyCurr = _gamemap[pinky->getY()][pinky->getX()];
      SetSprite(pinky->getX(), pinky->getY(), pinky);
    }

    if (t > 20)
    {
      prevX = inky->getX();
      prevY = inky->getY();
      UnsetSprite(prevX, prevY, inky);
      inky->move(_gamemap);
      _inkyCurr = _gamemap[inky->getY()][inky->getX()];
      SetSprite(inky->getX(), inky->getY(), inky);
    }

    if (t > 30)
    {
      prevX = clyde->getX();
      prevY = clyde->getY();
      UnsetSprite(prevX, prevY, clyde);
      clyde->move(_gamemap);
      _clydeCurr = _gamemap[clyde->getY()][clyde->getX()];
      SetSprite(clyde->getX(), clyde->getY(), clyde);
    }

    t++;
  }
  getch();
  endwin();
}

void gameMapNcurses::SetSprite(int x, int y, game::IGame *entity)
{
  if (entity->getType() == 0 )
    _gamemap[y][x] = TabType::PACMAN;
  else
  {
    _gamemap[y][x] = TabType::GHOST;
  }
}

void gameMapNcurses::UnsetSprite(int x, int y, game::IGame *entity)
{
  if (entity->getType() == 0 && (x != entity->getX() || y != entity->getY()))
    _gamemap[y][x] = _oldSPrite;
  else if (entity->getType() == 1)
    _gamemap[y][x] = _blinkyCurr;
  else if (entity->getType() == 2)
    _gamemap[y][x] = _pinkyCurr;
  else if (entity->getType() == 3)
    _gamemap[y][x] = _inkyCurr;
  else if (entity->getType() == 4)
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
