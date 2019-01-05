#include "snake.h"
#include <iostream>

Snake::Snake(const Renderer &renderer, int grid_size, int stride, int r, int g, int b, int a, int random_seed) :
Renderer(renderer), _grid_stride(stride), _r(r), _g(g), _b(b), _a(a), _dx(0), _dy(0), _grid_size(grid_size)
{
  srand(random_seed);
  initialiseLocation();
}

void Snake::draw() {
  move();
  for (int i = 0; i < locationHistory.size(); ++i) {
    renderRect(locationHistory.at(i), _grid_stride, _r, _g, _b, _a);
  }
  acceptingMove = true;
}

void Snake::initialiseLocation() {
  _x = ((rand() % (_grid_size - 2)) + 1) * _grid_stride;
  _y = ((rand() % (_grid_size - 2)) + 1) * _grid_stride;
  int x_offset = abs(_x - (_grid_size * _grid_stride) /2);
  int y_offset = abs(_y - (_grid_size * _grid_stride) /2);
  setDirection(x_offset, y_offset);
}

void Snake::setDirection(int x_offset, int y_offset) {
  if (x_offset > y_offset) {
    if (_x - (_grid_size * _grid_stride) /2 > 0) {
      currentDir = LEFT;
    } else {
      currentDir = RIGHT;
    }
  } else {
    if (_y - (_grid_size * _grid_stride) /2 > 0) {
      currentDir = UP;
    } else {
      currentDir = DOWN;
    }
  }
  attemptedDir = currentDir;
}

void Snake::updateLocationHistory() {
  locationHistory.push_back(std::vector<int> { _x, _y });
  if (locationHistory.size() > _currentLength) {
    locationHistory.pop_front();
  }
}

void Snake::updateDirection() {
  if (attemptedDir == LEFT && currentDir != RIGHT) {
    _dx = -_grid_stride;
    _dy = 0;
    currentDir = LEFT;
  } else if (attemptedDir == RIGHT && currentDir != LEFT) {
    _dx = _grid_stride;
    _dy = 0;
    currentDir = RIGHT;
  } else if (attemptedDir == UP && currentDir != DOWN) {
    _dx = 0;
    _dy = -_grid_stride;
    currentDir = UP;
  } else if (attemptedDir == DOWN && currentDir != UP) {
    _dx = 0;
    _dy = _grid_stride;
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
        alive = false;
        return locationHistory[i];
      }
    }
  }
  return locationHistory[0];
}

void Snake::checkHitWall(int grid_height) {
  std::vector<int> headSquare = locationHistory[locationHistory.size() -1];
  if (headSquare.at(0) >= (grid_height - 1) * _grid_stride || headSquare.at(0) <= 0) {
    alive = false;
  } else if (headSquare.at(1) >= (grid_height - 1) * _grid_stride || headSquare.at(1) <= 0) {
    alive = false;
  }
}

void Snake::checkDeath(int grid_height) {
  checkSelfEat();
  checkHitWall(grid_height);

}
bool Snake::isDead() {
  return !alive;
}

void Snake::showDeath() {
  for (int i = 0; i < locationHistory.size() - 1; ++i) {
    renderRect(locationHistory.at(i), _grid_stride, _r, _g, _b, _a);
  }
  std::vector<int> deathSquare = locationHistory[locationHistory.size() -1];
  renderRect(deathSquare, _grid_stride, 255, 0, 0, 255);
}

void Snake::reset() {
  initialiseLocation();
  _currentLength = 4;
  alive = true;
  while (locationHistory.size() > 0) {
    locationHistory.pop_front();
  }
  locationHistory.push_back(std::vector<int> { _x, _y });
}
