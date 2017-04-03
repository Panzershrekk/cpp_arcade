//
// Created by huguet_t on 31/03/17.
//

#include "include/mainMenu.hpp"

menu::menu()
{
  boolean = 0;
  pos = 0;
  _games[0] = "Pacman";
  _games[1] = "Snake";
  _libs[0] = "ncurses";
  _libs[1] = "SFML";
  _libs[2] = "Open Gl";
  std::cout << "menu created" << std::endl;
}

menu::~menu()
{
  std::cout << "menu delete" << std::endl;
}

int	mov_pos(int max, int pos, int ch)
{
  if (ch == KEY_DOWN)
  {
    pos++;
    if (pos == max)
      pos = 0;
  }
  if (ch == KEY_UP)
  {
    pos--;
    if (pos < 0)
      pos = max;
  }
  return pos;
}

void		menu::Game()
{
  int	posGame;
  int	posLibs;

  initscr();
  newterm(NULL, stdin, stdin);
  keypad(stdscr, TRUE);
  noecho();
  curs_set(0);
  pos = 0;
  while(ch != 'q' && ch != 'Q')
  {
    Animation();
    noecho();
    ch = getch();
    if (boolean == 0)
      pos = mov_pos(2, pos, ch);
    else
      pos = mov_pos(3, pos, ch);
    if (ch == '\n')
    {
      if (boolean == 0)
	posGame = pos;
      else if (boolean == 1)
	posLibs = pos;
      boolean++;
      if (boolean == 2)
      {
	endwin();
	std::cout << "exec game " << _games[posGame] << std::endl;
	std::cout << "exec libs " << _libs[posLibs] << std::endl;
	exit(EXIT_SUCCESS);
      }
    }
  }
}

void menu::SetSprite(int x, int y, game::IGame *entity)
{
  (void)x;
  (void)y;
  (void)entity;
}

void menu::UnsetSprite(int x, int y, game::IGame *entity)
{
  (void)x;
  (void)y;
  (void)entity;
}

void menu::Animation()
{
  int		i;

  i = 0;
  while (i < 3)
  {
    if (boolean == 0)
    {
      if (i == pos)
	attron(A_UNDERLINE);
      mvprintw(i, 0, _games[i].c_str());
      attroff(A_UNDERLINE);
      mvprintw(i, 60, _libs[i].c_str());
      i++;
      refresh();
    }
    else
    {
      mvprintw(i, 0, _games[i].c_str());
      if (i == pos)
	attron(A_UNDERLINE);
      mvprintw(i, 60, _libs[i].c_str());
      attroff(A_UNDERLINE);
      i++;
      refresh();
    }
  }
}

void menu::createMap()
{
}

extern "C" void		do_menu()
{
  menu	test;

  test.Game();
}