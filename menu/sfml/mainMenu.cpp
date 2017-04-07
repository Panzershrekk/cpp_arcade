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
  sf::Texture		background;
  sf::Texture		logo_pacman;
  sf::Texture		logo_snake;
  sf::Texture		logo_choice;
  sf::Texture		logo_buttons;
  sf::Vector2<int>	pos;
  std::string		games;
  std::string		libs;
  sf::Vector2u		window_size;
  sf::Sprite		_background_sprite;
  sf::Sprite		_logo_choice;
  sf::Sprite		_logo_buttons;
  int			test = 0;
  int			next = 0;

  games = "";
  libs = "ncurses";

  background.loadFromFile("/home/huguet_t/Documents/Rendu/Tek2/CPP/cpp_arcade/menu/sfml/sprites/Background_general.png", sf::IntRect(0, 0, 1920, 1080));
  _background_sprite.setTexture(background);
  _background_sprite.setPosition(0, 0);
  _background_sprite.setScale(0.56, 0.66);

  logo_choice.loadFromFile("/home/huguet_t/Documents/Rendu/Tek2/CPP/cpp_arcade/menu/sfml/sprites/Rectangle_de_selection.png", sf::IntRect(0, 0, 1920, 1080));
  _logo_choice.setTexture(logo_choice);
  _logo_choice.setPosition(0, 0);
  _logo_choice.setScale(0.56, 0.66);

  logo_pacman.loadFromFile("/home/huguet_t/Documents/Rendu/Tek2/CPP/cpp_arcade/menu/sfml/sprites/Pacman+Fantome.png", sf::IntRect(0, 0, 1920, 1080));
  _pacSprite.setTexture(logo_pacman);
  _pacSprite.setPosition(0, 0);
  _pacSprite.setScale(0.56, 0.66);

  logo_snake.loadFromFile("/home/huguet_t/Documents/Rendu/Tek2/CPP/cpp_arcade/menu/sfml/sprites/Snake.png", sf::IntRect(0, 0, 1920, 1080));
  _snakeSprite.setTexture(logo_snake);
  _snakeSprite.setPosition(0, 0);
  _snakeSprite.setScale(0.56, 0.66);


  logo_buttons.loadFromFile("/home/huguet_t/Documents/Rendu/Tek2/CPP/cpp_arcade/menu/sfml/sprites/Boutons_Menu.png", sf::IntRect(0, 0, 1920, 1080));
  _logo_buttons.setTexture(logo_buttons);
  _logo_buttons.setPosition(0, 0);
  _logo_buttons.setScale(0.56, 0.66);


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
	  std::cout << "pos X = " << pos.x << std::endl;
	  std::cout << "pos Y = " << pos.y << std::endl;
	  if (next == 0)
	  {
	    if (
	      (pos.x >= ((129.37 / 1080.0) * static_cast<double>(window_size.x))
	       && pos.x <=
		  ((295.31 / 1080.0) * static_cast<double>(window_size.x)))
	      && (pos.y <= ((420 / 720.0) * static_cast<double>(window_size.y))
		  && pos.y >=
		     ((316.67 / 720.0) * static_cast<double>(window_size.y))))
	    {
	      games = "pacman";
	      std::cout << "Pacman" << std::endl;
	    } else if (
	      (pos.x >= ((795.0 / 1080.0) * static_cast<double>(window_size.x))
	       &&
	       pos.x <= ((925.0 / 1080.0) * static_cast<double>(window_size.x)))
	      &&
	      (pos.y <= ((430.0 / 720.0) * static_cast<double>(window_size.y))
	       && pos.y >=
		  ((316.67 / 720.0) * static_cast<double>(window_size.y))))
	    {
	      std::cout << "Snake" << std::endl;
	      games = "snake";
	    }
	  }
	  if ((pos.x >= ((393.75 / 1080.0) * static_cast<double>(window_size.x))
		    && pos.x <= ((464.06 / 1080.0) * static_cast<double>(window_size.x)))
		   && (pos.y <= ((650.0 / 720.0) * static_cast<double>(window_size.y))
		       && pos.y >= ((558.0 / 720.0) * static_cast<double>(window_size.y))))
	    return;

	  else if ((pos.x >= ((506.25 / 1080.0) * static_cast<double>(window_size.x))
		    && pos.x <= ((576.56 / 1080.0) * static_cast<double>(window_size.x)))
		   && (pos.y <= ((600.0 / 720.0) * static_cast<double>(window_size.y))
		       && pos.y >= ((516.67 / 720.0) * static_cast<double>(window_size.y))))
	  {
	    if (next > 0)
	      next--;
	  }
	  else if ((pos.x >= ((604.69 / 1080.0) * static_cast<double>(window_size.x))
		    && pos.x <= ((683.06 / 1080.0) * static_cast<double>(window_size.x)))
		   && (pos.y <= ((650.0 / 720.0) * static_cast<double>(window_size.y))
		       && pos.y >= ((558.0 / 720.0) * static_cast<double>(window_size.y))))
	  {
	    if(next == 0 && games != "")
	      next++;
	    else if (next == 1 && libs != "")
	    {
	      void *lib;

	      std::string lib_func = ("./lib/lib_" + games + ".so");
	      std::cout << lib_func << std::endl;
	      if ((lib = dlopen(lib_func.c_str(), RTLD_LAZY)) == NULL)
	      {
		std::cout << "The error is    " << dlerror() << std::endl;
		exit(EXIT_FAILURE);
	      }

	      typedef void	(*func_ptr)();
	      lib_func = games + "_" + libs;
	      func_ptr func = (func_ptr)dlsym(lib,lib_func.c_str());

	      if (!func)
	      {
		std::cout << "The error is    " << dlerror() << std::endl;
		exit(EXIT_FAILURE);
	      }
	      _window.close();

	      func();
	      dlclose(lib);
	      return;
	    }
	  }
	}
      }
    }
    _window.clear();
    _window.draw(_background_sprite);
    if (next == 0)
    {
      _window.draw(_pacSprite);
      _window.draw(_snakeSprite);
      if (games == "pacman" && test == 1)
	_window.draw(_logo_choice);
      if (test == 1)
	test = 0;
      else if (test == 0)
	test = 1;
    }
    _window.draw(_logo_buttons);
    _window.display();
  }
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
