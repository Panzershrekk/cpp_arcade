//
// Created by huguet_t on 31/03/17.
//

#include  <SFML/Graphics.hpp>
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

void		menu::Game()
{
  sf::RenderWindow	_window(sf::VideoMode(1080, 720), "Arcade Menu");
  sf::Texture		logo_pacman;
  sf::Texture		logo_snake;
  sf::Vector2<int>	pos;
  std::string		games;
  std::string		libs;
  sf::Vector2u		window_size;

  games = "";
  libs = "";
  logo_pacman.loadFromFile("./sfml/logo.png", sf::IntRect(0, 0, 483, 149));
  logo_snake.loadFromFile("./sfml/snake_logo.png", sf::IntRect(0, 0, 400, 400));

  _pacSprite.setTexture(logo_pacman);
  _pacSprite.setPosition(40, 170);
  _pacSprite.setScale(0.75, 0.75);

  _snakeSprite.setTexture(logo_snake);
  _snakeSprite.setPosition(540, 70);
  _snakeSprite.setScale(0.75, 0.75);

  while (_window.isOpen())
  {
    sf::Event event;
    while (_window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
	_window.close();
      if (event.type == sf::Event::MouseButtonPressed)
      {
	if (event.mouseButton.button == sf::Mouse::Left)
	{
	  pos = sf::Mouse::getPosition(_window);

	  window_size = _window.getSize();
	  std::cout << "x = " << window_size.x << std::endl;
	  std::cout << "y = " << window_size.y << std::endl;
	  if ((pos.x >= ((15.0 / 1080.0) * static_cast<double>(window_size.x))
	       && pos.x <= ((498.0 / 1080.0) * static_cast<double>(window_size.x)))
	      && (pos.y <= ((319.0 / 720.0) * static_cast<double>(window_size.y))
		  && pos.y >= ((170.0 / 720.0) * static_cast<double>(window_size.y))))
	    games = "Pacman";

	  else if (pos.x >= ((540.0 / 1080.0) * static_cast<double>(window_size.x))
		   && pos.x <= (((540.0 + 400.0) / 1080.0) * static_cast<double>(window_size.x))
		   && pos.y <= (((70.0 + 400.0) / 1080.0) * static_cast<double>(window_size.y))
				&& pos.y >= ((70.0 / 1080.0) * static_cast<double>(window_size.x)))
	    games = "Snake";
	}
      }
    }
    _window.clear();
    _window.draw(_pacSprite);
    _window.draw(_snakeSprite);
    _window.display();
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

}

void menu::createMap()
{
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
  menu	test;

  test.Game();
}
