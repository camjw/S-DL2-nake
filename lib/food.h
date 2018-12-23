#ifndef FOOD_H
#define FOOD_H
#include <vector>
#include <cstdlib>
#include "window.h"

class Food : public Window {
  public:
    Food(const Window &window, int grid_w, int grid_h, int grid_stride, int r, int g, int b, int a, int random_seed);
    virtual void draw();
    std::vector<int> getLocation();
    void resetLocation();

  private:
    std::vector<int> location;
    int _x, _y;
    int _grid_w, _grid_h, _grid_stride;
    int _r, _g, _b, _a;
};

#endif
