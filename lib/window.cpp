#include <iostream>
#include "window.h"

Window::Window(const std::string &title, int width, int height, int stride) :
_title(title), _width(width), _height(height), _stride(stride)
{
  _closed = !init();
}

Window::~Window() {
  SDL_DestroyRenderer(_renderer);
  SDL_DestroyWindow(_window);
  SDL_Quit();
}

bool Window::init() {
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

void Window::pollEvents(SDL_Event &event) {
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

void Window::draw() const {
  SDL_RenderPresent(_renderer);
  SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
  SDL_RenderClear(_renderer);
}

void Window::renderRect(SDL_Rect rect, int r, int g, int b, int a) {
  SDL_SetRenderDrawColor(_renderer, r, g, b, a);
  SDL_RenderFillRect(_renderer, &rect);
}
