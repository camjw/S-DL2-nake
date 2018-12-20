#ifndef SHIP_H
#define SHIP_H
#include "window.h"

class Snake : public Window {
  public:
    Snake(const Window &window, int w, int h, int x, int y, int r, int g, int b, int a);
    void draw();
    void move();
    void pollEvents(SDL_Event &event);

  private:
    int _w, _h;
    int _x, _y;
    int _dx, _dy;
    int _r, _g, _b, _a;
    float _theta = 0;
};

#endif
