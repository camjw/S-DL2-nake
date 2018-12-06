#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "lib/display.h"

int main( int argc, char* args[] ) {
  Display game_display(480, 640);
  game_display.run();
  return 0;
}
