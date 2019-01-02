#include "background.h"

Background::Background(const Renderer &renderer, int width, int height, int stride) :
Renderer(renderer), _width(width), _height(height), _stride(stride) {
}

void Background::drawBackground() {
  SDL_RenderPresent(_renderer);
  SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
  SDL_RenderClear(_renderer);
}

void Background::drawBorder() {
  SDL_Rect border_1 { _stride, _stride, (_height - 2) * _stride, (_height - 2)* _stride };
  SDL_Rect border_2 { _stride - 1, _stride - 1, (_height - 2)* _stride + 2, (_height - 2)* _stride + 2 };
  SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
  SDL_RenderDrawRect(_renderer, &border_1);
  SDL_RenderDrawRect(_renderer, &border_2);
}

void Background::draw() {
  drawBackground();
  drawBorder();
}
