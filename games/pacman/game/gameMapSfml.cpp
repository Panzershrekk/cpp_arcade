/*
** gameMapSfml.cpp for cpp_arcade in /home/fossae_t/rendu2/cpp_arcade/games/gameman
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Thu Mar 09 17:02:17 2017 Thomas Fossaert
** Last update Wed Apr 05 15:37:39 2017 Thomas Fossaert
*/

#include <fstream>
#include <unistd.h>
#include "gameMapSfml.hpp"

gameMapSfml::gameMapSfml()
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

gameMapSfml::~gameMapSfml()
{
}

gameMapSfml::gameMapSfml(gameMapSfml const & other)
{
  (void) other;
}

gameMapSfml& gameMapSfml::operator=(gameMapSfml const & other)
{
  (void) other;
  return *this;
}

void gameMapSfml::createMap()
{
  /*int i = 0;
  int j = 0;
  while (i != _height)
  {
    while (j != _witdh)
      {
        if (_gamemap[i][j] == TabType::WALL)
          mvprintw(i, j, "|");
          //_window.draw(_spriteMap[0][0]);
        else if (_gamemap[i][j] == TabType::WALKABLE)
          mvprintw(i, j, " ");
        else if (_gamemap[i][j] == TabType::GATE)
          mvprintw(i, j, "_");
        else if (_gamemap[i][j] == TabType::PACGUM)
          mvprintw(i, j, ".");
        else if (_gamemap[i][j] == TabType::SPACGUM)
          mvprintw(i, j, "*");
        else if (_gamemap[i][j] == TabType::BLINKY)
          mvprintw(i, j, "M");
        else if (_gamemap[i][j] == TabType::PACMAN)
          mvprintw(i, j, "C");
        else
          mvprintw(i, j, " ");
        j++;
      }
    j = 0;
    i++;
  }*/
  _window.draw(_pacSprite);
}

void gameMapSfml::Game()
{
  game::IGame *pacman = new Pacman();
  /*game::IGame *blinky = new Blinky();
  game::IGame *pinky = new Pinky();
  game::IGame *inky = new Inky();
  game::IGame *clyde = new Clyde();*/

  sf::RenderWindow _window(sf::VideoMode(1080, 720), "Pacman");
  sf::CircleShape shape(50);

  sf::Texture logo_pacman;
  sf::Texture logo_snake;
  sf::Vector2<int> pos;

  logo_pacman.loadFromFile("./games/pacman/sprite/sp_pacman.png", sf::IntRect(0, 0, 32, 32));

  sf::Sprite _pacSprite;
  _pacSprite.setTexture(logo_pacman);
  _pacSprite.setPosition(15, 270);
  _spriteMap[0][0] = _pacSprite;

  logo_snake.loadFromFile("./games/pacman/sprite/sp_blinky.png", sf::IntRect(0, 0, 32, 32));

  sf::Sprite _snakeSprite;
  _snakeSprite.setTexture(logo_snake);
  _snakeSprite.setPosition(540, 160);

  while (_window.isOpen())
  {
    sf::Event event;
    while (_window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
  _window.close();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
     {
       pacman->setDirection(game::Direction::UP);
       logo_pacman.loadFromFile("./games/pacman/sprite/sp_pacman.png", sf::IntRect(96, 0, 32, 32));
      }
     else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
          pacman->setDirection(game::Direction::RIGHT);
          logo_pacman.loadFromFile("./games/pacman/sprite/sp_pacman.png", sf::IntRect(32, 0, 32, 32));
        }
     else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
          pacman->setDirection(game::Direction::LEFT);
          logo_pacman.loadFromFile("./games/pacman/sprite/sp_pacman.png", sf::IntRect(0, 0, 32, 32));
        }
     else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
          pacman->setDirection(game::Direction::DOWN);
          logo_pacman.loadFromFile("./games/pacman/sprite/sp_pacman.png", sf::IntRect(64, 0, 32, 32));
        }
    _pacSprite.setTexture(logo_pacman);
     pacman->move(_gamemap);
     if (pacman->getDirection() == 0)
      _pacSprite.move(0, -1);
     if (pacman->getDirection() == 1)
      _pacSprite.move(1, 0);
     if (pacman->getDirection() == 2)
       _pacSprite.move(0, 1);
     if (pacman->getDirection() == 3)
       _pacSprite.move(-1, 0);
    _window.clear();
    //createMap();
    //_window.draw(_pacSprite);
    _window.draw(_snakeSprite);
    //_window.draw(_textureMap[0][0]);
    _window.display();
    usleep(3000);
 }
}

void gameMapSfml::SetSprite(int x, int y, game::IGame *entity)
{
  (void) x;
  (void) y;
  (void) entity;
}

void gameMapSfml::UnsetSprite(int x, int y, game::IGame *entity)
{
  (void) x;
  (void) y;
  (void) entity;
}

void gameMapSfml::Animation()
{

}

void gameMapSfml::DumpMap()
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
