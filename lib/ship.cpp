#include "ship.h"

Ship::Ship(const Window &window, int w, int h, int pos_x, int pos_y, int r, int g, int b, int a) {
  Window(window), _w(w), _h(h), _pos_x(pos_x), _pos_y(pos_y), _r(r), _g(g), _b(b), _a(a);
}
