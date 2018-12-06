#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include "display.h"

Display::Display (int width, int height) {
  SCREEN_WIDTH = width;
  SCREEN_HEIGHT = height;
  quit = false;
}

SDL_Surface* Display::loadImage(const char* filename) {
  SDL_Surface* loadedImage = IMG_Load(filename);
  return loadedImage;
}

void Display::close() {
  SDL_DestroyWindow(window);
  window = NULL;
  SDL_Quit();
}

bool Display::init() {
  bool success = true;
  if(SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    success = false;
  } else {
    window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    if(window == NULL) {
      printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
      success = false;
    }
  }
  return success;
}

void Display::hasUserQuit() {
  while(SDL_PollEvent(&e) != 0 ) {
    if(e.type == SDL_QUIT) {
      quit = true;
    }
  }
}

void Display::run() {
  init();
  while(!quit) {
    hasUserQuit();
    screenSurface = SDL_GetWindowSurface(window);
    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFA, 0x11, 0x02));
    SDL_UpdateWindowSurface(window);
  }
  close();
}
