//
// Created by huguet_t on 31/03/17.
//

#ifndef CPP_ARCADE_MENU_HPP
#define CPP_ARCADE_MENU_HPP

#include "IGraph.hpp"
#include "IGame.hpp"

class menu : public graph::IGraph
{
    std::map<int, std::string>	_games;
    std::map<int, std::string>	_libs;
    int				ch;
    int				pos;
    int				boolean;

  public:
    menu();
    ~menu();
    void createMap();
    void Game();
    void SetSprite(int x, int y, game::IGame *entity);
    void UnsetSprite(int x, int y, game::IGame *entity);
    void Animation();
};


#endif //CPP_ARCADE_MENU_HPP
