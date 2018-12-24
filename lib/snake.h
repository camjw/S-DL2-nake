#ifndef SNAKE_H
#define SNAKE_H
#include <vector>
#include <deque>
#include <algorithm>
#include "window.h"

class Snake : public Window {
  public:
    Snake(const Window &window, int stride, int x, int y, int r, int g, int b, int a);
    virtual void draw();
    virtual void move();
    virtual void pollEvents(SDL_Event &event);
    std::vector<int> getLocation();
    std::deque<std::vector<int>> getLocationHistory();
    enum directions { UP, DOWN, LEFT, RIGHT };
    virtual void grow();
    std::vector<int> checkSelfEat();
    bool isDead();

  private:
    virtual void updateLocationHistory();
    virtual void updateDirection();
    std::deque<std::vector<int>> locationHistory;
    directions currentDir, attemptedDir;
    bool acceptingMove = true;
    bool alive = true;
    int _currentLength = 4;
    int _stride;
    int _x, _y;
    int _dx, _dy;
    int _r, _g, _b, _a;
};

#endif
