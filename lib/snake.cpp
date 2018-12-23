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

    rect.w = _w - 2;
    rect.h = _h - 2 ;
    rect.x = currentSquare.at(0) + 1;
    rect.y = currentSquare.at(1) + 1;

    SDL_SetRenderDrawColor(_renderer, _r, _g, _b, _a);
    SDL_RenderFillRect(_renderer, &rect);
  }
  acceptingMove = true;
}

void Snake::updatePositionHistory() {
  positionHistory.push_back(std::vector<int> { _x, _y });
  if (positionHistory.size() > _currentLength) {
    positionHistory.pop_front();
  }
}

void Snake::updateDirection(directions dir) {
  if (dir == LEFT && currentDir != RIGHT) {
    _dx = -_w;
    _dy = 0;
    currentDir = LEFT;
  } else if (dir == RIGHT && currentDir != LEFT) {
    _dx = _w;
    _dy = 0;
    currentDir = RIGHT;
  } else if (dir == UP && currentDir != DOWN) {
    _dx = 0;
    _dy = -_h;
    currentDir = UP;
  } else if (dir == DOWN && currentDir != UP) {
    _dx = 0;
    _dy = _h;
    currentDir = DOWN;
  }
  acceptingMove = false;
}

void Snake::move() {
  _x += _dx;
  _y += _dy;
  updatePositionHistory();
}

void Snake::pollEvents(SDL_Event &event) {
  if (acceptingMove) {
    if (event.type == SDL_KEYDOWN) {
      switch (event.key.keysym.sym) {
        case SDLK_LEFT:
        updateDirection(LEFT);
        break;
        case SDLK_RIGHT:
        updateDirection(RIGHT);
        break;
        case SDLK_UP:
        updateDirection(UP);
        break;
        case SDLK_DOWN:
        updateDirection(DOWN);
        break;
      }
    }
  }
}