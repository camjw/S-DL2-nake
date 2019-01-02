#include <iostream>
#include "renderer.h"

Renderer::Renderer(const std::string &title, int width, int height, int stride) :
_title(title), _width(width), _height(height), _stride(stride)
{
  _closed = !init();
}

Renderer::~Renderer() {
  SDL_DestroyRenderer(_renderer);
  SDL_DestroyWindow(_window);
  SDL_Quit();
}

bool Renderer::init() {
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    std::cerr << "SDL failed to init" << std::endl;
    return 0;
  }

  _window = SDL_CreateWindow(
    _title.c_str(),
    SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED,
    _width * _stride,
    _height * _stride,
    0
  );

  if(_window == nullptr) {
    std::cerr << "SDL failed to create window" << std::endl;
    return 0;
  }

  _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  if (_renderer == nullptr) {
    std::cerr << "SDL failed to create renderer" << std::endl;
    return 0;
  }
  return true;
}

void Renderer::pollEvents(SDL_Event &event) {
  switch (event.type) {
    case SDL_QUIT:
      _closed = true;
      break;

    case SDL_KEYDOWN:
      switch (event.key.keysym.sym) {
        case SDLK_ESCAPE:
          _closed = true;
          break;
      }

    default:
      break;
  }
}

void Renderer::drawBackground() {
  SDL_RenderPresent(_renderer);
  SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
  SDL_RenderClear(_renderer);
}

void Renderer::drawBorder() {
  SDL_Rect border_1 { _stride, _stride, (_height - 2) * _stride, (_height - 2)* _stride };
  SDL_Rect border_2 { _stride - 1, _stride - 1, (_height - 2)* _stride + 2, (_height - 2)* _stride + 2 };
  SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
  SDL_RenderDrawRect(_renderer, &border_1);
  SDL_RenderDrawRect(_renderer, &border_2);
}

void Renderer::draw() {
  drawBackground();
  drawBorder();
}

void Renderer::renderRect(std::vector<int> rectCoords, int stride, int r, int g, int b, int a) {
  SDL_Rect rect { rectCoords.at(0) + 1, rectCoords.at(1) + 1, stride -2, stride - 2 };
  SDL_SetRenderDrawColor(_renderer, r, g, b, a);
  SDL_RenderFillRect(_renderer, &rect);
}
