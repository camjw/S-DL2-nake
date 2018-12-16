#include "ship.h"
#include <iostream>

Ship::Ship(const Window &window, int w, int h, int x, int y, int r, int g, int b, int a) :
  Window(window), _w(w), _h(h), _x(x), _y(y), _r(r), _g(g), _b(b), _a(a)
{
}

void Ship::draw() const {
  SDL_Rect rect;

  rect.w = _w;
  rect.h = _h;
  rect.x = _x;
  rect.y = _y;

  SDL_SetRenderDrawColor(_renderer, 200, 0, 200, 205);
  SDL_RenderFillRect(_renderer, &rect);
  // std::cout << _w << " " << _h << _pos_x << _pos_y << std::endl;
}

// void Ship::pollEvents(SDL_Event &event) {
//   if (event.type == SDL_KEYDOWN) {
//     switch (event.key.keysym.sym) {
//       case SDLK_LEFT:
//         _pos_x -= 10;
//         break;
//     }
//   }
// }
