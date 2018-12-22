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

  for (int i = 0; i < positionHistory.size(); ++i) {
    std::vector<int> currentSquare = positionHistory.at(i);

    SDL_Rect rect;

    rect.w = _w;
    rect.h = _h;
    rect.x = currentSquare.at(0);
    rect.y = currentSquare.at(1);

    SDL_SetRenderDrawColor(_renderer, _r, _g, _b, _a);
    SDL_RenderFillRect(_renderer, &rect);
  }
}

void Snake::updatePositionHistory() {
  positionHistory.push_back(std::vector<int> { _x, _y });
  if (positionHistory.size() > _currentLength) {
    positionHistory.pop_front();
  }
}

void Snake::move() {
  _x += _dx;
  _y += _dy;
  updatePositionHistory();
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
