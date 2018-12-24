#include "snake.h"
#include <iostream>

Snake::Snake(const Window &window, int stride, int x, int y, int r, int g, int b, int a) :
  Window(window), _stride(stride), _x(x), _y(y), _r(r), _g(g), _b(b), _a(a), _dx(0), _dy(0)
{
  currentDir = RIGHT;
  attemptedDir = RIGHT;
  alive = true;
}

void Snake::draw() {
  move();

  for (int i = 0; i < locationHistory.size(); ++i) {
    std::vector<int> currentSquare = locationHistory.at(i);

    SDL_Rect rect;

    rect.w = _stride - 2;
    rect.h = _stride - 2;
    rect.x = currentSquare.at(0) + 1;
    rect.y = currentSquare.at(1) + 1;

    renderRect(rect, _r, _g, _b, _a);
  }
  acceptingMove = true;
}

void Snake::updateLocationHistory() {
  locationHistory.push_back(std::vector<int> { _x, _y });
  if (locationHistory.size() > _currentLength) {
    locationHistory.pop_front();
  }
}

void Snake::updateDirection() {
  if (attemptedDir == LEFT && currentDir != RIGHT) {
    _dx = -_stride;
    _dy = 0;
    currentDir = LEFT;
  } else if (attemptedDir == RIGHT && currentDir != LEFT) {
    _dx = _stride;
    _dy = 0;
    currentDir = RIGHT;
  } else if (attemptedDir == UP && currentDir != DOWN) {
    _dx = 0;
    _dy = -_stride;
    currentDir = UP;
  } else if (attemptedDir == DOWN && currentDir != UP) {
    _dx = 0;
    _dy = _stride;
    currentDir = DOWN;
  }
  acceptingMove = false;
}

void Snake::move() {
  updateDirection();
  _x += _dx;
  _y += _dy;
  updateLocationHistory();
}

std::vector<int> Snake::getLocation() {
  return std::vector<int> { _x, _y };
}

std::deque<std::vector<int>> Snake::getLocationHistory() {
  return locationHistory;
}

void Snake::grow() {
  _currentLength += 4;
}

void Snake::pollEvents(SDL_Event &event) {
  if (acceptingMove) {
    if (event.type == SDL_KEYDOWN) {
      switch (event.key.keysym.sym) {
        case SDLK_LEFT:
          attemptedDir = LEFT;
        break;
        case SDLK_RIGHT:
          attemptedDir = RIGHT;
        break;
        case SDLK_UP:
          attemptedDir = UP;
        break;
        case SDLK_DOWN:
          attemptedDir = DOWN;
        break;
      }
    }
  }
}

std::vector<int> Snake::checkSelfEat() {
  for (int i = 0; i < locationHistory.size() - 1; ++i) {
    for (int j = i + 1; j < locationHistory.size(); ++j){
      if (locationHistory[i] == locationHistory[j]) {
        std::cout << i << j << std::endl;
        alive = false;
        return locationHistory[i];
      }
    }
  }
  return locationHistory[0];
}

bool Snake::isDead() {
  return !alive;
}
