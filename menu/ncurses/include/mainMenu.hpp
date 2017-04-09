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
    void displayMap(int **, int, int, int);
    void drawMap(int, int, char);
    void drawPlayer(std::vector<Game::IGame*>, char);
    void drawScore(int, int);
    void drawFood(int, int, char);
    void drawLoose(void);
    int  recoverKey(void);
    bool checkSizeWindow(int x, int y);
};


#endif //CPP_ARCADE_MENU_HPP
