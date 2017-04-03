#include  <SFML/Graphics.hpp>
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
 GHOST = 6,
 PACMAN = 7
};

class gameMapSfml : public graph::IGraph
{
  private:
    int _height;
    int _witdh;
    sf::Sprite _pacSprite;
    sf::RenderWindow _window;
    /*int _blinkyCurr;
    int _pinkyCurr;
    int _inkyCurr;
    int _clydeCurr;*/
    std::map<int, std::map<int, int>> _gamemap;
    std::map<int, std::map<int, sf::Sprite>> _spriteMap;
  public:
    gameMapSfml();
    ~gameMapSfml();
    gameMapSfml(gameMapSfml const & other);
    gameMapSfml& operator=(gameMapSfml const & other);

    void createMap();
    void Game();
    void SetSprite(int x, int y, game::IGame *entity);
    void UnsetSprite(int x, int y, game::IGame *entity);
    void Animation();

    void DumpMap();
};
