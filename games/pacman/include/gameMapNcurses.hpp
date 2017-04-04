#include  <ncurses.h>
#include  "Pacman.hpp"
#include  "IGame.hpp"
#include  "Blinky.hpp"
#include  "Pinky.hpp"
#include  "Inky.hpp"
#include  "Clyde.hpp"
#include  "IGraph.hpp"

enum TabType
{
 VOID = 0,
 WALKABLE = 1,
 WALL = 2,
 GATE = 3,
 PACGUM = 4,
 SPACGUM = 5,
 BLINKY = 6,
 PACMAN = 7,
 PINKY = 8,
 INKY = 9,
 CLYDE = 10
};

class gameMapNcurses : public graph::IGraph
{
  private:

    game::IGame *_pacman;
    game::IGame *_blinky;
    game::IGame *_pinky;
    game::IGame *_inky;
    game::IGame *_clyde;

    int _height;
    int _witdh;
    int _oldSPrite;
    int _blinkyCurr;
    int _pinkyCurr;
    int _inkyCurr;
    int _clydeCurr;
    std::map<int, std::map<int, int>> _gamemap;
  public:
    gameMapNcurses();
    ~gameMapNcurses();
    gameMapNcurses(gameMapNcurses const & other);
    gameMapNcurses& operator=(gameMapNcurses const & other);

    void createMap();
    void Game();
    void SetSprite(int x, int y, game::IGame *entity);
    void UnsetSprite(int x, int y, game::IGame *entity);
    void Animation();

    void DumpMap();
};
