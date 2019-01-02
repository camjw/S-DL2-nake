#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <SDL2/SDL.h>
#include "renderer.h"

class Background : public Renderer {
  public:
    Background(const Renderer &renderer, int width, int height, int stride);
    virtual void draw();
    virtual ~Background() {};

  private:
    void drawBorder();
    void drawBackground();
    int _width, _height, _stride;
};

#endif
