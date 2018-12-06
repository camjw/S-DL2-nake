#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

class Display {
  int SCREEN_WIDTH, SCREEN_HEIGHT;
  SDL_Window* window;
  SDL_Surface* screenSurface;

  public:
    Display(int, int);
}

Display::Display (int width, int height) {
  SCREEN_WIDTH = width;
  SCREEN_HEIGHT = height;
}

SDL_Surface* Display::loadImage(const char* filename) {

  SDL_Surface* loadedImage = IMG_Load(filename);
  return loadedImage;
}
