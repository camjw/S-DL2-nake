#ifndef SHIP_H
#define SHIP_H
#include "window.h">

class Ship : public Window {

  public:
    Rect(const Window &window, int w, int h, int pos_x, int pos_y, int r, int g, int b, int a);
    void draw() const;
    void pollEvents();

  private:
    int _w, _h;
    int _pos_x, _pos_y;
    int _r, _g, _b, _a;
};

#endif
