#include  "IGraph.hpp"

class gameMapNcurses : public graph::IGraph
{
  public:
    gameMapNcurses();
    ~gameMapNcurses();
    gameMapNcurses(gameMapNcurses const & other);
    gameMapNcurses& operator=(gameMapNcurses const & other);

    void createMap();
    void Game() = 0;
    void SetSprite();
    void UnsetSprite();
    void Animation();
};
