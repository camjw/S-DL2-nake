#include "ship.h"

Ship::Ship(const Window &window, int w, int h, int pos_x, int pos_y, int r, int g, int b, int a) :
  Window(window), _w(w), _h(h), _pos_x(pos_x), _pos_y(pos_y), _r(r), _g(g), _b(b), _a(a)
{
  
}

void Ship::draw() const {
  SDL_Rect rect;

  rect.w = _w;
  rect.h = _h;
  rect.x = _pos_x;
  rect.y = _pos_y;

  SDL_SetRenderDrawColor(_renderer, 200, 0, 200, 205);
  SDL_RenderFillRect(_renderer, &rect);
}

void Ship::pollEvents(SDL_Event &event) {
  if (event.type == SDL_KEYDOWN) {
    switch (event.key.keysym.sym) {
      case SDLK_LEFT:
        _pos_x -= 10;
        break;
    }
  }
}
