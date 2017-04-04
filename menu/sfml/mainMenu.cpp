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
  sf::RenderWindow _window(sf::VideoMode(1080, 720), "Arcade Menu");
  sf::CircleShape shape(50);
  sf::Texture logo_pacman;
  sf::Texture logo_snake;
  sf::Vector2<int> pos;

  logo_pacman.loadFromFile("./sfml/logo.png", sf::IntRect(0, 0, 483, 149));
  logo_snake.loadFromFile("./sfml/snake_logo.png", sf::IntRect(0, 0, 400, 400));

  sf::Sprite _pacSprite;
  _pacSprite.setTexture(logo_pacman);
  _pacSprite.setPosition(15, 270);

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
      if (event.type == sf::Event::MouseButtonPressed)
      {
	if (event.mouseButton.button == sf::Mouse::Left)
	{
	  pos = sf::Mouse::getPosition(_window);

	  std::cout << pos.y << std::endl;
	  std::cout << pos.x << std::endl;
	  if ((pos.x >= 15 && pos.x <= 498) && (pos.y <= 419 && pos.y >= 270))
	    std::cout << "clique pacman" << std::endl;

	  else if (pos.x >= 540 && pos.x <= (540 + 400) &&
		   pos.y <= (160 + 400) && pos.y >= 160)
	    std::cout << "clique snake" << std::endl;
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

extern "C" void		do_menu()
{
  menu	test;

  test.Game();
}