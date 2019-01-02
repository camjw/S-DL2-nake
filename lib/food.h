#ifndef FOOD_H
#define FOOD_H
#include <vector>
#include <deque>
#include <cstdlib>
#include "renderer.h"

class Food : public Renderer {
  public:
    Food(const Renderer &renderer, int grid_w, int grid_h, int grid_stride, int r, int g, int b, int a, int random_seed);
    virtual void draw();
    virtual std::vector<int> getLocation();
    virtual void resetLocation(std::deque<std::vector<int>> snakeLocationHistory);
    virtual void reset();
    virtual ~Food();

  private:
    std::vector<int> location;
    int _x, _y;
    int _grid_w, _grid_h, _grid_stride;
    int _r, _g, _b, _a;
};

#endif
