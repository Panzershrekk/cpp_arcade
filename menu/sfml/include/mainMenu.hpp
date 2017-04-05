//
// Created by huguet_t on 31/03/17.
//

#ifndef CPP_ARCADE_MENU_HPP
#define CPP_ARCADE_MENU_HPP

#include "IGraph.hpp"
#include "IGame.hpp"

class menu : public Graph::IGraph
{
    std::map<int, std::string>	_games;
    std::map<int, std::string>	_libs;
    int				ch;
    int				pos;
    int				boolean;
    sf::Sprite			_pacSprite;
    sf::Sprite			_snakeSprite;

  public:
    menu();
    ~menu();
    void createMap();
    void Game();
    void SetSprite(int x, int y, Game::IGame *entity);
    void UnsetSprite(int x, int y, Game::IGame *entity);
    void Animation();
    std::pair<std::string, std::string>	startMenu(const std::vector<std::string> &, const std::vector<std::string> &);
    void displayMap(int **);
};


#endif //CPP_ARCADE_MENU_HPP
