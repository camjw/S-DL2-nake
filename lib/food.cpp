#include "food.h"
#include <iostream>

Food::Food(const Window &window, int grid_w, int grid_h, int grid_stride, int r, int g, int b, int a, int random_seed) :
Window(window), _grid_w(grid_w), _grid_h(grid_h), _grid_stride(grid_stride), _r(r), _g(g), _b(b), _a(a)
{
  srand(random_seed);
  location.push_back(rand() % _grid_w);
  location.push_back(rand() % _grid_h);
};

void Food::draw() {
  SDL_Rect rect;

  rect.w = 18;
  rect.h = 18;
  rect.x = location[0] * _grid_stride + 1;
  rect.y = location[1] * _grid_stride + 1;

  SDL_SetRenderDrawColor(_renderer, _r, _g, _b, _a);
  SDL_RenderFillRect(_renderer, &rect);
};

std::vector<int> Food::getLocation() {
  return location;
};
