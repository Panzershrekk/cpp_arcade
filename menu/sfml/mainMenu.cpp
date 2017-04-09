//
// Created by huguet_t on 31/03/17.
//

#include  <SFML/Graphics.hpp>
#include "include/mainMenu.hpp"

menu::menu()
{
  boolean = 0;
  pos = 0;
  _window = new sf::RenderWindow(sf::VideoMode(1080, 720), "Pacman");
  _games[0] = "Pacman";
  _games[1] = "Snake";
  _libs[0] = "ncurses";
  _libs[1] = "SFML";
  _libs[2] = "Open Gl";

  background = new sf::Texture;
  background->loadFromFile("./menu/sfml/sprites/Background_general.png", sf::IntRect(0, 0, 1920, 1080));
  _background_sprite.setTexture(*background);
  _background_sprite.setPosition(0, 0);
  _background_sprite.setScale(0.56, 0.66);

  logo_choice = new sf::Texture;
  logo_choice->loadFromFile("./menu/sfml/sprites/Rectangle_de_selection.png", sf::IntRect(0, 0, 1920, 1080));
  _logo_choice.setTexture(*logo_choice);
  _logo_choice.setPosition(0, 0);
  _logo_choice.setScale(0.56, 0.66);

  sfml = new sf::Texture;
  sfml->loadFromFile("./menu/sfml/sprites/Boutons_SFML.png", sf::IntRect(0, 0, 1920, 1080));
  _sfml_sprite.setTexture(*sfml);
  _sfml_sprite.setPosition(0, 0);
  _sfml_sprite.setScale(0.56, 0.66);

  ncurses = new sf::Texture;
  ncurses->loadFromFile("./menu/sfml/sprites/Boutons_NCURSES.png", sf::IntRect(0, 0, 1920, 1080));
  _ncurses_sprite.setTexture(*ncurses);
  _ncurses_sprite.setPosition(0, 0);
  _ncurses_sprite.setScale(0.56, 0.66);

  logo_pacman = new sf::Texture;
  logo_pacman->loadFromFile("./menu/sfml/sprites/Pacman+Fantome.png", sf::IntRect(0, 0, 1920, 1080));
  _pacSprite.setTexture(*logo_pacman);
  _pacSprite.setPosition(0, 0);
  _pacSprite.setScale(0.56, 0.66);

  logo_snake = new sf::Texture;
  logo_snake->loadFromFile("./menu/sfml/sprites/Snake.png", sf::IntRect(0, 0, 1920, 1080));
  _snakeSprite.setTexture(*logo_snake);
  _snakeSprite.setPosition(0, 0);
  _snakeSprite.setScale(0.56, 0.66);

  logo_buttons = new sf::Texture;
  logo_buttons->loadFromFile("./menu/sfml/sprites/Boutons_Menu.png", sf::IntRect(0, 0, 1920, 1080));
  _logo_buttons.setTexture(*logo_buttons);
  _logo_buttons.setPosition(0, 0);
  _logo_buttons.setScale(0.56, 0.66);
}

menu::~menu()
{
}

