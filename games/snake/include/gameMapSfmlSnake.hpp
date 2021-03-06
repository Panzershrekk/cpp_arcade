#ifndef _GAMEMAPSFMLSNAKE_HPP_
# define _GAMEMAPSFMLSNAKE_HPP_

#include  <SFML/Graphics.hpp>
#include  "Snake.hpp"
#include  "IGame.hpp"
#include  "IGraph.hpp"

enum TabTypeSnake
{
  CANWALK = 0,
  WALLE = 1,
  APPLE = 2,
  SNAK = 3
};

class gameMapSfmlSnake : public Graph::IGraph
{
  private:

    int _height;
    int _witdh;
    int _oldSPrite;

  sf::Sprite *_snakSprite;
  sf::RenderWindow *_window;
    std::map<int, std::map<int, int>> _gamemap;
    std::map<int, std::map<int, sf::Sprite>> _spriteMap;
    std::map<int, sf::Texture *> _textureMap;
  public:
    gameMapSfmlSnake();
    ~gameMapSfmlSnake();
    gameMapSfmlSnake(gameMapSfmlSnake const & other);
    gameMapSfmlSnake& operator=(gameMapSfmlSnake const & other);
  std::pair<std::string, std::string> startMenu(const std::vector<std::string> &, const std::vector<std::string> &);
  void Animation();
  std::vector<Position> movePosSnake(int, int, std::vector<Position>, Snake *);
  void createMap();
    void Game();
    void SetSprite(int x, int y, Game::IGame *entity);
    void UnsetSprite(int x, int y, Game::IGame *entity);
    void displayMap(int **);
    void displayMap(int **, int, int, int);
    void drawMap(int, int, char);
    void drawPlayer(std::vector<Game::IGame*>, char);
    void drawScore(int, int);
    void drawFood(int, int, char);
    void drawLoose(void);
    int  recoverKey(void);
    bool checkSizeWindow(int x, int y);
  void resetMap();
  void InitSprite();
  void genApple();
    void DumpMap();
};

#endif
