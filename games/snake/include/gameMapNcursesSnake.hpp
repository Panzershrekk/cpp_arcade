#include  <ncurses.h>
#include  "IGame.hpp"
#include  "IGraph.hpp"
#include <vector>
#include "Snake.hpp"
// #include "gameMapNcursesSnake.hpp"

enum TabTypeSnake
{
  CANWALK = 0,
  WALLE = 1,
  APPLE = 2,
  SNAK = 3
};

class gameMapNcursesSnake : public Graph::IGraph
{
  private:
    int _height;
    int _witdh;
    std::map<int, std::map<int, int>> _gamemap;
  public:
    gameMapNcursesSnake();
    ~gameMapNcursesSnake();
    gameMapNcursesSnake(gameMapNcursesSnake const & other);
  gameMapNcursesSnake& operator=(gameMapNcursesSnake const & other);
  std::vector<Position> movePosSnake(int, int, std::vector<Position>, Snake *);
    void createMap();
    void Game();
    void SetSpriteByEnum(int x, int y, int tmp);
    void SetSprite(int x, int y, Game::IGame *entity);
    void UnsetSprite(int x, int y, Game::IGame *entity);
    void Animation();
    void genApple();
    void DumpMap();
    std::pair<std::string, std::string>	startMenu(const std::vector<std::string> &, const std::vector<std::string> &);
    void displayMap(int **);
  void resetMap();
};
