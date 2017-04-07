//
// gameMapSfmlSnake.cpp for snake in /home/antoine/Bureau/Epi/Arcade/cpp_arcade/games/snake/game
// 
// Made by antoine
// Login   <antoine@epitech.net>
// 
// Started on  Thu Apr  6 22:43:08 2017 antoine
// Last update Thu Apr  6 23:05:05 2017 antoine
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
  _window = new sf::RenderWindow(sf::VideoMode(1080, 1080), "Snake");
  while (fin.get(c))
  {
    if (c != '\n')  {
      if (c == '|')
        _gamemap[i][j] = TabTypeSnake::WALLE;
      if (c == ' ')
        _gamemap[i][j] = TabTypeSnake::CANWALK;
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

  _textureMap[0] = new sf::Texture;
  _textureMap[0]->loadFromFile("./games/snake/sprite/block.png", sf::IntRect(0, 0, 32, 32));
  _textureMap[1] = new sf::Texture;
  _textureMap[1]->loadFromFile("./games/snake/sprite/head.png", sf::IntRect(0, 0, 32, 32));
  _textureMap[2] = new sf::Texture;
  _textureMap[2]->loadFromFile("./games/snake/sprite/body.png", sf::IntRect(0, 0, 32, 32));
}

gameMapSfmlSnake::~gameMapSfmlSnake()
{
}

gameMapSfmlSnake::gameMapSfmlSnake(gameMapSfmlSnake const & other)
{
  (void) other;
}

gameMapSfmlSnake& gameMapSfmlSnake::operator=(gameMapSfmlSnake const & other)
{
  (void) other;
  return *this;
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
        else
          {
            sf::Sprite _pacSprite;
            _pacSprite.setTexture(*_textureMap[2]);
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

  //createMap();

  InitSprite();

  while (_window->isOpen() && win != 0)
  {
    sf::Event event;
    while (_window->pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
      _window->close();

    }
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

    _window->clear();
    InitSprite();
    createMap();
    _window->display();

    // if (_gamemap[_pacman->getY()][_pacman->getX()] == TabType::BLINKY
    //     || _gamemap[_pacman->getY()][_pacman->getX()] == TabType::PINKY
    //     || _gamemap[_pacman->getY()][_pacman->getX()] == TabType::INKY
    //     || _gamemap[_pacman->getY()][_pacman->getX()] == TabType::CLYDE)
    //   _pacman->setLive(false);

    // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    //   _pacman->setDirection(Game::Direction::UP);
    // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    //   _pacman->setDirection(Game::Direction::DOWN);
    // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    //   _pacman->setDirection(Game::Direction::LEFT);
    // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    //   _pacman->setDirection(Game::Direction::RIGHT);

    // _oldSPrite = 1;
    // prevX = _pacman->getX();
    // prevY = _pacman->getY();
    // _pacman->movePlayer(_gamemap);

    // if (_gamemap[_pacman->getY()][_pacman->getX()] == 4)
    //   _pacman->setScore(10);
    // _score = _pacman->getScore();

    // SetSprite(_pacman->getX(), _pacman->getY(), _pacman);
    // UnsetSprite(prevX, prevY, _pacman);

    // prevX = _blinky->getX();
    // prevY = _blinky->getY();
    // UnsetSprite(prevX, prevY, _blinky);
    // _blinky->movePlayer(_gamemap);
    // _blinkyCurr = _gamemap[_blinky->getY()][_blinky->getX()];
    // SetSprite(_blinky->getX(), _blinky->getY(), _blinky);

    // if (t > 10)
    // {
    //   prevX = _pinky->getX();
    //   prevY = _pinky->getY();
    //   UnsetSprite(prevX, prevY, _pinky);
    //   _pinky->movePlayer(_gamemap);
    //   _pinkyCurr = _gamemap[_pinky->getY()][_pinky->getX()];
    //   SetSprite(_pinky->getX(), _pinky->getY(), _pinky);
    // }

    // if (t > 20)
    // {
    //   prevX = _inky->getX();
    //   prevY = _inky->getY();
    //   UnsetSprite(prevX, prevY, _inky);
    //   _inky->movePlayer(_gamemap);
    //   _inkyCurr = _gamemap[_inky->getY()][_inky->getX()];
    //   SetSprite(_inky->getX(), _inky->getY(), _inky);
    // }

    // if (t > 30)
    // {
    //   prevX = _clyde->getX();
    //   prevY = _clyde->getY();
    //   UnsetSprite(prevX, prevY, _clyde);
    //   _clyde->movePlayer(_gamemap);
    //   _clydeCurr = _gamemap[_clyde->getY()][_clyde->getX()];
    //   SetSprite(_clyde->getX(), _clyde->getY(), _clyde);
    // }
    // t++;
    // Animation();
    usleep(100000);
 }
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