//
// gameMapSfmlSnake.cpp for snake in /home/antoine/Bureau/Epi/Arcade/cpp_arcade/games/snake/game
//
// Made by antoine
// Login   <antoine@epitech.net>
//
// Started on  Thu Apr  6 22:43:08 2017 antoine
// Last update Sat Apr  8 11:36:56 2017 antoine
//

#include <fstream>
#include <unistd.h>
#include "gameMapSfmlSnake.hpp"
#include <string>

gameMapSfmlSnake::gameMapSfmlSnake()
{
  char c;
  unsigned int i = 0;
  unsigned int j = 0;

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
    _witdh = j - 1;
    if (c == '\n')  {
      _height++;
      i++;
      j = 0;
    }
  }
  fin.close();
  _oldSPrite = 1;
  _window = new sf::RenderWindow(sf::VideoMode(_witdh* 32, i * 32), "Snake");

  _textureMap[0] = new sf::Texture;
  _textureMap[0]->loadFromFile("./games/snake/sprite/block.png", sf::IntRect(0, 0, 32, 32));
  _textureMap[1] = new sf::Texture;
  _textureMap[1]->loadFromFile("./games/snake/sprite/head.png", sf::IntRect(0, 0, 32, 32));
  _textureMap[2] = new sf::Texture;
  _textureMap[2]->loadFromFile("./games/snake/sprite/body.png", sf::IntRect(0, 0, 32, 32));
  _textureMap[3] = new sf::Texture;
  _textureMap[3]->loadFromFile("./games/snake/sprite/apple.png", sf::IntRect(0, 0, 32, 32));
  _textureMap[4] = new sf::Texture;
  _textureMap[4]->loadFromFile("./games/snake/sprite/ground.png", sf::IntRect(0, 0, 32, 32));
}

gameMapSfmlSnake::~gameMapSfmlSnake()
{

}

gameMapSfmlSnake::gameMapSfmlSnake(gameMapSfmlSnake const & other)
{
  _height = other._height;
  _witdh = other._witdh;
  _oldSPrite = other._oldSPrite;
  _snakSprite = other._snakSprite;
  _window = other._window;
  _spriteMap = other._spriteMap;
  _textureMap = other._textureMap;
  _gamemap = other._gamemap;
}

gameMapSfmlSnake& gameMapSfmlSnake::operator=(gameMapSfmlSnake const & other)
{
  _height = other._height;
  _witdh = other._witdh;
  _oldSPrite = other._oldSPrite;
  _snakSprite = other._snakSprite;
  _window = other._window;
  _spriteMap = other._spriteMap;
  _textureMap = other._textureMap;
  _gamemap = other._gamemap;
  return *this;
}

void gameMapSfmlSnake::resetMap()
{
  int i = 0;
  int j = 0;
  while (i != _height)
  {
    while (j != _witdh)
      {
        if (_gamemap[i][j] == 3)
          _gamemap[i][j] = 0;
        if (_gamemap[i][j] == 2)
	  _gamemap[i][j] = 0;
        j++;
      }
    j = 0;
    i++;
  }
}

void gameMapSfmlSnake::createMap()
{
  int i = 0;
  int j = 0;
  while (i != _height)
  {
    while (j != _witdh)
      {
        if (_gamemap[i][j] == TabTypeSnake::WALLE)
          _window->draw(_spriteMap[i][j]);
        else if (_gamemap[i][j] == TabTypeSnake::SNAK)
          _window->draw(_spriteMap[i][j]);
        else if (_gamemap[i][j] == TabTypeSnake::APPLE)
          _window->draw(_spriteMap[i][j]);
        else
        _window->draw(_spriteMap[i][j]);
        j++;
      }
    j = 0;
    i++;
  }
}

void gameMapSfmlSnake::InitSprite()
{
  int i = 0;
  int j = 0;
  while (i != _height)
  {
    while (j != _witdh)
      {
        if (_gamemap[i][j] == TabTypeSnake::WALLE)
          {
            sf::Sprite _pacSprite;
            _pacSprite.setTexture(*_textureMap[0]);
            _pacSprite.setPosition(j * 32, i * 32);
            _spriteMap[i][j] = _pacSprite;
          }
        else if (_gamemap[i][j] == TabTypeSnake::SNAK)
        {
          sf::Sprite _pacSprite;
          _pacSprite.setTexture(*_textureMap[1]);
          _pacSprite.setPosition(j * 32, i * 32);
          _spriteMap[i][j] = _pacSprite;
	}
        else if (_gamemap[i][j] == TabTypeSnake::APPLE)
        {
          sf::Sprite _pacSprite;
          _pacSprite.setTexture(*_textureMap[3]);
          _pacSprite.setPosition(j * 32, i * 32);
          _spriteMap[i][j] = _pacSprite;
	}
        else
          {
            sf::Sprite _pacSprite;
            _pacSprite.setTexture(*_textureMap[4]);
            _pacSprite.setPosition(j * 32, i * 32);
            _spriteMap[i][j] = _pacSprite;
          }
        j++;
      }
    j = 0;
    i++;
  }
}

  void gameMapSfmlSnake::Game()
{
  // int   t = 0;
  // int   prevX = 0;
  // int   prevY = 0;
  int   win = 1;
  Snake *snake = new Snake();
  //createMap();
  int prevX;
  int prevY;
  InitSprite();

  while (_window->isOpen() && win != 0)
  {
    sf::Event event;
    while (_window->pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
      _window->close();

    }
    _window->clear();
    prevX = snake->getX();
    prevY = snake->getY();
    // resetMap();
    snake->movePlayer(_gamemap);
    snake->setPosSnake(movePosSnake(prevX, prevY, snake->getPosSnake(), snake));
    if (snake->isAlive() == false)
      {
	resetMap();
	snake->setLive(true);
      }
    InitSprite();
    createMap();
    _window->display();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
      snake->setDirection(Game::Direction::DOWN);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
      snake->setDirection(Game::Direction::UP);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
      snake->setDirection(Game::Direction::RIGHT);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
      snake->setDirection(Game::Direction::LEFT);
    genApple();
    usleep(100000);
 }
  delete snake;
}

