#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "lib/game.h"

const int GRID_WIDTH = 40;
const int GRID_HEIGHT = 30;
const int GRID_STRIDE = 20;
const int SCREEN_FPS = 24;

int main( int argc, char* args[] ) {
  Game game(GRID_WIDTH, GRID_HEIGHT, GRID_STRIDE, SCREEN_FPS);
  game.run();
}
