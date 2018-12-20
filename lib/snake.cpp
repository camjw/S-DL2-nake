#include "snake.h"
#include <iostream>

Snake::Snake(const Window &window, int w, int h, int x, int y, int r, int g, int b, int a) :
  Window(window), _w(w), _h(h), _x(x), _y(y), _r(r), _g(g), _b(b), _a(a)
{
  _dx = 0;
  _dy = 0;
}

void Snake::draw() {
  move();
  SDL_Rect rect;

  rect.w = _w;
  rect.h = _h;
  rect.x = _x;
  rect.y = _y;

  SDL_SetRenderDrawColor(_renderer, _r, _g, _b, _a);
  SDL_RenderFillRect(_renderer, &rect);
}

void Snake::move() {
  _x += _dx;
  _y += _dy;
}

void Snake::pollEvents(SDL_Event &event) {
  if (event.type == SDL_KEYDOWN) {
    switch (event.key.keysym.sym) {
      case SDLK_LEFT:
        _dx = -_w;
        _dy = 0;
        break;
      case SDLK_RIGHT:
        _dx = _w;
        _dy = 0;
        break;
      case SDLK_UP:
        _dy = -_w;
        _dx = 0;
        break;
      case SDLK_DOWN:
        _dy = _w;
        _dx = 0;
        break;
    }
  }
}
