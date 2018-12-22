#ifndef SNAKE_H
#define SNAKE_H
#include <vector>
#include <deque>
#include "window.h"

class Snake : public Window {
  public:
    Snake(const Window &window, int w, int h, int x, int y, int r, int g, int b, int a);
    std::deque<std::vector<int>> positionHistory;
    void draw();
    void move();
    void pollEvents(SDL_Event &event);
    enum Directions { UP, DOWN, LEFT, RIGHT };

  private:
    void updatePositionHistory();
    void updateDirection(Directions dir);
    Directions currentDir;
    int _currentLength = 4;
    int _w, _h;
    int _x, _y;
    int _dx, _dy;
    int _r, _g, _b, _a;
};

#endif