void		menu::Game()
{
  //sf::RenderWindow	_window(sf::VideoMode(1080, 720), "Arcade Menu");
  sf::Vector2<int>	pos;
  std::string		games;
  std::string		libs;
  sf::Vector2u		window_size;
  int			test = 0;
  int			next = 0;
  int			affichage = 0;

  sf::CircleShape shape(50);
  games = "";
  libs = "";

  while (_window->isOpen())
  {
    sf::Event event;
    while (_window->pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
	_window->close();
      if (event.type == sf::Event::MouseButtonPressed)
      {
	if (event.mouseButton.button == sf::Mouse::Left)
	{
	  pos = sf::Mouse::getPosition(*_window);

	  window_size = _window->getSize();
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
	    }
	    else if (
	      (pos.x >= ((795.0 / 1080.0) * static_cast<double>(window_size.x))
	       &&
	       pos.x <= ((925.0 / 1080.0) * static_cast<double>(window_size.x)))
	      &&
	      (pos.y <= ((430.0 / 720.0) * static_cast<double>(window_size.y))
	       && pos.y >=
		  ((316.67 / 720.0) * static_cast<double>(window_size.y))))
	    {
	      games = "snake";
	    }
	  }
	  else if (next == 1)
	  {
	    if (
	      (pos.x >= ((399.38 / 1080.0) * static_cast<double>(window_size.x))
	       && pos.x <=
		  ((464.06 / 1080.0) * static_cast<double>(window_size.x)))
	      && (pos.y <= ((460 / 720.0) * static_cast<double>(window_size.y))
		  && pos.y >=
		     ((450 / 720.0) * static_cast<double>(window_size.y))))
	    {
	      libs = "SFML";
	    }
	    if (
	      (pos.x >= ((604.69 / 1080.0) * static_cast<double>(window_size.x))
	       && pos.x <=
		  ((663.75 / 1080.0) * static_cast<double>(window_size.x)))
	      && (pos.y <= ((460 / 720.0) * static_cast<double>(window_size.y))
		  && pos.y >=
		     ((450 / 720.0) * static_cast<double>(window_size.y))))
	    {
	      libs = "ncurses";
	    }
	  }
	  if ((pos.x >= ((393.75 / 1080.0) * static_cast<double>(window_size.x))
	       && pos.x <=
		  ((464.06 / 1080.0) * static_cast<double>(window_size.x)))
	      &&
	      (pos.y <= ((650.0 / 720.0) * static_cast<double>(window_size.y))
	       &&
	       pos.y >= ((558.0 / 720.0) * static_cast<double>(window_size.y))))
	  {
	    if (next > 0)
	      next--;
	  }
	  else if ((pos.x >= ((506.25 / 1080.0) * static_cast<double>(window_size.x))
		    && pos.x <= ((576.56 / 1080.0) * static_cast<double>(window_size.x)))
		   && (pos.y <= ((600.0 / 720.0) * static_cast<double>(window_size.y))
		       && pos.y >= ((516.67 / 720.0) * static_cast<double>(window_size.y))))
	    return;
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

	      std::string lib_func = ("./lib/lib_arcade_" + games + ".so");
	      if ((lib = dlopen(lib_func.c_str(), RTLD_LAZY)) == NULL)
	      {
		std::cout << "error: failed to load the lib" << lib_func << std::endl;
		_window->close();
		return;
	      }

	      typedef void	(*func_ptr)();
	      lib_func = games + "_" + libs;
	      func_ptr func = (func_ptr)dlsym(lib,lib_func.c_str());

	      if (!func)
	      {
		std::cout << "error: failed to load the function" << lib_func << std::endl;
		_window->close();
		exit(EXIT_FAILURE);
	      }
	      _window->close();

	      func();

	      dlclose(lib);

	      return;
	    }
	  }
	}
      }
    }
    _window->clear();
    _window->draw(_background_sprite);
    if (next == 0)
    {
      _window->draw(_pacSprite);
      _window->draw(_snakeSprite);
      if (test % 40 == 0)
      {
	if (affichage == 0)
	  affichage = 1;
	else
	  affichage = 0;
    }
      if (games == "pacman" && affichage == 0)
      {
	_logo_choice.setPosition(0, 0);
	_window->draw(_logo_choice);
      }
      if (games == "snake" && affichage == 0)
      {
	_logo_choice.setPosition(640, 0);
	_window->draw(_logo_choice);
      }
    }
    else
    {
      if (libs == "SFML")
      {
	sfml->loadFromFile("./menu/sfml/sprites/Boutons_SFML_Cliked.png", sf::IntRect(0, 0, 1920, 1080));
	ncurses->loadFromFile("./menu/sfml/sprites/Boutons_NCURSES.png", sf::IntRect(0, 0, 1920, 1080));
	_sfml_sprite.setTexture(*sfml);
	_ncurses_sprite.setTexture(*ncurses);
      }
      else if (libs == "ncurses")
      {
	sfml->loadFromFile("./menu/sfml/sprites/Boutons_SFML.png", sf::IntRect(0, 0, 1920, 1080));
	ncurses->loadFromFile("./menu/sfml/sprites/Boutons_NCURSES_Cliked.png", sf::IntRect(0, 0, 1920, 1080));
	_sfml_sprite.setTexture(*sfml);
	_ncurses_sprite.setTexture(*ncurses);
      }
      _window->draw(_sfml_sprite);
      _window->draw(_ncurses_sprite);
    }
    test++;
    _window->draw(_logo_buttons);
    _window->display();
  }
  delete _window;
  delete background;
  delete sfml;
  delete ncurses;
  delete logo_pacman;
  delete logo_snake;
  delete logo_choice;
  delete logo_buttons;
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
