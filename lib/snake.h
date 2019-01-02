#ifndef SNAKE_H
#define SNAKE_H
#include <vector>
#include <deque>
#include <algorithm>
#include "renderer.h"

class Snake : public Renderer {
  public:
    Snake(const Renderer &renderer, int stride, int x, int y, int r, int g, int b, int a);
    virtual void draw();
    void move();
    void pollEvents(SDL_Event &event);
    virtual std::vector<int> getLocation();
    virtual std::deque<std::vector<int>> getLocationHistory();
    enum directions { UP, DOWN, LEFT, RIGHT };
    virtual void grow();
    void checkDeath(int grid_width);
    bool isDead();
    void showDeath();
    virtual void reset();
    virtual ~Snake() {};

  private:
    void updateLocationHistory();
    void updateDirection();
    std::vector<int> checkSelfEat();
    void checkHitWall(int grid_width);
    std::deque<std::vector<int>> locationHistory;
    directions currentDir = RIGHT;
    directions attemptedDir = RIGHT;
    bool acceptingMove = true;
    bool alive = true;
    int _currentLength = 4;
    int _stride;
    int _x, _y;
    int _dx, _dy;
    int _r, _g, _b, _a;
};

#endif
