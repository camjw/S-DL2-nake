#include "food.h"
#include <algorithm>
#include <iostream>

Food::Food(const Window &window, int grid_w, int grid_h, int grid_stride, int r, int g, int b, int a, int random_seed) :
Window(window), _grid_w(grid_w), _grid_h(grid_h), _grid_stride(grid_stride), _r(r), _g(g), _b(b), _a(a)
{
  srand(random_seed);
  location.push_back((rand() % _grid_w) * _grid_stride);
  location.push_back((rand() % _grid_h) * _grid_stride);
};

void Food::draw() {
  renderRect(location, _grid_stride, _r, _g, _b, _a);
};

std::vector<int> Food::getLocation() {
  return location;
};

void Food::resetLocation(std::deque<std::vector<int>> snakeLocationHistory) {
  location[0] = (rand() % _grid_w) * _grid_stride;
  location[1] = (rand() % _grid_h) * _grid_stride;

  if (std::find(snakeLocationHistory.begin(), snakeLocationHistory.end(), location) != snakeLocationHistory.end()) {
    resetLocation(snakeLocationHistory);
  }
}

Food::~Food() {};
