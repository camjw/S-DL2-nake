#include "ship.h"
#include <iostream>

Ship::Ship(const Window &window, int w, int h, int x, int y, int r, int g, int b, int a) :
  Window(window), _w(w), _h(h), _x(x), _y(y), _r(r), _g(g), _b(b), _a(a)
{
  _dx = 0;
  _dy = 0;
}

void Ship::draw() {
  move();
  SDL_Rect rect;

  rect.w = _w;
  rect.h = _h;
  rect.x = _x;
  rect.y = _y;

  SDL_SetRenderDrawColor(_renderer, 200, 0, 200, 205);
  SDL_RenderFillRect(_renderer, &rect);
}

void Ship::move() {
  _x += _dx;
  _y += _dy;
}

void Ship::pollEvents(SDL_Event &event) {
  if (event.type == SDL_KEYDOWN) {
    switch (event.key.keysym.sym) {
      case SDLK_LEFT:
        _dx = -1;
        _dy = 0;
        break;
      case SDLK_RIGHT:
        _dx = +1;
        _dy = 0;
        break;
      case SDLK_UP:
        _dy = -1;
        _dx = 0;
        break;
      case SDLK_DOWN:
        _dy = +1;
        _dx = 0;
        break;
      default:
        _dx = std::max(0, _dx - 1);
        _dy = std::max(0, _dy - 1);
        break;
    }
  }
}
