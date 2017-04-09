//
// Created by huguet_t on 31/03/17.
//

#include <dlfcn.h>
#include <unistd.h>
#include "include/mainMenu.hpp"

menu::menu()
{
  boolean = 0;
  pos = 0;
  _games[0] = "pacman";
  _games[1] = "snake";
  _libs[0] = "ncurses";
  _libs[1] = "SFML";
}

menu::~menu()
{
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
      pos = max - 1;
  }
  return pos;
}

void		menu::Game()
{
  int	posGame;
  int	posLibs;
  void		*lib;

  initscr();
  keypad(stdscr, TRUE);
  noecho();
  curs_set(0);
  pos = 0;
  while(ch != 'q' && ch != 'Q')
  {
    clear();
    createMap();
    Animation();
    refresh();
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
	clear();
	endwin();

	std::string load_lib = ("./lib/lib_arcade_" + _games[posGame] + ".so");
	if ((lib = dlopen(load_lib.c_str(), RTLD_LAZY)) == NULL)
	  {
	    std::cout << "error: failed to load the lib" << load_lib << std::endl;
	    exit(EXIT_FAILURE);
	  }

	typedef void	(*func_ptr)();
	load_lib = _games[posGame] + "_" + _libs[posLibs];
	func_ptr func = (func_ptr)dlsym(lib,load_lib.c_str());

	if (!func)
	{
	  std::cout << "error: failed to load the function" << load_lib << std::endl;
	  exit(EXIT_FAILURE);
	}
	func();
	dlclose(lib);
	return;
      }
    }
  }
  endwin();
}

void menu::SetSprite(int x, int y, Game::IGame *entity)
{
  (void)x;
  (void)y;
  (void)entity;
}

void menu::UnsetSprite(int x, int y, Game::IGame *entity)
{
  (void)x;
  (void)y;
  (void)entity;
}

void menu::Animation()
{
  int		i;
  int		j;
  unsigned long		y;
  unsigned long		x;

  i = 0;
  j = 0;
  getmaxyx(stdscr, y, x);
  while (i < 3)
  {
    if (boolean == 0)
    {
      if (i == pos)
	attron(A_UNDERLINE);
      mvprintw(static_cast<int>((y / 2) + i + j),static_cast<int>((x / 2) - (6 / 2)), _games[i].c_str());
      attroff(A_UNDERLINE);
      i++;
      j++;
      refresh();
    }
    else
    {
      if (i == pos)
	attron(A_UNDERLINE);
      mvprintw(static_cast<int>((y / 2) + i + j),static_cast<int>((x / 2) - (8 / 2)), _libs[i].c_str());
      attroff(A_UNDERLINE);
      i++;
      j++;
      refresh();
    }
  }
}

