/*
** gameMapSfml.cpp for cpp_arcade in /home/fossae_t/rendu2/cpp_arcade/games/gameman
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Thu Mar 09 17:02:17 2017 Thomas Fossaert
** Last update Sun Apr 09 12:51:18 2017 Thomas Fossaert
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
  _window = new sf::RenderWindow(sf::VideoMode(1080, 1080), "Pacman");
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
  _score = 0;
  _tempoSprite = 0;

  _textureMap[0] = new sf::Texture;
  _textureMap[0]->loadFromFile("./games/pacman/sprite/mur_marine.png", sf::IntRect(0, 0, 32, 32));
  _textureMap[1] = new sf::Texture;
  _textureMap[1]->loadFromFile("./games/pacman/sprite/gate.png", sf::IntRect(0, 0, 32, 32));
  _textureMap[2] = new sf::Texture;
  _textureMap[2]->loadFromFile("./games/pacman/sprite/pacgum.png", sf::IntRect(0, 0, 32, 32));
  _textureMap[3] = new sf::Texture;
  _textureMap[3]->loadFromFile("./games/pacman/sprite/Spacgum.png", sf::IntRect(0, 0, 32, 32));
  _textureMap[4] = new sf::Texture;
  _textureMap[4]->loadFromFile("./games/pacman/sprite/sp_blinky.png", sf::IntRect(0, 0, 32, 32));
  _textureMap[5] = new sf::Texture;
  _textureMap[5]->loadFromFile("./games/pacman/sprite/sp_pacman.png", sf::IntRect(0, 0, 32, 32));
  _textureMap[6] = new sf::Texture;
  _textureMap[6]->loadFromFile("./games/pacman/sprite/black_square.png", sf::IntRect(0, 0, 32, 32));
  _textureMap[7] = new sf::Texture;
  _textureMap[7]->loadFromFile("./games/pacman/sprite/sp_pinky.png", sf::IntRect(0, 0, 32, 32));
  _textureMap[8] = new sf::Texture;
  _textureMap[8]->loadFromFile("./games/pacman/sprite/sp_inky.png", sf::IntRect(0, 0, 32, 32));
  _textureMap[9] = new sf::Texture;
  _textureMap[9]->loadFromFile("./games/pacman/sprite/sp_clyde.png", sf::IntRect(0, 0, 32, 32));


}

gameMapSfml::~gameMapSfml()
{
  delete _blinky;
  delete _pinky;
  delete _inky;
  delete _clyde;
  delete _window;
  delete _textureMap[9];
  delete _textureMap[8];
  delete _textureMap[7];
  delete _textureMap[6];
  delete _textureMap[5];
  delete _textureMap[4];
  delete _textureMap[3];
  delete _textureMap[2];
  delete _textureMap[1];
  delete _textureMap[0];
  delete _pacSprite;
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
  int i = 0;
  int j = 0;
  while (i != _height)
  {
    while (j != _witdh)
      {
        if (_gamemap[i][j] == TabType::WALL)
          _window->draw(_spriteMap[i][j]);
        else if (_gamemap[i][j] == TabType::WALKABLE)
          _window->draw(_spriteMap[i][j]);
        else if (_gamemap[i][j] == TabType::GATE)
          _window->draw(_spriteMap[i][j]);
        else if (_gamemap[i][j] == TabType::PACGUM)
          _window->draw(_spriteMap[i][j]);
        else if (_gamemap[i][j] == TabType::SPACGUM)
          _window->draw(_spriteMap[i][j]);
        else if (_gamemap[i][j] == TabType::BLINKY)
          _window->draw(_spriteMap[i][j]);
        else if (_gamemap[i][j] == TabType::PACMAN)
          _window->draw(_spriteMap[i][j]);
        else if (_gamemap[i][j] == TabType::PINKY)
          _window->draw(_spriteMap[i][j]);
        else if (_gamemap[i][j] == TabType::INKY)
          _window->draw(_spriteMap[i][j]);
        else if (_gamemap[i][j] == TabType::CLYDE)
          _window->draw(_spriteMap[i][j]);
        else
        _window->draw(_spriteMap[i][j]);
        j++;
      }
    j = 0;
    i++;
  }
}

void gameMapSfml::InitSprite()
{
  int i = 0;
  int j = 0;
  while (i != _height)
  {
    while (j != _witdh)
      {
        if (_gamemap[i][j] == TabType::WALL)
          {
            sf::Sprite _pacSprite;
            _pacSprite.setTexture(*_textureMap[0]);
            _pacSprite.setPosition(j * 32, i * 32);
            _spriteMap[i][j] = _pacSprite;
          }
        else if (_gamemap[i][j] == TabType::GATE)
        {
          sf::Sprite _pacSprite;
          _pacSprite.setTexture(*_textureMap[1]);
          _pacSprite.setPosition(j * 32, i * 32);
          _spriteMap[i][j] = _pacSprite;

        }
        else if (_gamemap[i][j] == TabType::PACGUM)
        {
          sf::Sprite _pacSprite;
          _pacSprite.setTexture(*_textureMap[2]);
          _pacSprite.setPosition(j * 32, i * 32);
          _spriteMap[i][j] = _pacSprite;
        }
        else if (_gamemap[i][j] == TabType::SPACGUM)
          {
            sf::Sprite _pacSprite;
            _pacSprite.setTexture(*_textureMap[3]);
            _pacSprite.setPosition(j * 32, i * 32);
            _spriteMap[i][j] = _pacSprite;
          }
        else if (_gamemap[i][j] == TabType::BLINKY)
        {
          sf::Sprite _pacSprite;
          _pacSprite.setTexture(*_textureMap[4]);
          _pacSprite.setPosition(j * 32, i * 32);
          _spriteMap[i][j] = _pacSprite;
        }
        else if (_gamemap[i][j] == TabType::PACMAN)
        {
          sf::Sprite _pacSprite;
          _pacSprite.setTexture(*_textureMap[5]);
          //_pacSprite.setPosition(j * 32, i * 32);
          _pacSprite.move(j * 32, i * 32);
          _spriteMap[i][j] = _pacSprite;
        }
        else if (_gamemap[i][j] == TabType::PINKY)
        {
          sf::Sprite _pacSprite;
          _pacSprite.setTexture(*_textureMap[7]);
          _pacSprite.setPosition(j * 32, i * 32);
          _spriteMap[i][j] = _pacSprite;
        }
        else if (_gamemap[i][j] == TabType::INKY)
        {
          sf::Sprite _pacSprite;
          _pacSprite.setTexture(*_textureMap[8]);
          _pacSprite.setPosition(j * 32, i * 32);
          _spriteMap[i][j] = _pacSprite;
        }
        else if (_gamemap[i][j] == TabType::CLYDE)
        {
          sf::Sprite _pacSprite;
          _pacSprite.setTexture(*_textureMap[9]);
          _pacSprite.setPosition(j * 32, i * 32);
          _spriteMap[i][j] = _pacSprite;
        }
        else
          {
            sf::Sprite _pacSprite;
            _pacSprite.setTexture(*_textureMap[6]);
            _pacSprite.setPosition(j * 32, i * 32);
            _spriteMap[i][j] = _pacSprite;
          }
        j++;
      }
    j = 0;
    i++;
  }
}

void gameMapSfml::Game()
{
  int   t = 0;
  int   prevX = 0;
  int   prevY = 0;
  int   win = 1;

  sf::CircleShape shape(50);
  InitSprite();

  while (_window->isOpen() && (_pacman->isAlive() == true && win != 0))
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

    if (_gamemap[_pacman->getY()][_pacman->getX()] == TabType::BLINKY
        || _gamemap[_pacman->getY()][_pacman->getX()] == TabType::PINKY
        || _gamemap[_pacman->getY()][_pacman->getX()] == TabType::INKY
        || _gamemap[_pacman->getY()][_pacman->getX()] == TabType::CLYDE)
      _pacman->setLive(false);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
      _pacman->setDirection(Game::Direction::UP);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
      _pacman->setDirection(Game::Direction::DOWN);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
      _pacman->setDirection(Game::Direction::LEFT);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
      _pacman->setDirection(Game::Direction::RIGHT);

    _oldSPrite = 1;
    prevX = _pacman->getX();
    prevY = _pacman->getY();
    _pacman->movePlayer(_gamemap);

    if (_gamemap[_pacman->getY()][_pacman->getX()] == 4)
      _pacman->setScore(10);
    _score = _pacman->getScore();

    SetSprite(_pacman->getX(), _pacman->getY(), _pacman);
    UnsetSprite(prevX, prevY, _pacman);

    prevX = _blinky->getX();
    prevY = _blinky->getY();
    UnsetSprite(prevX, prevY, _blinky);
    _blinky->movePlayer(_gamemap);
    _blinkyCurr = _gamemap[_blinky->getY()][_blinky->getX()];
    SetSprite(_blinky->getX(), _blinky->getY(), _blinky);

    if (t > 10)
    {
      prevX = _pinky->getX();
      prevY = _pinky->getY();
      UnsetSprite(prevX, prevY, _pinky);
      _pinky->movePlayer(_gamemap);
      _pinkyCurr = _gamemap[_pinky->getY()][_pinky->getX()];
      SetSprite(_pinky->getX(), _pinky->getY(), _pinky);
    }

    if (t > 20)
    {
      prevX = _inky->getX();
      prevY = _inky->getY();
      UnsetSprite(prevX, prevY, _inky);
      _inky->movePlayer(_gamemap);
      _inkyCurr = _gamemap[_inky->getY()][_inky->getX()];
      SetSprite(_inky->getX(), _inky->getY(), _inky);
    }

    if (t > 30)
    {
      prevX = _clyde->getX();
      prevY = _clyde->getY();
      UnsetSprite(prevX, prevY, _clyde);
      _clyde->movePlayer(_gamemap);
      _clydeCurr = _gamemap[_clyde->getY()][_clyde->getX()];
      SetSprite(_clyde->getX(), _clyde->getY(), _clyde);
    }
    t++;
    Animation();
    _tempoSprite == 1 ? _tempoSprite = 0 : _tempoSprite = 1;
    usleep(100000);
 }
}

void gameMapSfml::SetSprite(int x, int y, Game::IGame *entity)
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

void gameMapSfml::UnsetSprite(int x, int y, Game::IGame *entity)
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

void gameMapSfml::Animation()
{
  if (_pacman->getDirection() == Game::Direction::UP)
    _textureMap[5]->loadFromFile("./games/pacman/sprite/sp_pacman.png", sf::IntRect(96, 0, 32, 32));
  else if (_pacman->getDirection() == Game::Direction::DOWN)
    _textureMap[5]->loadFromFile("./games/pacman/sprite/sp_pacman.png", sf::IntRect(64, 0, 32, 32));
  else if (_pacman->getDirection() == Game::Direction::RIGHT)
    _textureMap[5]->loadFromFile("./games/pacman/sprite/sp_pacman.png", sf::IntRect(32, 0, 32, 32));
  else if (_pacman->getDirection() == Game::Direction::LEFT)
    _textureMap[5]->loadFromFile("./games/pacman/sprite/sp_pacman.png", sf::IntRect(0, 0, 32, 32));

  if (_blinky->getDirection() == Game::Direction::UP)
    _textureMap[4]->loadFromFile("./games/pacman/sprite/sp_blinky.png", sf::IntRect(0 + _tempoSprite * 32, 0, 32, 32));
  else if (_blinky->getDirection() == Game::Direction::DOWN)
    _textureMap[4]->loadFromFile("./games/pacman/sprite/sp_blinky.png", sf::IntRect(64 + _tempoSprite * 32, 0, 32, 32));
  else if (_blinky->getDirection() == Game::Direction::RIGHT)
    _textureMap[4]->loadFromFile("./games/pacman/sprite/sp_blinky.png", sf::IntRect(192 + _tempoSprite * 32, 0, 32, 32));
  else if (_blinky->getDirection() == Game::Direction::LEFT)
    _textureMap[4]->loadFromFile("./games/pacman/sprite/sp_blinky.png", sf::IntRect(128 + _tempoSprite * 32, 0, 32, 32));

  if (_pinky->getDirection() == Game::Direction::UP)
    _textureMap[7]->loadFromFile("./games/pacman/sprite/sp_pinky.png", sf::IntRect(0 + _tempoSprite * 32, 0, 32, 32));
  else if (_pinky->getDirection() == Game::Direction::DOWN)
    _textureMap[7]->loadFromFile("./games/pacman/sprite/sp_pinky.png", sf::IntRect(64 + _tempoSprite * 32, 0, 32, 32));
  else if (_pinky->getDirection() == Game::Direction::RIGHT)
    _textureMap[7]->loadFromFile("./games/pacman/sprite/sp_pinky.png", sf::IntRect(192 + _tempoSprite * 32, 0, 32, 32));
  else if (_pinky->getDirection() == Game::Direction::LEFT)
    _textureMap[7]->loadFromFile("./games/pacman/sprite/sp_pinky.png", sf::IntRect(128 + _tempoSprite * 32, 0, 32, 32));

  if (_inky->getDirection() == Game::Direction::UP)
    _textureMap[8]->loadFromFile("./games/pacman/sprite/sp_inky.png", sf::IntRect(0 + _tempoSprite * 32, 0, 32, 32));
  else if (_inky->getDirection() == Game::Direction::DOWN)
    _textureMap[8]->loadFromFile("./games/pacman/sprite/sp_inky.png", sf::IntRect(64 + _tempoSprite * 32, 0, 32, 32));
  else if (_inky->getDirection() == Game::Direction::RIGHT)
    _textureMap[8]->loadFromFile("./games/pacman/sprite/sp_inky.png", sf::IntRect(192 + _tempoSprite * 32, 0, 32, 32));
  else if (_inky->getDirection() == Game::Direction::LEFT)
    _textureMap[8]->loadFromFile("./games/pacman/sprite/sp_inky.png", sf::IntRect(128 + _tempoSprite * 32, 0, 32, 32));

  if (_clyde->getDirection() == Game::Direction::UP)
    _textureMap[9]->loadFromFile("./games/pacman/sprite/sp_clyde.png", sf::IntRect(0 + _tempoSprite * 32, 0, 32, 32));
  else if (_clyde->getDirection() == Game::Direction::DOWN)
    _textureMap[9]->loadFromFile("./games/pacman/sprite/sp_clyde.png", sf::IntRect(64 + _tempoSprite * 32, 0, 32, 32));
  else if (_clyde->getDirection() == Game::Direction::RIGHT)
    _textureMap[9]->loadFromFile("./games/pacman/sprite/sp_clyde.png", sf::IntRect(192 + _tempoSprite * 32, 0, 32, 32));
  else if (_clyde->getDirection() == Game::Direction::LEFT)
    _textureMap[9]->loadFromFile("./games/pacman/sprite/sp_clyde.png", sf::IntRect(128 + _tempoSprite * 32, 0, 32, 32));
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

std::pair<std::string, std::string>	gameMapSfml::startMenu(const std::vector<std::string> & x, const std::vector<std::string> & y)
{
  (void) x;
  (void) y;
  std::pair<std::string, std::string> menu;
  return menu;
}

void gameMapSfml::displayMap(int ** l)
{
  (void) l;
}

void gameMapSfml::displayMap(int **i, int j, int k, int l)
{
  (void)i;
  (void)k;
  (void)j;
  (void)l;
}

void gameMapSfml::drawMap(int i, int j, char k)
{
  (void)i;
  (void)k;
  (void)j;
}

void gameMapSfml::drawPlayer(std::vector<Game::IGame*> i, char j)
{
  (void)i;
  (void)j;
}

void gameMapSfml::drawScore(int i, int j)
{
  (void)i;
  (void)j;
}

void gameMapSfml::drawFood(int i, int j, char k)
{
  (void)i;
  (void)k;
  (void)j;
}

void gameMapSfml::drawLoose(void)
{

}

int  gameMapSfml::recoverKey(void)
{
  return (0);
}

bool gameMapSfml::checkSizeWindow(int x, int y)
{
  (void)x;
  (void)y;
  return (true);
}
