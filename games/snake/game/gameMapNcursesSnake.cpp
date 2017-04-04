//
// gameMapNcurses.cpp for game in /home/antoine/Bureau/Epi/Arcade/cpp_arcade/games/snake/game
// 
// Made by antoine
// Login   <antoine@epitech.net>
// 
// Started on  Mon Apr  3 11:33:02 2017 antoine
// Last update Tue Apr  4 20:20:52 2017 antoine
//

#include <fstream>
#include <unistd.h>
#include "gameMapNcursesSnake.hpp"
#include "Snake.hpp"
#include <vector>

gameMapNcursesSnake::gameMapNcursesSnake()
{
  char c;
  unsigned int i = 0;
  unsigned int j = 0;
  unsigned int	tmpJ;

  std::ifstream fin("./games/snake/sprite/NcurseMap.txt");
  if(!fin) {
    std::cout << "Cannot open file for input.\n";
  }
  while (fin.get(c))
  {
    if (c != '\n')  {
      if (c == '|')
        _gamemap[i][j] = TabTypeSnake::WALLE;
      if (c == ' ')
	_gamemap[i][j] = TabTypeSnake::CANWALK;
    }
    j++;
    if (c == '\n')  {
      _height++;
      i++;
      tmpJ = j;
      j = 0;
    }
  }
  fin.close();
  _witdh = tmpJ;
}

gameMapNcursesSnake::~gameMapNcursesSnake()
{
}

gameMapNcursesSnake::gameMapNcursesSnake(gameMapNcursesSnake const & other)
{
  (void) other;
}

gameMapNcursesSnake& gameMapNcursesSnake::operator=(gameMapNcursesSnake const & other)
{
  (void) other;
  return *this;
}

void gameMapNcursesSnake::createMap()
{
  int i = 0;
  int j = 0;
  start_color();
  while (i != _height)
  {
    while (j != _witdh)
      {
        if (_gamemap[i][j] == TabTypeSnake::WALLE)
	  {
	    init_pair(1, COLOR_RED, COLOR_WHITE);
 	    attron(COLOR_PAIR(1));
	    mvprintw(i, j, " ");
	    attroff(COLOR_PAIR(1));
	  }
        else if (_gamemap[i][j] == TabTypeSnake::CANWALK)
	  {
	    
	    mvprintw(i, j, " ");
	  }
        else if (_gamemap[i][j] == TabTypeSnake::APPLE)
	  {
	    init_pair(3, COLOR_RED, COLOR_RED);
	     attron(COLOR_PAIR(3));
	    mvprintw(i, j, " ");
	    attroff(COLOR_PAIR(3));
	  }
	else if (_gamemap[i][j] == TabTypeSnake::SNAK)
	  {
	    init_pair(2, COLOR_RED, COLOR_YELLOW);
	     attron(COLOR_PAIR(2));
	    mvprintw(i, j, " ");
	    attroff(COLOR_PAIR(2));
	  }
        else
          mvprintw(i, j, " ");
        j++;
      }
    j = 0;
    i++;
  }
}

void gameMapNcursesSnake::Game()
{
  int   ch;
  int   row;
  int   col;
  int   t = 0;
  int   prevX = 0;
  int   prevY = 0;
  Snake *snake = new Snake();

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

    createMap();
    mvprintw(_height + 1, 0, std::to_string(snake->getScore()).c_str());
    ch = getch();
    if (ch == KEY_UP)
      snake->setDirection(game::Direction::UP);
    if (ch == KEY_DOWN)
      snake->setDirection(game::Direction::DOWN);
    if (ch == KEY_LEFT)
      snake->setDirection(game::Direction::LEFT);
    if (ch == KEY_RIGHT)
      snake->setDirection(game::Direction::RIGHT);
    prevX = snake->getX();
    prevY = snake->getY();
    snake->move(_gamemap);
    // _gamemap[prevY][prevX] = 0;
    snake->setPosSnake(movePosSnake(prevX, prevY, snake->getPosSnake(), snake));
    genApple();
    t++;
  }
  getch();
  endwin();
}

std::vector<Position> gameMapNcursesSnake::movePosSnake(int x, int y, std::vector<Position> tmp, Snake *snake)
{
  Position pos;
  Position first;
  unsigned int	i = tmp.size() - 1;
  int j = tmp.size() - 1;
  
  first.x = x;
  first.y = y;
  _gamemap[snake->getY()][snake->getX()] = 3;
   _gamemap[tmp[tmp.size() - 1].y][tmp[tmp.size() - 1].x] = 0;
  while (j >= 0)
    {
      if (i == 0)
	{
	  tmp[0] = first;
	  // if (snake->getNeedGrowth() != 1)
	    _gamemap[tmp[0].y][tmp[0].x] = 3;
	}
      else
	{
	  pos = tmp[i - 1];
	  tmp[i] = pos;
	  _gamemap[tmp[i].y][tmp[i].x] = 3;
	}
      i--;
      j--;
    }
 if (snake->getNeedGrowth() == 1)
    {
      tmp.push_back(tmp[tmp.size() - 1]);
      _gamemap[tmp[tmp.size() - 1].y][tmp[tmp.size() - 1].x] = 3;
      snake->setNeedGrowth(0);
    }
  return (tmp);
}

void gameMapNcursesSnake::genApple()
{
  static int i = 0;
  int	tmpy, tmpx;

  if ((i % 10) == 0)
    {
      tmpy = rand() % _height;
      tmpx = rand() % _witdh;
      while ((_gamemap[tmpy][tmpx] == TabTypeSnake::WALLE))
	{
	  tmpy = rand() % _height;
	  tmpx = rand() % _witdh;	 
	}
      _gamemap[tmpy][tmpx] = 2;
    }
  i++;
}

void gameMapNcursesSnake::SetSprite(int x, int y, game::IGame *entity)
{
  x++;
  y++;
  (void) entity;
}

void gameMapNcursesSnake::UnsetSprite(int x, int y, game::IGame *entity)
{
  x++;
  y++;
  (void) entity;
}

void gameMapNcursesSnake::Animation()
{

}

void gameMapNcursesSnake::DumpMap()
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