void menu::createMap()
{
  int x;
  int y;
  int i;

  start_color();
  init_pair(1, COLOR_WHITE, COLOR_WHITE);
  init_pair(2, COLOR_BLACK, COLOR_WHITE);
  init_pair(3, COLOR_GREEN, COLOR_BLACK);
  init_pair(4, COLOR_YELLOW, COLOR_BLACK);

  i = 0;
  getmaxyx(stdscr, y, x);
  attron(COLOR_PAIR(4));
  mvprintw(((y / 2) - 20), 0, "================================================.\n"
    "     .-.   .-.     .--.                         |\n"
    "    | OO| | OO|   / _.-' .-.   .-.  .-.   .''.  |\n"
    "    |   | |   |   \\  '-. '-'   '-'  '-'   '..'  |\n"
    "    '^^^' '^^^'    '--'                         |\n"
    "===============.  .-.  .================.  .-.  |\n"
    "               | |   | |                |  '-'  |\n"
    "               | |   | |                |       |\n"
    "               | ':-:' |                |  .-.  |\n"
    "l42            |  '-'  |                |  '-'  |\n"
    "==============='       '================'       |");
  attroff(COLOR_PAIR(4));

  attron(COLOR_PAIR(3));
  mvprintw(((y / 2) - 20),x - 45,"   _________         _________\n");
  mvprintw(((y / 2) - 19),x - 45,"  /         \\       /         \\   \n");
  mvprintw(((y / 2) - 18),x - 45," /  /~~~~~\\  \\     /  /~~~~~\\  \\  \n");
  mvprintw(((y / 2) - 17),x - 45," |  |     |  |     |  |     |  |\n");
  mvprintw(((y / 2) - 16),x - 45," |  |     |  |     |  |     |  |\n");
  mvprintw(((y / 2) - 15),x - 45," |  |     |  |     |  |     |  |         /\n");
  mvprintw(((y / 2) - 14),x - 45," |  |     |  |     |  |     |  |       //\n");
  mvprintw(((y / 2) - 13),x - 45,"(o  o)    \\  \\_____/  /     \\  \\_____/ /\n");
  mvprintw(((y / 2) - 12),x - 45," \\__/      \\         /       \\        /\n");
  mvprintw(((y / 2) - 11),x - 45,"  |         ~~~~~~~~~         ~~~~~~~~\n");
  mvprintw(((y / 2) - 10),x - 45,"  ^");
  attroff(COLOR_PAIR(3));

  mvprintw(0, (x / 2 - 25), "   _______  _______  _______  _______  ______   _______\n");
  mvprintw(1, (x / 2 - 25),"  (  ___  )(  ____ )(  ____ \\(  ___  )(  __  \\ (  ____ \\\n");
  mvprintw(2, (x / 2 - 25),"  | (   ) || (    )|| (    \\/| (   ) || (  \\  )| (    \\/\n");
  mvprintw(3, (x / 2 - 25),"  | (___) || (____)|| |      | (___) || |   ) || (__\n");
  mvprintw(4, (x / 2 - 25),"  |  ___  ||     __)| |      |  ___  || |   | ||  __)\n");
  mvprintw(5, (x / 2 - 25),"  | (   ) || (\\ (   | |      | (   ) || |   ) || (\n");
  mvprintw(6, (x / 2 - 25),"  | )   ( || ) \\ \\__| (____/\\| )   ( || (__/  )| (____/\\\n");
  mvprintw(7, (x / 2 - 25),"  |/     \\||/   \\__/(_______/|/     \\|(______/ (_______/ \n");
  while(i < 7)
  {
    attron(COLOR_PAIR(1));
    mvprintw(static_cast<int>((y / 2) + i - 1),
	     static_cast<int>((x / 2) - (8 / 2) - 10), "|");
    i++;
  }
  i = 0;
  while(i < 29)
  {
    attron(COLOR_PAIR(1));
    mvprintw(static_cast<int>((y / 2) - 1),
	     static_cast<int>((x / 2) - (8 / 2) - 10 + i), "|");
    i++;
  }
  i = 0;
  while(i < 7)
  {
    attron(COLOR_PAIR(1));
    mvprintw(static_cast<int>((y / 2) + i - 1),
	     static_cast<int>((x / 2) + (8 / 2) + 10), "|");
    i++;
  }
  i = 0;
  while(i < 29)
  {
    attron(COLOR_PAIR(1));
    mvprintw(static_cast<int>((y / 2) + 6),
	     static_cast<int>((x / 2) - (8 / 2) - 10 + i), "|");
    i++;
  }
  i = 0;
  if (boolean == 0)
  {
      attron(COLOR_PAIR(2));
      mvprintw(static_cast<int>((y / 2) - 1),
	       static_cast<int>((x / 2) - (10 / 2)), "Choose Game");
  }
  else
  {
    attron(COLOR_PAIR(2));
    mvprintw(static_cast<int>((y / 2) - 1),
	     static_cast<int>((x / 2) - (10 / 2)), "Choose Lib");
  }
  attroff(COLOR_PAIR(1));
  attroff(COLOR_PAIR(2));
}

std::pair<std::string, std::string>	menu::startMenu(const std::vector<std::string> & x, const std::vector<std::string> & y)
{
  (void) x;
  (void) y;
  std::pair<std::string, std::string> menu;
  return menu;
}
void menu::displayMap(int ** l)
{
  (void) l;
}

extern "C" void		do_menu()
{
  menu	my_menu;

  my_menu.Game();
}

void menu::displayMap(int **i, int j, int k, int l)
{
  (void)i;
  (void)k;
  (void)j;
  (void)l;
}

void menu::drawMap(int i, int j, char k)
{
  (void)i;
  (void)k;
  (void)j;
}

void menu::drawPlayer(std::vector<Game::IGame*> i, char j)
{
  (void)i;
  (void)j;
}

void menu::drawScore(int i, int j)
{
  (void)i;
  (void)j;
}

void menu::drawFood(int i, int j, char k)
{
  (void)i;
  (void)k;
  (void)j;
}

void menu::drawLoose(void)
{

}

int  menu::recoverKey(void)
{
  return (0);
}

bool menu::checkSizeWindow(int x, int y)
{
  (void)x;
  (void)y;
  return (true);
}
