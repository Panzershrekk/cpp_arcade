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
 BLINKY = 6,
 PACMAN = 7,
 PINKY = 8,
 INKY = 9,
 CLYDE = 10
};

class gameMapSfml : public Graph::IGraph
{
  private:
    Game::IGame *_pacman;
    Game::IGame *_blinky;
    Game::IGame *_pinky;
    Game::IGame *_inky;
    Game::IGame *_clyde;

    int _height;
    int _witdh;
    int _oldSPrite;
    int _blinkyCurr;
    int _pinkyCurr;
    int _inkyCurr;
    int _clydeCurr;

    sf::Sprite *_pacSprite;
    sf::RenderWindow *_window;
    int _score;
    std::map<int, std::map<int, int>> _gamemap;
    std::map<int, std::map<int, sf::Sprite>> _spriteMap;
    std::map<int, sf::Texture *> _textureMap;
  public:
    gameMapSfml();
    ~gameMapSfml();
    gameMapSfml(gameMapSfml const & other);
    gameMapSfml& operator=(gameMapSfml const & other);

    void createMap();
    void Game();
    void SetSprite(int x, int y, Game::IGame *entity);
    void UnsetSprite(int x, int y, Game::IGame *entity);
    std::pair<std::string, std::string>	startMenu(const std::vector<std::string> &, const std::vector<std::string> &);
    void displayMap(int **);
    void Animation();

    void InitSprite();

    void DumpMap();
};