void gameMapSfmlSnake::genApple()
{
  static int i = 0;
  int   tmpy, tmpx;

  if ((i % 20) == 0)
    {
      tmpy = rand() % _height;
      tmpx = rand() % _witdh;
      while ((_gamemap[tmpy][tmpx] == TabTypeSnake::WALLE) || (_gamemap[tmpy][tmpx] == 3))
        {
          tmpy = rand() % _height;
          tmpx = rand() % _witdh;
        }
      _gamemap[tmpy][tmpx] = 2;
    }
  i++;
}


void gameMapSfmlSnake::SetSprite(int x, int y, Game::IGame *entity)
{
 //  if (entity->getType() == 0)
//     _gamemap[y][x] = TabType::PACMAN;
//   else
//   {
//     if (entity->getType() == 1)
//       _gamemap[y][x] = TabType::BLINKY;
//     if (entity->getType() == 2)
//       _gamemap[y][x] = TabType::PINKY;
//     if (entity->getType() == 3)
//       _gamemap[y][x] = TabType::INKY;
//     if (entity->getType() == 4)
//       _gamemap[y][x] = TabType::CLYDE;
//   }
  x++;
  y++;
  (void) entity;
}

std::vector<Position> gameMapSfmlSnake::movePosSnake(int x, int y, std::vector<Position> tmp, Snake *snake)
{
  Position pos;
  Position first;
  unsigned int  i = tmp.size() - 1;
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


void gameMapSfmlSnake::UnsetSprite(int x, int y, Game::IGame *entity)
{
  // if (entity->getType() == 0 && (x != entity->getX() || y != entity->getY()))
  //   _gamemap[y][x] = _oldSPrite;
  // else if (entity->getType() == 1 && (_blinkyCurr != 8 && _blinkyCurr != 9 && _blinkyCurr != 10))
  //   _gamemap[y][x] = _blinkyCurr;
  // else if (entity->getType() == 2 && (_pinkyCurr != 6 && _pinkyCurr != 9 && _pinkyCurr != 10))
  //   _gamemap[y][x] = _pinkyCurr;
  // else if (entity->getType() == 3 && (_inkyCurr != 6 && _inkyCurr != 8 && _inkyCurr != 10))
  //   _gamemap[y][x] = _inkyCurr;
  // else if (entity->getType() == 4 && (_clydeCurr != 6 && _clydeCurr != 8 && _clydeCurr != 9))
  //   _gamemap[y][x] = _clydeCurr;
  x++;
  y++;
  (void) entity;
}

void gameMapSfmlSnake::Animation()
{
/*  int i = 0;
  int j = 0;
  while (i != _height)
  {
    while (j != _witdh)
      {
        delete &_spriteMap[i][j];
        j++;
      }
    j = 0;
    i++;
  }*/
  //delete &_spriteMap[1][1];
}


std::pair<std::string, std::string>     gameMapSfmlSnake::startMenu(const std::vector<std::string> & x, const std::vector<std::string> & y)
{
  (void) x;
  (void) y;
  std::pair<std::string, std::string> menu;
  return menu;
}

void gameMapSfmlSnake::DumpMap()
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


void gameMapSfmlSnake::displayMap(int ** l)
{
  (void) l;
}

void gameMapSfmlSnake::displayMap(int **i, int j, int k, int l)
{
  (void)i;
  (void)k;
  (void)j;
  (void)l;
}

void gameMapSfmlSnake::drawMap(int i, int j, char k)
{
  (void)i;
  (void)k;
  (void)j;
}

void gameMapSfmlSnake::drawPlayer(std::vector<Game::IGame*> i, char j)
{
  (void)i;
  (void)j;
}

void gameMapSfmlSnake::drawScore(int i, int j)
{
  (void)i;
  (void)j;
}

void gameMapSfmlSnake::drawFood(int i, int j, char k)
{
  (void)i;
  (void)k;
  (void)j;
}

void gameMapSfmlSnake::drawLoose(void)
{

}

int  gameMapSfmlSnake::recoverKey(void)
{
  return (0);
}

bool gameMapSfmlSnake::checkSizeWindow(int x, int y)
{
  (void)x;
  (void)y;
  return (true);
}
